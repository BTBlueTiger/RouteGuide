package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.model.Company;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface CompanyRepository extends JpaRepository<Company, Long> {

    Optional<Company> findByMailEnding(String mailEnding);
    Optional<Company> findByName(String name);

}
