package dev.dubsky.routeguide.rest.model;

import jakarta.persistence.*;
import jakarta.validation.constraints.NotNull;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Entity
@Table(name = "addresses")
public class Address {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "addresses_id_gen")
    @SequenceGenerator(name = "addresses_id_gen", sequenceName = "addresses_id_seq", allocationSize = 1)
    @Column(name = "id", nullable = false)
    private Integer id;

    @NotNull
    @Column(name = "town", nullable = false, length = Integer.MAX_VALUE)
    private String town;

    @NotNull
    @Column(name = "street", nullable = false, length = Integer.MAX_VALUE)
    private String street;

    @NotNull
    @Column(name = "number", nullable = false, length = Integer.MAX_VALUE)
    private String number;

    @NotNull
    @Column(name = "longitude", nullable = false)
    private Double longitude;

    @NotNull
    @Column(name = "latitude", nullable = false)
    private Double latitude;

    @NotNull
    @ManyToOne(fetch = FetchType.LAZY, optional = false)
    @JoinColumn(name = "route_id", nullable = false)
    private Route route;

}