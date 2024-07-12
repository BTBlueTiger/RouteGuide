package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.jwt.JwtTokenUtil;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.service.UserService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.AuthenticationManager;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.web.bind.annotation.*;

import java.util.Map;

@RestController
@RequestMapping("/auth")
public class AuthController {

    @Autowired
    private AuthenticationManager authenticationManager;

    @Autowired
    private UserDetailsService userDetailsService;

    @Autowired
    private JwtTokenUtil jwtTokenUtil;

    @Autowired
    private UserService userService;

    /**
     * Register a new user
     * @param user User object
     * @return ResponseEntity with status code and message
     */
    @PostMapping("/register")
    public ResponseEntity<?> registerUser(@RequestBody User user) {
        if (userService.create(user) == null) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("User already exists");
        }
        return ResponseEntity.status(HttpStatus.CREATED).body("User created");
    }

    /**
     * Login a user
     * @param user Map with username and password
     * @return ResponseEntity with status code and token
     */
    @PostMapping("/login")
    public ResponseEntity<?> login(@RequestBody Map<String, String> user) {
        AdvLogger.output(Color.GREEN, "Login method called with username: " + user.get("username"));
        authenticationManager.authenticate(
                new UsernamePasswordAuthenticationToken(user.get("username"), user.get("password"))
        );
        final UserDetails userDetails = userDetailsService.loadUserByUsername(user.get("username"));
        String token = jwtTokenUtil.generateToken(userDetails);
        AdvLogger.output(Color.GREEN, "Generated Token: " + token + " for user: " + user.get("username"));
        return ResponseEntity.ok(token);
    }

}