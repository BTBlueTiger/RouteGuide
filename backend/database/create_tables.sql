create table "user"
(
    user_id  integer   not null
        constraint user_pk
            primary key,
    username varchar   not null,
    email    varchar   not null,
    password varchar   not null,
    creation timestamp not null
);

alter table "user"
    owner to admin;

create table "group"
(
    group_id integer not null
        constraint group_pk
            primary key,
    status   varchar,
    location varchar
);

alter table "group"
    owner to admin;

create table route
(
    route_id   integer not null
        constraint route_pk
            primary key,
    start      varchar,
    "end"      varchar,
    included   varchar,
    creator_id integer
        constraint route_user_user_id_fk
            references "user",
    group_id   integer
        constraint route_group_group_id_fk
            references "group"
);

alter table route
    owner to admin;

create table user_group
(
    group_id integer not null
        constraint user_group_group_group_id_fk
            references "group",
    user_id  integer not null
        constraint user_group_user_user_id_fk
            references "user"
);

alter table user_group
    owner to admin;


