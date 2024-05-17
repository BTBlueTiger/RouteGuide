package dev.dubsky.routeguide.rest.service;

import dev.dubsky.routeguide.rest.model.User;

import java.util.List;

public interface UserService {
    User findById(Long id);
    List<User> findAll();
    User save(User user);
    void deleteById(Long id);
}
