package dev.dubsky.routeguide.rest.service.impl;

import dev.dubsky.routeguide.rest.jwt.JwtTokenUtil;
import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.persistence.UserRepository;
import dev.dubsky.routeguide.rest.service.UserService;
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
    public User getCurrentUser(String token) {
        token = token.replace("Bearer ", "");
        return userRepository.findByUsername(jwtTokenUtil.getUsernameFromToken(token)).orElse(null);
    }

    @Override
    public List<User> findAll() {
        return userRepository.findAll();
    }

    public User save(User user) {
        user.setPassword(passwordEncoder.encode(user.getPassword()));
        user.setCreation(java.time.Instant.now());
        if (user.getRole() == null) {
            user.setRole("USER");
        }
        String email = user.getEmail();
        String emailAfterAt = email.substring(email.indexOf("@"));
        System.out.println("Registering user with email ending: " + emailAfterAt);
        Company company = companyService.checkIfMailExists(emailAfterAt);
        if (company != null) {
            System.out.println("Company found: " + company.getName());
            user.setCompany(company);
        }
        return userRepository.save(user);
    }

    @Override
    public void deleteById(Long id) {
        userRepository.deleteById(id);
    }
}
