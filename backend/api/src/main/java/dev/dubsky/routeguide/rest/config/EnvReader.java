package dev.dubsky.routeguide.rest.config;

import lombok.Getter;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.stereotype.Component;

@Getter
@Component
public class EnvReader {

    @Value("${GOOGLE_API_KEY}")
    private String googleApiKey;

}