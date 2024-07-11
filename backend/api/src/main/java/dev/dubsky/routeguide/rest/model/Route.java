package dev.dubsky.routeguide.rest.model;

import jakarta.annotation.Nullable;
import jakarta.persistence.*;
import jakarta.validation.constraints.NotNull;
import lombok.Getter;
import lombok.Setter;

import java.util.List;

import com.fasterxml.jackson.annotation.JsonBackReference;

@Getter
@Setter
@Entity
@Table(name = "routes")
@NamedQueries({
        @NamedQuery(name = "Route.getRoutesByUser", query = "SELECT r FROM Route r WHERE r.user.username = :username"),
        @NamedQuery(name = "Route.getRouteById", query = "SELECT r FROM Route r WHERE r.id = :id"),
        @NamedQuery(name = "Route.getRouteByName", query = "SELECT r FROM Route r WHERE r.name = :name")
})
public class Route {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE, generator = "routes_id_gen")
    @SequenceGenerator(name = "routes_id_gen", sequenceName = "routes_routes_id_seq", allocationSize = 1)
    @Column(name = "routes_id", nullable = false)
    private Integer id;

    @NotNull
    @ManyToOne(fetch = FetchType.EAGER, optional = false)
    @JoinColumn(name = "user_id", nullable = false)
    private User user;

    @Column(name = "name", length = Integer.MAX_VALUE)
    private String name;

    @OneToMany(mappedBy = "route", cascade = CascadeType.ALL, orphanRemoval = true)
    private List<Address> addresses;

    @Column(name = "public", nullable = false)
    private boolean isPublic;

    @Nullable
    @ManyToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "group_id")
    private Group group;
}