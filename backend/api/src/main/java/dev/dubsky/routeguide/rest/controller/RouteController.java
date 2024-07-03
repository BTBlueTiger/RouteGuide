package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.service.impl.RouteServiceImpl;
import dev.dubsky.routeguide.rest.service.impl.UserServiceImpl;
import dev.dubsky.routeguide.rest.utility.CLog;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/route")
public class RouteController {

    @Autowired
    private RouteServiceImpl routeService;

    @Autowired
    private UserServiceImpl userService;

    @PostMapping("/create")
    @PreAuthorize("hasRole('USER')")
    public Route createRoute(@RequestHeader("Authorization") String authorizationToken, @RequestBody Route route) {
        CLog.out(0, "Creating route for token: " + authorizationToken);
        CLog.out(0, "Route: " + "User: " + userService.getCurrentUser(authorizationToken).getUsername());
        return routeService.createRoute(authorizationToken, route);
    }

    @GetMapping("/get")
    @PreAuthorize("hasRole('USER')")
    public List<Route> getRoutes(@RequestHeader("Authorization") String authorizationToken) {
        CLog.out(0, "Getting routes for token: " + authorizationToken);
        CLog.out(0, "User: " + userService.getCurrentUser(authorizationToken).getUsername());
        return routeService.getRoutesByUser(authorizationToken);
    }
}
