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
