package dev.dubsky.routeguide.rest;

import dev.dubsky.routeguide.rest.model.User;
import dev.dubsky.routeguide.rest.persistence.UserRepository;
import dev.dubsky.routeguide.rest.service.impl.CompanyServiceImpl;
import dev.dubsky.routeguide.rest.service.impl.CustomUserDetailsService;
import dev.dubsky.routeguide.rest.service.impl.UserServiceImpl;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.test.context.junit.jupiter.SpringExtension;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.Mockito.when;

@ExtendWith(SpringExtension.class)
public class UserServiceTests {

    @InjectMocks
    private UserServiceImpl userService;

    @Mock
    private CompanyServiceImpl companyService;

    @Mock
    private UserRepository userRepository;

    @Mock
    private PasswordEncoder passwordEncoder;

    @Mock
    private CustomUserDetailsService customUserDetailsService;

    private User user;

    @BeforeEach
    public void setUp() {
        MockitoAnnotations.initMocks(this);
        user = new User();
        user.setId(1L);
        user.setUsername("dubsky");
        user.setPassword("hellothere");
        user.setEmail("mock@mail.com");
    }

    @Test
    public void testCreateUser() {
        when(userService.save(user)).thenReturn(user);
        User savedUser = userService.save(user);
        assertThat(savedUser.getUsername()).isEqualTo("dubsky");
    }

    @Test
    public void testUpdateUser() {
        when(userService.save(user)).thenReturn(user);
        User savedUser = userService.save(user);
        assertThat(savedUser.getUsername()).isEqualTo("dubsky");
    }

    @Test
    public void testDeleteUser() {
        userService.deleteById(1L);
        assertThat(userService.findById(1L)).isNull();
    }
}