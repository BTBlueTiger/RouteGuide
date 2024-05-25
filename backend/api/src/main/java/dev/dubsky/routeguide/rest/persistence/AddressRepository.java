package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.model.Address;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface AddressRepository extends JpaRepository<Address, Long> {
}
