package dev.dubsky.routeguide.rest.model;

import com.fasterxml.jackson.annotation.JsonBackReference;
import com.fasterxml.jackson.databind.annotation.JsonNaming;
import jakarta.persistence.*;
import jakarta.validation.constraints.NotNull;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Entity
@Table(name = "addresses_company")
@NamedQueries({
        @NamedQuery(name = "AdressesCompany.getAdressById", query = "SELECT a FROM AddressCompany a WHERE a.id = :id"),
        @NamedQuery(name = "AdressesCompany.getAdressesByRoute", query = "SELECT a FROM AddressCompany a WHERE a.route.id = :id")
})
public class AddressCompany {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "adresses_company_id_gen")
    @SequenceGenerator(name = "adresses_company_id_gen", sequenceName = "adresses_company_id_seq", allocationSize = 1)
    @Column(name = "id", nullable = false)
    private Integer id;

    @NotNull
    @Column(name = "identifier", nullable = false, length = Integer.MAX_VALUE)
    private String identifier;

    @NotNull
    @Column(name = "longitude", nullable = false)
    private Double longitude;

    @NotNull
    @Column(name = "latitude", nullable = false)
    private Double latitude;

    @JsonBackReference
    @NotNull
    @ManyToOne(fetch = FetchType.EAGER, optional = false)
    @JoinColumn(name = "route_id", nullable = false)
    private RoutesCompany route;

}