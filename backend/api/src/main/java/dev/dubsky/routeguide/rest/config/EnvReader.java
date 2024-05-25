package dev.dubsky.routeguide.rest.config;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class EnvReader {

    @Value("${GOOGLE_API_KEY}")
    private String googleApiKey;

    @Bean
    public String googleApiKey() {
        return googleApiKey;
    }
}
