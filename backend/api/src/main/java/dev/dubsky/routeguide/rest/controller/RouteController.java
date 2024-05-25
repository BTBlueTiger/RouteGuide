package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.routeguide.rest.dto.UserDTO;
import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.service.RouteService;
import dev.dubsky.routeguide.rest.service.impl.RouteServiceImpl;
import dev.dubsky.routeguide.rest.service.impl.UserServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
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
        System.out.println("Creating route for user: " + authorizationToken);
        System.out.println("User: " + userService.getCurrentUser(authorizationToken).getUsername());
        return routeService.createRoute(authorizationToken, route);
    }

    @GetMapping("/get")
    @PreAuthorize("hasRole('USER')")
    public List<Route> getRoutes(@RequestHeader("Authorization") String authorizationToken) {
        return routeService.getRoutesByUser(authorizationToken);
    }
}
