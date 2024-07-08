package dev.dubsky.routeguide.rest;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import dev.dubsky.advancedlog.AdvLogger;

@SpringBootApplication
public class RestEntry {

    public static void main(String[] args) {
        SpringApplication.run(RestEntry.class, args);
        AdvLogger.config.enable = true;
    }

}
