package dev.dubsky.routeguide.rest.service.impl;

import dev.dubsky.routeguide.rest.jwt.JwtTokenUtil;
import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.persistence.UserRepository;
import dev.dubsky.routeguide.rest.service.UserService;
import dev.dubsky.routeguide.rest.utility.CLog;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserServiceImpl implements UserService {

    @Autowired
    private UserRepository userRepository;

    @Autowired
    private CompanyServiceImpl companyService;

    @Autowired
    private PasswordEncoder passwordEncoder;

    @Autowired
    JwtTokenUtil jwtTokenUtil;

    @Override
    public User findById(Long id) {
        return userRepository.findById(id).orElse(null);
    }

    @Override
    public User findByUsername(String username) {
        return userRepository.findByUsername(username).orElse(null);
    }

    @Override
    public User getCurrentUser(String token) {
        token = token.replace("Bearer ", "");
        return userRepository.findByUsername(jwtTokenUtil.getUsernameFromToken(token)).orElse(null);
    }

    @Override
    public List<User> findAll() {
        return userRepository.findAll();
    }

    public User create(User user) {
        user.setPassword(passwordEncoder.encode(user.getPassword()));
        user.setCreation(java.time.Instant.now());
        if (user.getRole() == null) {
            user.setRole("USER");
        }
        String email = user.getEmail();
        String emailAfterAt = email.substring(email.indexOf("@"));
        CLog.out(0, "User ["+ user.getUsername() +"] registered with email ending: " + emailAfterAt);
        Company company = companyService.checkIfMailExists(emailAfterAt);
        if (company != null) {
            CLog.out(0, "Company found: " + company.getName());
            user.setCompany(company);
        }
        return userRepository.save(user);
    }

    public User save(User user) {
        return userRepository.save(user);
    }

    public User saveMail(User user) {
        CLog.out(0, "User ["+ user.getUsername() +"] changed email to : " + user.getEmail());
        String email = user.getEmail();
        String emailAfterAt = email.substring(email.indexOf("@"));
        Company company = companyService.checkIfMailExists(emailAfterAt);
        if (company != null) {
            CLog.out(0, "Company found: " + company.getName());
            user.setCompany(company);
        } else {
            CLog.out(2, "Company not found");
            user.setCompany(null);
        }
        return userRepository.save(user);
    }

    @Override
    public void deleteById(Long id) {
        userRepository.deleteById(id);
    }
}
