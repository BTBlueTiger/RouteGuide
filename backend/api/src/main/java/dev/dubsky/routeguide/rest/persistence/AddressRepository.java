package dev.dubsky.routeguide.rest.persistence;

import dev.dubsky.routeguide.rest.model.Address;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.query.Param;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public interface AddressRepository extends JpaRepository<Address, Long> {

    Address findByTownAndStreetAndNumber(String town, String street, String number);

    @Query("SELECT a FROM Address a WHERE CONCAT(a.street, ', ', a.number, ', ', a.town) = :fullAddress")
    List<Address> findFirstByFullAddress(@Param("fullAddress") String fullAddress);

    @Query("SELECT a FROM Address a WHERE CONCAT(a.street, ', ', a.number, ', ', a.town) = :fullAddress")
    Address findFirstByOrderByFullAddress(@Param("fullAddress") String fullAddress);
}
