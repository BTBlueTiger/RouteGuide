package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.service.CompanyService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/company")
public class CompanyController {

    @Autowired
    private CompanyService companyService;

    @GetMapping
    @PreAuthorize("hasRole('ADMIN')")
    public Company getCompany(@PathVariable Long id) {
        return companyService.getCompany();
    }

    @GetMapping("/all")
    @PreAuthorize("hasRole('ADMIN')")
    public List<Company> getAllCompanies() {
        return companyService.getAllCompanies();
    }

//    @GetMapping("/getUsers")
//    @PreAuthorize("hasRole('ADMIN')")
//    public List<UserDTO> getUsers() {
//        return companyService.getUsers();
//    }

}
