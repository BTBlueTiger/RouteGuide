-- Drop and create the sequence to avoid conflicts
DROP SEQUENCE IF EXISTS addresses_company_id_seq;
CREATE SEQUENCE addresses_company_id_seq;

-- Create the tables
CREATE TABLE "group"
(
    group_id serial
        CONSTRAINT group_pk
            PRIMARY KEY,
    name     varchar NOT NULL
);

ALTER TABLE "group"
    OWNER TO admin;

CREATE TABLE companies
(
    company_id  serial
        CONSTRAINT companies_pk
            PRIMARY KEY,
    name        varchar NOT NULL
        CONSTRAINT companies_pk_2
            UNIQUE,
    mail_ending varchar,
    owner_id    integer NOT NULL
);

ALTER TABLE companies
    OWNER TO admin;

CREATE TABLE "user"
(
    user_id    serial
        CONSTRAINT user_pk
            PRIMARY KEY,
    email      varchar                                   NOT NULL,
    username   varchar                                   NOT NULL,
    password   varchar,
    role       varchar DEFAULT 'USER'::character varying NOT NULL,
    creation   date                                      NOT NULL,
    company_id integer
        CONSTRAINT company_fk
            REFERENCES companies,
    group_id   integer DEFAULT 1
        CONSTRAINT user_group_group_id_fk
            REFERENCES "group"
);

ALTER TABLE "user"
    OWNER TO admin;

ALTER TABLE companies
    ADD CONSTRAINT companies_user_user_id_fk
        FOREIGN KEY (owner_id) REFERENCES "user";

CREATE TABLE routes
(
    routes_id serial
        CONSTRAINT routes_pk
            PRIMARY KEY,
    user_id   integer               NOT NULL
        CONSTRAINT routes_user_user_id_fk
            REFERENCES "user",
    name      varchar,
    public    boolean DEFAULT false NOT NULL,
    group_id  integer
        CONSTRAINT routes_group_group_id_fk
            REFERENCES "group"
);

ALTER TABLE routes
    OWNER TO admin;

CREATE TABLE addresses
(
    id        serial
        CONSTRAINT addresses_pk
            PRIMARY KEY,
    town      varchar          NOT NULL,
    street    varchar          NOT NULL,
    number    varchar          NOT NULL,
    longitude double precision NOT NULL,
    latitude  double precision NOT NULL,
    route_id  integer          NOT NULL
        CONSTRAINT addresses_routes_routes_id_fk
            REFERENCES routes
);

ALTER TABLE addresses
    OWNER TO admin;

CREATE TABLE routes_company
(
    route_id   serial
        CONSTRAINT id
            PRIMARY KEY,
    user_id    integer               NOT NULL
        CONSTRAINT routes_company_user_user_id_fk
            REFERENCES "user",
    company_id integer               NOT NULL
        CONSTRAINT routes_company_companies_company_id_fk
            REFERENCES companies,
    name       varchar,
    public     boolean DEFAULT false NOT NULL
);

ALTER TABLE routes_company
    OWNER TO admin;

CREATE TABLE addresses_company
(
    id         integer DEFAULT nextval('addresses_company_id_seq'::regclass) NOT NULL
        CONSTRAINT addresses_company_pk
            PRIMARY KEY,
    identifier varchar                                                      NOT NULL,
    longitude  double precision                                             NOT NULL,
    latitude   double precision                                             NOT NULL,
    route_id   integer                                                      NOT NULL
        CONSTRAINT addresses_company_routes_company_route_id_fk
            REFERENCES routes_company
);

ALTER TABLE addresses_company
    OWNER TO admin;
