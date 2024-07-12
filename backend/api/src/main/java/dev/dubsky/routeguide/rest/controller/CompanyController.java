package dev.dubsky.routeguide.rest.controller;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.dto.UserDTO;
import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.service.CompanyService;

import dev.dubsky.routeguide.rest.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
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

    @Autowired
    private UserService userService;

    /**
     * Get company by id
     * @param id Company id
     * @return Company object
     */
    @GetMapping(("/{id}"))
    @PreAuthorize("hasRole('ADMIN')")
    public Company getCompany(@PathVariable Long id) {
        return companyService.getCompanyById(id);
    }

    /**
     * Get all companies
     * @return List of companies
     */
    @GetMapping("/all")
    @PreAuthorize("hasRole('ADMIN')")
    public List<Company> getAllCompanies() {
        AdvLogger.output(Color.GREEN, "[ADMIN] Getting all companies");
        return companyService.getAllCompanies();
    }

    /**
     * Get owner of the company
     * @param id Company id
     * @return User object
     */
    @GetMapping("/get_owner/{id}")
    @PreAuthorize("hasRole('ADMIN')")
    public User getOwner(@PathVariable Long id) {
        AdvLogger.output(Color.GREEN, "[ADMIN] Getting owner for company: " + companyService.getCompanyById(id).getName());
        return companyService.getCompanyById(id).getOwner();
    }

    /**
     * Get users of the company
     * @param token Authorization token
     * @return List of UserDTO objects
     */
    @GetMapping("/get_users")
    @PreAuthorize("hasRole('USER')")
    public ResponseEntity<?> getUsers(@RequestHeader("Authorization") String token) {
        User user = userService.getCurrentUser(token);
        List<UserDTO> users = companyService.getUsers(userService, user);
        if (users == null) {
            return ResponseEntity.badRequest().body("Invalid token or user is not a company owner");
        }
        return ResponseEntity.ok(users);
    }
}