package dev.dubsky.routeguide.rest.service.impl;

import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.persistence.CompanyRepository;
import dev.dubsky.routeguide.rest.service.CompanyService;
import dev.dubsky.routeguide.rest.utility.CLog;

import org.springframework.beans.factory.annotation.Autowired;
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
        CLog.out(0, "Checking if mail exists: " + mail);
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

}
