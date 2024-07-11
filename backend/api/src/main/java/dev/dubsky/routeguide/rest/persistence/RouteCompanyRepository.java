package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.RouteCompany;
import dev.dubsky.routeguide.rest.model.User;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface RouteCompanyRepository extends JpaRepository<RouteCompany, Long> {
    RouteCompany getRouteByName(String name);
    List<RouteCompany> getCompanyRouteByCompanyAndUser(User user, Company company);
    List<RouteCompany> getCompanyRouteByCompanyAndPublic(Company company);
}
