package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.model.RoutesCompany;
import org.springframework.data.jpa.repository.JpaRepository;

public interface RouteCompanyRepository extends JpaRepository<RoutesCompany, Long> {
    RoutesCompany getRouteByName(String name);
}
