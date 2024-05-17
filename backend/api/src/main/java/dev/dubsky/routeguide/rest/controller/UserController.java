package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/users")
public class UserController {

    @Autowired
    private UserService userService;

    @GetMapping("/{id}")
    @PreAuthorize("hasRole('USER')")
    public User getUserById(@PathVariable Long id) {
        return userService.findById(id);
    }

    @GetMapping
    @PreAuthorize("hasRole('USER')")
    public List<User> getAllUsers() {
        return userService.findAll();
    }

    @PostMapping
    @PreAuthorize("hasRole('USER')")
    public User createUser(@RequestBody User user) {
        return userService.save(user);
    }

    @PutMapping("/{id}")
    @PreAuthorize("hasRole('USER')")
    public User updateUser(@PathVariable Long id, @RequestBody User user) {
        user.setId(id);
        return userService.save(user);
    }

    @DeleteMapping("/{id}")
    @PreAuthorize("hasRole('USER')")
    public void deleteUser(@PathVariable Long id) {
        userService.deleteById(id);
    }
}
