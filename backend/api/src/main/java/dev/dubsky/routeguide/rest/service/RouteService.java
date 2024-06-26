package dev.dubsky.routeguide.rest.service;

import dev.dubsky.routeguide.rest.model.Route;

import java.util.List;

public interface RouteService {

    public Route createRoute(String username, Route route);
    public List<Route> getRoutesByUser(String authorizationToken);

}
