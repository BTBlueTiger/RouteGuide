package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.dto.UserDTO;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/users")
public class UserController {

    @Autowired
    private UserService userService;

    @GetMapping("/me")
    @PreAuthorize("hasRole('USER')")
    public UserDTO getCurrentUser(@RequestHeader("Authorization") String token) {
        return new UserDTO(userService.getCurrentUser(token));
    }

    @GetMapping("/me/get_group")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getGroup(@RequestHeader("Authorization") String token) {
        AdvLogger.output(Color.GREEN, "Getting group for user: " + userService.getCurrentUser(token).getUsername());
        if (userService.getCurrentUser(token).getGroup() == null) {
            return ResponseEntity.badRequest().body("No group found");
        }
        return ResponseEntity.ok(userService.getCurrentUser(token).getGroup());
    }

    @PutMapping("/me/setEmail")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> setEmail(@RequestHeader("Authorization") String token, @RequestBody String email) {
        User user = userService.getCurrentUser(token);
        user.setEmail(email);
        if (userService.saveMail(user) == null) {
            return ResponseEntity.badRequest().body("Email update failed");
        }
        return ResponseEntity.ok(userService.saveMail(user));
    }

    @PutMapping("/me/setPassword")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> setPassword(@RequestHeader("Authorization") String token, @RequestBody String password) {
        User user = userService.getCurrentUser(token);
        user.setPassword(password);
        return ResponseEntity.ok(userService.save(user));
    }

    @GetMapping("/{id}")
    @PreAuthorize("hasRole('ADMIN')")
    public UserDTO getUserById(@PathVariable Long id) {
        return new UserDTO(userService.findById(id));
    }

    @GetMapping
    @PreAuthorize("hasRole('ADMIN')")
    public List<UserDTO> getAllUsers() {
        return userService.findAll().stream().map(UserDTO::new).collect(Collectors.toList());
    }

    @PostMapping
    @PreAuthorize("hasRole('ADMIN')")
    public UserDTO createUser(@RequestBody User user) {
        return new UserDTO(userService.save(user));
    }

    @PutMapping("/{id}")
    @PreAuthorize("hasRole('ADMIN')")
    public UserDTO updateUser(@PathVariable Long id, @RequestBody User user) {
        user.setId(id);
        return new UserDTO(userService.save(user));
    }

    @DeleteMapping("/{id}")
    @PreAuthorize("hasRole('ADMIN')")
    public void deleteUser(@PathVariable Long id) {
        userService.deleteById(id);
    }
}
