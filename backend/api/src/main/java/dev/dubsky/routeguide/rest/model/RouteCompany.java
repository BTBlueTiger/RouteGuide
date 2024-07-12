package dev.dubsky.routeguide.rest.model;

import com.fasterxml.jackson.annotation.JsonManagedReference;
import jakarta.persistence.*;
import jakarta.validation.constraints.NotNull;
import lombok.Getter;
import lombok.Setter;
import org.hibernate.annotations.ColumnDefault;

import java.util.List;

@Getter
@Setter
@Entity
@Table(name = "routes_company")
@NamedQueries({
        @NamedQuery(name = "RouteCompany.getCompanyRoutes", query = "SELECT r FROM RouteCompany r WHERE r.user = :user"),
        @NamedQuery(name = "RouteCompany.getCompanyRoutesPublic", query = "SELECT r FROM RouteCompany r WHERE r.user = :user AND r.isPublic = true"),
        @NamedQuery(name = "RouteCompany.getCompanyRouteByName", query = "SELECT r FROM RouteCompany r WHERE r.name = :name"),
        @NamedQuery(name = "RouteCompany.getCompanyRouteByCompanyAndUser", query = "SELECT r FROM RouteCompany r WHERE r.company = :company AND r.user = :user"),
        @NamedQuery(name = "RouteCompany.getCompanyRouteByCompanyAndPublic", query = "SELECT r FROM RouteCompany r WHERE r.company = :company AND r.isPublic = true"),
})
public class RouteCompany {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "routes_company_id_gen")
    @SequenceGenerator(name = "routes_company_id_gen", sequenceName = "routes_company_route_id_seq", allocationSize = 1)
    @Column(name = "route_id", nullable = false)
    private Integer id;

    @NotNull
    @ManyToOne(fetch = FetchType.EAGER, optional = false)
    @JoinColumn(name = "user_id", nullable = false)
    private User user;

    @NotNull
    @ManyToOne(fetch = FetchType.EAGER, optional = false)
    @JoinColumn(name = "company_id", nullable = false)
    private Company company;

    @Column(name = "name", length = Integer.MAX_VALUE)
    private String name;

    @JsonManagedReference
    @OneToMany(mappedBy = "route", cascade = CascadeType.ALL, orphanRemoval = true)
    private List<AddressCompany> addresses;

    @NotNull
    @ColumnDefault("false")
    @Column(name = "public", nullable = false)
    private Boolean isPublic = false;
}
