package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.routeguide.rest.dto.UserDTO;
import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.service.CompanyService;
import dev.dubsky.routeguide.rest.utility.CLog;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestHeader;
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
        return companyService.getCompanyById(id);
    }

    @GetMapping("/all")
    @PreAuthorize("hasRole('ADMIN')")
    public List<Company> getAllCompanies() {
        return companyService.getAllCompanies();
    }

    @GetMapping("/get_owner/{id}")
    @PreAuthorize("hasRole('ADMIN')")
    public User getOwner(@PathVariable Long id) {
        CLog.out(0, "Getting owner for company: " + companyService.getCompanyById(id).getName());
        return companyService.getCompanyById(id).getOwner();
    }

    @GetMapping("/get_users")
    @PreAuthorize("hasRole('USER')")
    public List<UserDTO> getUsers(@RequestHeader("Authorization") String token) {
        return companyService.getUsers(token);
    }

}
