package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.dto.RouteDTO;
import dev.dubsky.routeguide.rest.model.*;
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
        AdvLogger.output(Color.GREEN, "[ROUTES] Creating route for token: " + authorizationToken);
        AdvLogger.output(Color.GREEN, "[ROUTES] Route: " + "User: " + userService.getCurrentUser(authorizationToken).getUsername());
        if (routeService.getRouteByName(route.getName()) != null) {
            return ResponseEntity.badRequest().body("Route with name: " + route.getName() + " already exists");
        }
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
        AdvLogger.output(Color.GREEN, "[ROUTES] Getting routes for token: " + authorizationToken);
        AdvLogger.output(Color.GREEN, "[ROUTES] User: " + userService.getCurrentUser(authorizationToken).getUsername());
        List<Route> routes = routeService.getRoutesByUser(authorizationToken);
        if (routes.isEmpty()) {
            return ResponseEntity.badRequest().body("No routes found");
        }
        return ResponseEntity.ok(routes);
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
        return ResponseEntity.ok(routes);
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
        return ResponseEntity.ok(routes);
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
        return ResponseEntity.ok(routes);
    }

    @PostMapping("create_company_route")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> createCompanyRoute(@RequestHeader("Authorization") String authorizationToken, @RequestBody RouteCompany route) {
        AdvLogger.output(Color.GREEN, "[ROUTES] Creating company route for token: " + authorizationToken);
        if (routeService.getCompanyRouteByName(route.getName()) != null) {
            return ResponseEntity.badRequest().body("Route with name: " + route.getName() + " already exists");
        } else if (route.getAddresses().isEmpty()) {
            return ResponseEntity.badRequest().body("Route must have at least one address");
        }
        RouteCompany newRoute = routeService.createCompanyRoute(authorizationToken, route);
        if (newRoute == null) {
            return ResponseEntity.badRequest().body("Route creation failed");
        }
        return ResponseEntity.ok(new RouteDTO(newRoute));
    }

    @GetMapping("get_routes_company")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getCompanyRoutes(@RequestHeader("Authorization") String authorizationToken) {
        AdvLogger.output(Color.GREEN, "[ROUTES] Getting personal company routes for token: " + authorizationToken);
        User user = userService.getCurrentUser(authorizationToken);
        List<RouteCompany> routes = routeService.getCompanyRoutes(user);
        if (routes.isEmpty()) {
            return ResponseEntity.badRequest().body("No routes found");
        }
        return ResponseEntity.ok(routes.stream().map(RouteDTO::new).toList());
    }

    @GetMapping("get_routes_company_public")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getCompanyRoutesPublic(@RequestHeader("Authorization") String authorizationToken) {
        AdvLogger.output(Color.GREEN, "[ROUTES] Getting public company routes for token: " + authorizationToken);
        User user = userService.getCurrentUser(authorizationToken);
        List<RouteCompany> routes = routeService.getCompanyRoutesPublic(user);
        if (routes.isEmpty()) {
            return ResponseEntity.badRequest().body("No routes found");
        }
        return ResponseEntity.ok(routes.stream().map(RouteDTO::new).toList());
    }
}