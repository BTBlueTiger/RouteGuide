package dev.dubsky.routeguide.rest.service;

import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.model.RouteCompany;
import dev.dubsky.routeguide.rest.model.User;

import java.util.List;

public interface RouteService {

    public Route createRoute(String username, Route route);
    public List<Route> getRoutesByUser(String authorizationToken);
    public List<Route> getPublicRoutes(Long group);
    public List<Route> getPublicRoutes();
    public RouteCompany createCompanyRoute(String token, RouteCompany route);
    public Route getRouteByName(String name);
    public RouteCompany getCompanyRouteByName(String name);
    public List<RouteCompany> getCompanyRoutes(User user);
    public List<RouteCompany> getCompanyRoutesPublic(User user);

}
