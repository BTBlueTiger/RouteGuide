create table "group"
(
    group_id serial
        constraint group_pk
            primary key,
    name     varchar not null
);

alter table "group"
    owner to admin;

create table companies
(
    company_id  serial
        constraint companies_pk
            primary key,
    name        varchar not null
        constraint companies_pk_2
            unique,
    mail_ending varchar
);

alter table companies
    owner to admin;

create table "user"
(
    user_id    serial
        constraint user_pk
            primary key,
    email      varchar                                   not null,
    username   varchar                                   not null,
    password   varchar,
    role       varchar default 'USER'::character varying not null,
    creation   date                                      not null,
    company_id integer
        constraint company_fk
            references companies
);

alter table "user"
    owner to admin;

create table user_group
(
    user_id  integer not null
        constraint user_group_user_user_id_fk
            references "user",
    group_id integer not null
        constraint user_group_group_group_id_fk
            references "group",
    constraint user_group_pk
        primary key (user_id, group_id)
);

alter table user_group
    owner to admin;

create table routes
(
    routes_id serial
        constraint routes_pk
            primary key,
    user_id   integer not null
        constraint routes_user_user_id_fk
            references "user",
    name      varchar
);

alter table routes
    owner to admin;

create table addresses
(
    id        serial
        constraint addresses_pk
            primary key,
    town      varchar          not null,
    street    varchar          not null,
    number    varchar          not null,
    longitude double precision not null,
    latitude  double precision not null,
    route_id  integer          not null
        constraint addresses_routes_routes_id_fk
            references routes
);

alter table addresses
    owner to admin;