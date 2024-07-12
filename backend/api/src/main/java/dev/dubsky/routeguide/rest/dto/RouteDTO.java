package dev.dubsky.routeguide.rest.dto;

import dev.dubsky.routeguide.rest.model.AddressCompany;
import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.model.RouteCompany;
import lombok.Getter;
import lombok.Setter;

import java.util.List;

@Getter
@Setter
public class RouteDTO {
    private int id;
    private String name;
    private List<AddressCompany> addresses;

    public RouteDTO(RouteCompany routeCompany) {
        this.id = routeCompany.getId();
        this.name = routeCompany.getName();
        this.addresses = routeCompany.getAddresses();
    }
}
