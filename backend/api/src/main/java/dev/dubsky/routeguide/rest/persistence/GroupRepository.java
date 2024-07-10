package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.model.Group;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface GroupRepository extends JpaRepository<Group, Long> {

}