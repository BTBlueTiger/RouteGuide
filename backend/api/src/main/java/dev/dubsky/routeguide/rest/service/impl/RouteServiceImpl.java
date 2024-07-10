package dev.dubsky.routeguide.rest.service.impl;

import com.google.maps.GeoApiContext;
import com.google.maps.GeocodingApi;
import com.google.maps.model.GeocodingResult;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.config.EnvReader;
import dev.dubsky.routeguide.rest.model.Address;
import dev.dubsky.routeguide.rest.model.Group;
import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.persistence.AddressRepository;
import dev.dubsky.routeguide.rest.persistence.GroupRepository;
import dev.dubsky.routeguide.rest.persistence.RouteRepository;
import dev.dubsky.routeguide.rest.service.RouteService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class RouteServiceImpl implements RouteService {

    @Autowired
    private RouteRepository routeRepository;

    @Autowired
    private AddressRepository addressRepository;

    @Autowired
    private UserServiceImpl userService;

    @Autowired
    private EnvReader envReader;

    private GeoApiContext getGeoApiContext() {
        return new GeoApiContext.Builder().apiKey(envReader.getGoogleApiKey()).build();
    }

    @Override
    public Route createRoute(String authorizationToken, Route route) {
        User user = userService.getCurrentUser(authorizationToken);
        route.setUser(user);
        route.setGroup(user.getGroup());

        GeoApiContext context = getGeoApiContext();

        for (Address address : route.getAddresses()) {
            try {
                String fullAddress = address.getStreet() + ", " + address.getNumber() + ", " + address.getTown();

                List<Address> cachedAddresses = addressRepository.findFirstByFullAddress(fullAddress);
                Address cachedAddress = !cachedAddresses.isEmpty() ? cachedAddresses.get(0) : null;
                if (cachedAddress != null) {
                    AdvLogger.output(Color.GREEN, "Using cached address for: " + fullAddress);
                    address.setLatitude(cachedAddress.getLatitude());
                    address.setLongitude(cachedAddress.getLongitude());
                } else {
                    AdvLogger.output(Color.YELLOW, "Geocoding address for: " + fullAddress);
                    GeocodingResult[] results = GeocodingApi.geocode(context, fullAddress).await();
                    if (results.length > 0) {
                        address.setLatitude(results[0].geometry.location.lat);
                        address.setLongitude(results[0].geometry.location.lng);
                    }

                }
                address.setRoute(route);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        return routeRepository.save(route);
    }

    public List<Route> getRoutesByUser(String authorizationToken) {
        User user = userService.getCurrentUser(authorizationToken);
        return routeRepository.findByUserId(user.getId());
    }

    public List<Route> getPublicRoutes(Long group) {
        List<Route> routes = routeRepository.getPublicRoutesByGroup(group);
        AdvLogger.output(Color.GREEN, "Found " + routes.size() + " public routes for group: " + group);
        return routes;
    }

    public List<Route> getPublicRoutes() {
        List<Route> routes = routeRepository.getPublicRoutes();
        AdvLogger.output(Color.GREEN, "Found " + routes.size() + " public routes");
        return routes;
    }
}
