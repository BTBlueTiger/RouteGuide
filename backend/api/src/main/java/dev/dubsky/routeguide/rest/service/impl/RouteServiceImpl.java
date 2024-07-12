package dev.dubsky.routeguide.rest.service.impl;

import com.google.maps.GeoApiContext;
import com.google.maps.GeocodingApi;
import com.google.maps.model.GeocodingResult;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.config.EnvReader;
import dev.dubsky.routeguide.rest.model.*;
import dev.dubsky.routeguide.rest.persistence.*;
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
    private RouteCompanyRepository routesCompanyRepository;

    @Autowired
    private AddressCompanyRepository adressesCompanyRepository;

    @Autowired
    private UserServiceImpl userService;

    @Autowired
    private EnvReader envReader;

    @Override
    public Route createRoute(String authorizationToken, Route route) {
        User user = userService.getCurrentUser(authorizationToken);
        route.setUser(user);
        route.setGroup(user.getGroup());

        for (Address address : route.getAddresses()) {
            address.setRoute(route);
        }

        return routeRepository.save(route);
    }

    public RouteCompany createCompanyRoute(String authorizationToken, RouteCompany route) {
        User user = userService.getCurrentUser(authorizationToken);
        route.setUser(user);
        route.setCompany(user.getCompany());

        for (AddressCompany address : route.getAddresses()) {
            address.setRoute(route);
        }

        return routesCompanyRepository.save(route);
    }
    public List<Route> getRoutesByUser(String authorizationToken) {
        User user = userService.getCurrentUser(authorizationToken);
        List<Route> routes = routeRepository.findByUserId(user.getId());
        AdvLogger.output(Color.GREEN, "[ROUTES] Found " + routes.size() + " routes for user: " + user.getUsername());
        return routes;
    }

    public List<Route> getPublicRoutes(Long group) {
        List<Route> routes = routeRepository.getPublicRoutesByGroup(group);
        AdvLogger.output(Color.GREEN, "[ROUTES] Found " + routes.size() + " public routes for group: " + group);
        return routes;
    }

    public List<Route> getPublicRoutes() {
        List<Route> routes = routeRepository.getPublicRoutes();
        AdvLogger.output(Color.GREEN, "[ROUTES] Found " + routes.size() + " public routes");
        return routes;
    }

    public Route getRouteByName(String name) {
        return routeRepository.getRouteByName(name);
    }

    public RouteCompany getCompanyRouteByName(String name) {
        return routesCompanyRepository.getRouteByName(name);
    }

    public List<RouteCompany> getCompanyRoutes(User user) {
        return routesCompanyRepository.getCompanyRouteByCompanyAndUser(user, user.getCompany());
    }

    public List<RouteCompany> getCompanyRoutesPublic(User user) {
        return routesCompanyRepository.getCompanyRouteByCompanyAndPublic(user.getCompany());
    }
}
