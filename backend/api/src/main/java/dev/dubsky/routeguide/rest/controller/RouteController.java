package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.model.Group;
import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.service.RouteService;
import dev.dubsky.routeguide.rest.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/route")
public class RouteController {

    @Autowired
    private RouteService routeService;

    @Autowired
    private UserService userService;

    @PostMapping("/create")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> createRoute(@RequestHeader("Authorization") String authorizationToken, @RequestBody Route route) {
        AdvLogger.output(Color.GREEN, "Creating route for token: " + authorizationToken);
        AdvLogger.output(Color.GREEN, "Route: " + "User: " + userService.getCurrentUser(authorizationToken).getUsername());
        Route newRoute = routeService.createRoute(authorizationToken, route);
        if (newRoute == null) {
            return ResponseEntity.badRequest().body("Route creation failed");
        }
        return ResponseEntity.ok(newRoute);
    }

    @GetMapping("/get")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getRoutes(@RequestHeader("Authorization") String authorizationToken) {
        AdvLogger.output(Color.GREEN, authorizationToken);
        AdvLogger.output(Color.GREEN, "Getting routes for token: " + authorizationToken);
        AdvLogger.output(Color.GREEN, "User: " + userService.getCurrentUser(authorizationToken).getUsername());
        List<Route> routes = routeService.getRoutesByUser(authorizationToken);
        if (routes.isEmpty()) {
            return ResponseEntity.badRequest().body("No routes found");
        }
        return ResponseEntity.ok(routeService.getRoutesByUser(authorizationToken));
    }

    @GetMapping("/get_routes/{group_id}")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getPublicRoutes(@RequestHeader("Authorization") String authorizationToken, @PathVariable Long group_id) {
        AdvLogger.output(Color.GREEN, "[ROUTES] getPublicRoutes for token: " + authorizationToken);
        AdvLogger.output(Color.GREEN, "[ROUTES] Target group: " + group_id);
        List<Route> routes = routeService.getPublicRoutes(group_id);
        if (routes.isEmpty()) {
            return ResponseEntity.badRequest().body("No routes found for group: " + group_id);
        }
        return ResponseEntity.ok(routeService.getPublicRoutes(group_id));
    }

    @GetMapping("/get_routes")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getPublicRoutes(@RequestHeader("Authorization") String authorizationToken) {
        AdvLogger.output(Color.GREEN, "[ROUTES] getPublicRoutes for token: " + authorizationToken);
        AdvLogger.output(Color.GREEN, "[ROUTES] Target group: all");
        List<Route> routes = routeService.getPublicRoutes();
        if (routes.isEmpty()) {
            return ResponseEntity.badRequest().body("No routes found");
        }
        return ResponseEntity.ok(routeService.getPublicRoutes());
    }

    @GetMapping("/get_routes_auto")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getPublicRoutesAuto(@RequestHeader("Authorization") String authorizationToken) {
        AdvLogger.output(Color.GREEN, "[ROUTES] getPublicRoutes for token: " + authorizationToken);
        User user = userService.getCurrentUser(authorizationToken);
        Group group = user.getGroup();
        AdvLogger.output(Color.GREEN, "[ROUTES] Target group: " + group.getName());
        List<Route> routes = routeService.getPublicRoutes(Long.valueOf(group.getId()));
        if (routes.isEmpty()) {
            return ResponseEntity.badRequest().body("No routes found for group: " + group.getName());
        }
        return ResponseEntity.ok(routeService.getPublicRoutes(Long.valueOf(group.getId())));
    }
}