package dev.dubsky.routeguide.rest.service;

import dev.dubsky.routeguide.rest.model.Company;

import java.util.List;

public interface CompanyService {

    List<Company> getAllCompanies();
    Company checkIfMailExists(String mail);
    Company getCompanyById(Long id);
    Company getCompanyByMailEnding(String mailEnding);
    Company getCompanyByName(String name);

}
