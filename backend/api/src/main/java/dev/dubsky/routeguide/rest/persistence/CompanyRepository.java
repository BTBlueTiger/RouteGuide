package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.dto.UserDTO;
import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.User;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.stereotype.Repository;

import java.util.List;
import java.util.Optional;

@Repository
public interface CompanyRepository extends JpaRepository<Company, Long> {

    Optional<Company> findByMailEnding(String mailEnding);

    @Query("SELECT c FROM Company c")
    List<Company> getAllCompanies();

    @Query("SELECT c FROM Company c")
    Company getCompany();

    @Query("SELECT c FROM Company c WHERE c.id = :id")
    Company getCompanyById(Long id);

    @Query("SELECT c FROM Company c WHERE c.mailEnding = :mailEnding")
    Company getCompanyByMailEnding(String mailEnding);

    @Query("SELECT c FROM Company c WHERE c.name = :name")
    Company getCompanyByName(String name);

}
