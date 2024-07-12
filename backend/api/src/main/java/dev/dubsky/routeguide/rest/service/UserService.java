package dev.dubsky.routeguide.rest.service;

import dev.dubsky.routeguide.rest.model.Group;
import dev.dubsky.routeguide.rest.model.User;

import java.util.List;

public interface UserService {
    User getCurrentUser(String token);
    User findById(Long id);
    User findByUsername(String username);
    List<User> findAll();
    User create(User user);
    User save(User user);
    User saveMail(User user);
    void deleteById(Long id);
    List<User> findByCompany(Long companyId);
    Group getGroupByGroupID(Long group_id);
}
