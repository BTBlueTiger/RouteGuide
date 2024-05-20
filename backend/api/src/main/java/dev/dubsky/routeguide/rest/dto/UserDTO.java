package dev.dubsky.routeguide.rest.dto;

import dev.dubsky.routeguide.rest.model.User;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor
public class UserDTO {
    private String username;
    private String email;


    public UserDTO(User user) {
        this.username = user.getUsername();
        this.email = user.getEmail();
    }
}
