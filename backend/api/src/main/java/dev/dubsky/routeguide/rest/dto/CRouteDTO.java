package dev.dubsky.routeguide.rest.dto;

import dev.dubsky.routeguide.rest.model.Address;
import dev.dubsky.routeguide.rest.model.AddressCompany;
import dev.dubsky.routeguide.rest.model.Route;
import dev.dubsky.routeguide.rest.model.RouteCompany;
import lombok.Getter;
import lombok.Setter;

import java.util.List;

@Getter
@Setter
public class CRouteDTO {
    private int id;
    private String name;
    private List<Address> addresses;

    public CRouteDTO(Route route) {
        this.id = route.getId();
        this.name = route.getName();
        this.addresses = route.getAddresses();
    }

}
