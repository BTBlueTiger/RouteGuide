package dev.dubsky.routeguide.rest;

import dev.dubsky.routeguide.rest.service.impl.CustomUserDetailsService;
import dev.dubsky.routeguide.rest.service.impl.UserServiceImpl;
import org.springframework.boot.test.context.TestConfiguration;
import org.springframework.context.annotation.Bean;

@TestConfiguration
public class TestConfig {

    @Bean
    public CustomUserDetailsService customUserDetailsService() {
        return new CustomUserDetailsService();
    }

    @Bean
    public UserServiceImpl userServiceImpl() {
        return new UserServiceImpl();
    }
}