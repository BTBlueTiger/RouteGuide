package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.model.Address;
import dev.dubsky.routeguide.rest.model.AddressCompany;
import org.springframework.data.jpa.repository.JpaRepository;

public interface AddressCompanyRepository extends JpaRepository<AddressCompany, Long> {
}
