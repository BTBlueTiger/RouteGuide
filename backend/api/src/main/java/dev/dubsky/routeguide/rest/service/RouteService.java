package dev.dubsky.routeguide.rest.service;

import dev.dubsky.routeguide.rest.model.Group;
import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.model.RoutesCompany;

import java.util.List;

public interface RouteService {

    public Route createRoute(String username, Route route);
    public List<Route> getRoutesByUser(String authorizationToken);
    public List<Route> getPublicRoutes(Long group);
    public List<Route> getPublicRoutes();
    public RoutesCompany createCompanyRoute(String token, RoutesCompany route);
    public Route getRouteByName(String name);
    public RoutesCompany getCompanyRouteByName(String name);

}
