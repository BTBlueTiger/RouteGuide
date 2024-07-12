package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.dto.UserDTO;
import dev.dubsky.routeguide.rest.model.Group;
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

    /**
     * Get current user
     * @param token Authorization token
     * @return UserDTO object
     */
    @GetMapping("/me")
    @PreAuthorize("hasRole('USER')")
    public UserDTO getCurrentUser(@RequestHeader("Authorization") String token) {
        return new UserDTO(userService.getCurrentUser(token));
    }

    /**
     * Get group for the current user
     * @param token Authorization token
     * @return ResponseEntity with group object
     */
    @GetMapping("/me/get_group")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getGroup(@RequestHeader("Authorization") String token) {
        AdvLogger.output(Color.GREEN, "Getting group for user: " + userService.getCurrentUser(token).getUsername());
        if (userService.getCurrentUser(token).getGroup() == null) {
            return ResponseEntity.badRequest().body("No group found");
        }
        return ResponseEntity.ok(userService.getCurrentUser(token).getGroup());
    }

    /**
     * Set email for the current user
     * @param token Authorization token
     * @param email Email string
     * @return ResponseEntity with user object
     */
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

    /**
     * Set password for the current user
     * @param token Authorization token
     * @param password Password string
     * @return ResponseEntity with user object
     */
    @PutMapping("/me/setPassword")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> setPassword(@RequestHeader("Authorization") String token, @RequestBody String password) {
        User user = userService.getCurrentUser(token);
        user.setPassword(password);
        return ResponseEntity.ok(userService.save(user));
    }

    /**
     * Set group for the current user
     * @param token Authorization token
     * @param group Group id
     * @return ResponseEntity with user object
     */
    @PutMapping("/me/setGroup")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> setGroup(@RequestHeader("Authorization") String token, @RequestBody Long group) {
        User user = userService.getCurrentUser(token);
        Group g = userService.getGroupByGroupID(group);
        if (g == null) {
            return ResponseEntity.badRequest().body("Group not found");
        }
        user.setGroup(g);
        return ResponseEntity.ok(userService.save(user));
    }

    /**
     * Get user by id
     * @param id User id
     * @return UserDTO object
     */
    @GetMapping("/{id}")
    @PreAuthorize("hasRole('ADMIN')")
    public UserDTO getUserById(@PathVariable Long id) {
        return new UserDTO(userService.findById(id));
    }

    /**
     * Get all users
     * @return List of UserDTO objects
     */
    @GetMapping
    @PreAuthorize("hasRole('ADMIN')")
    public List<UserDTO> getAllUsers() {
        return userService.findAll().stream().map(UserDTO::new).collect(Collectors.toList());
    }

    /**
     * Create a new user
     * @param user User object
     * @return UserDTO object
     */
    @PostMapping
    @PreAuthorize("hasRole('ADMIN')")
    public UserDTO createUser(@RequestBody User user) {
        return new UserDTO(userService.save(user));
    }

    /**
     * Update user by id
     * @param id User id
     * @param user User object
     * @return UserDTO object
     */
    @PutMapping("/{id}")
    @PreAuthorize("hasRole('ADMIN')")
    public UserDTO updateUser(@PathVariable Long id, @RequestBody User user) {
        user.setId(id);
        return new UserDTO(userService.save(user));
    }

    /**
     * Delete user by id
     * @param id User id
     */
    @DeleteMapping("/{id}")
    @PreAuthorize("hasRole('ADMIN')")
    public void deleteUser(@PathVariable Long id) {
        userService.deleteById(id);
    }
}
