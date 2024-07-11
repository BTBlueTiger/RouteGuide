package dev.dubsky.routeguide.rest.service.impl;

import dev.dubsky.advancedlog.AdvLogger;
import dev.dubsky.advancedlog.Color;
import dev.dubsky.routeguide.rest.jwt.JwtTokenUtil;
import dev.dubsky.routeguide.rest.model.Company;
import dev.dubsky.routeguide.rest.model.Group;
import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.persistence.GroupRepository;
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
    private GroupRepository groupRepository;

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

        if (userRepository.findByUsername(user.getUsername()).isPresent()) {
            AdvLogger.output(Color.RED, "Username already exists: " + user.getUsername());
            return null;
        }

        if (userRepository.findByEmail(user.getEmail()).isPresent()) {
            AdvLogger.output(Color.RED, "Email already exists: " + user.getEmail());
            return null;
        }

        user.setPassword(passwordEncoder.encode(user.getPassword()));
        user.setCreation(java.time.Instant.now());
        if (user.getRole() == null) {
            user.setRole("USER");
        }
        String email = user.getEmail();
        String emailAfterAt = email.substring(email.indexOf("@"));
        AdvLogger.output(Color.GREEN, "User ["+ user.getUsername() +"] registered with email ending: " + emailAfterAt);
        Company company = companyService.checkIfMailExists(emailAfterAt);
        if (company != null) {
            AdvLogger.output(Color.GREEN, "Company found: " + company.getName());
            user.setCompany(company);
        }
        return userRepository.save(user);
    }

    public User save(User user) {
        return userRepository.save(user);
    }

    public User saveMail(User user) {
        AdvLogger.output(Color.GREEN, "User ["+ user.getUsername() +"] changed email to : " + user.getEmail());
        String email = user.getEmail();
        String emailAfterAt = email.substring(email.indexOf("@"));
        Company company = companyService.checkIfMailExists(emailAfterAt);
        if (company != null) {
            AdvLogger.output(Color.GREEN, "Company found: " + company.getName());
            user.setCompany(company);
        } else {
            AdvLogger.output(Color.RED, "Company not found");
            user.setCompany(null);
        }
        return userRepository.save(user);
    }

    @Override
    public void deleteById(Long id) {
        userRepository.deleteById(id);
    }

    @Override
    public List<User> findByCompany(Long companyId) {
        return userRepository.findByCompanyId(companyId).orElse(null);
    }

    @Override
    public Group getGroupByGroupID(Long group_id) {
        return groupRepository.findById(group_id).orElse(null);
    }
}