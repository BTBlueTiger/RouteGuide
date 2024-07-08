package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.service.impl.RouteServiceImpl;
import dev.dubsky.routeguide.rest.service.impl.UserServiceImpl;

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
        AdvLogger.output(Color.GREEN, "Creating route for token: " + authorizationToken);
        AdvLogger.output(Color.GREEN, "Route: " + "User: " + userService.getCurrentUser(authorizationToken).getUsername());
        return routeService.createRoute(authorizationToken, route);
    }

    @GetMapping("/get")
    @PreAuthorize("hasRole('USER')")
    public List<Route> getRoutes(@RequestHeader("Authorization") String authorizationToken) {
        AdvLogger.output(Color.GREEN, authorizationToken);
        AdvLogger.output(Color.GREEN, "Getting routes for token: " + authorizationToken);
        AdvLogger.output(Color.GREEN, "User: " + userService.getCurrentUser(authorizationToken).getUsername());
        return routeService.getRoutesByUser(authorizationToken);
    }
}
