package dev.dubsky.routeguide.rest.dto;

import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.Group;
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
    private Group group;
    private Company company;


    public UserDTO(User user) {
        this.username = user.getUsername();
        this.email = user.getEmail();
        this.group = user.getGroup();
        this.company = user.getCompany();
    }
}
