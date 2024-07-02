package dev.dubsky.routeguide.rest.service;

import dev.dubsky.routeguide.rest.model.Company;

import java.util.List;

public interface CompanyService {

    Company getCompany();
    List<Company> getAllCompanies();
    // List<UserDTO> getUsers();
    Company checkIfMailExists(String mail);

}
