package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.model.Group;
import dev.dubsky.routeguide.rest.model.Route;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface RouteRepository extends JpaRepository<Route, Long> {

    List<Route> findByUserId(Long userId);

    @Query("SELECT r FROM Route r WHERE r.group.id = :group_id AND r.isPublic = true")
    List<Route> getPublicRoutesByGroup(Long group_id);

}
