package dev.dubsky.routeguide.rest.model;

import com.fasterxml.jackson.annotation.JsonManagedReference;

import jakarta.persistence.*;
import jakarta.validation.constraints.NotNull;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Entity
@Table(name = "companies")
public class Company {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "companies_id_gen")
    @SequenceGenerator(name = "companies_id_gen", sequenceName = "companies_company_id_seq", allocationSize = 1)
    @Column(name = "company_id", nullable = false)
    private Integer id;

    @NotNull
    @Column(name = "name", nullable = false, length = Integer.MAX_VALUE)
    private String name;

    @Column(name = "mail_ending", length = Integer.MAX_VALUE)
    private String mailEnding;

    @JsonManagedReference
    @NotNull
    @ManyToOne(fetch = FetchType.EAGER, optional = false)
    @JoinColumn(name = "owner_id", nullable = false)
    private User owner;

}