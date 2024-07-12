package dev.dubsky.routeguide.rest.service.impl;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.dto.UserDTO;
import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.persistence.CompanyRepository;
import dev.dubsky.routeguide.rest.service.CompanyService;
import dev.dubsky.routeguide.rest.service.UserService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Lazy;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class CompanyServiceImpl implements CompanyService {

    @Autowired
    private CompanyRepository companyRepository;

    @Override
    public List<Company> getAllCompanies() {
        return companyRepository.findAll();
    }

    @Override
    public Company checkIfMailExists(String mail) {
        AdvLogger.output(Color.GREEN, "Checking if mail exists: " + mail);
        return companyRepository.findByMailEnding(mail).orElse(null);
    }

    @Override
    public Company getCompanyById(Long id) {
        return companyRepository.findById(id).orElse(null);
    }

    @Override
    public Company getCompanyByMailEnding(String mailEnding) {
        return companyRepository.findByMailEnding(mailEnding).orElse(null);
    }

    @Override
    public Company getCompanyByName(String name) {
        return companyRepository.findByName(name).orElse(null);
    }

    @Override
    public Company getCompanyByOwner(Long ownerId) {
        return companyRepository.findByOwner(ownerId).orElse(null);
    }

    @Override
    public List<UserDTO> getUsers(UserService userService, User user) {
        Company company = getCompanyByOwner(user.getId());
        if (company == null) {
            return null;
        }
        AdvLogger.output(Color.GREEN, "[COMPANY] Getting users for company: " + company.getName() + " by user: " + user.getUsername());
        // Ugly, but I don't want to change the whole structure
        return userService.findByCompany(company.getId().longValue()).stream().map(UserDTO::new).toList();
    }
}
