package dev.dubsky.routeguide.rest.persistence;

import org.springframework.data.jpa.repository.JpaRepository;

import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.model.UserGroup;

public interface UserGroupRepository extends JpaRepository<UserGroup, Long> {

    UserGroup findByUser(User user);
    
}
