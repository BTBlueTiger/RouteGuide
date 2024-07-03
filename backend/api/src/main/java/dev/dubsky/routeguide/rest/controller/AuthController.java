package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.routeguide.rest.jwt.JwtTokenUtil;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.service.UserService;
import dev.dubsky.routeguide.rest.utility.CLog;

import org.springframework.beans.factory.annotation.Autowired;
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

    @PostMapping("/register")
    public String registerUser(@RequestBody User user) {
        userService.create(user);
        return "User registered successfully";
    }

    @PostMapping("/login")
    public String login(@RequestBody Map<String, String> user) {
        CLog.out(0, "Login method called with username: " + user.get("username"));
        authenticationManager.authenticate(
                new UsernamePasswordAuthenticationToken(user.get("username"), user.get("password"))
        );
        final UserDetails userDetails = userDetailsService.loadUserByUsername(user.get("username"));
        String token = jwtTokenUtil.generateToken(userDetails);
        CLog.out(0, "Generated Token: " + token + " for user: " + user.get("username"));
        return token;
    }

}