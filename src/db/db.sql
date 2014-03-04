-- postgres db, sql

CREATE ROLE synod SUPERUSER;
CREATE ROLE admin CREATEDB;

CREATE USER synod WITH PASSWORD 'root';

CREATE DATABASE recognise
  OWNER = synod
  ENCODING = 'UTF8'
  CONNECTION LIMIT = -1;


CREATE TABLE class_recogn
(
    id_no serial NOT NULL,
    first_name varchar(20) NOT NULL,
    last_name varchar(20) NOT NULL,
    classes_missed integer NOT NULL,
    dates_missed varchar(200) NOT NULL,
    last_time_stamp TIMESTAMP,

    PRIMARY KEY (id_no)
)


CREATE TABLE sec_recogn
(
    id_no serial NOT NULL,
    first_name varchar(20) NOT NULL,
    last_name varchar(20) NOT NULL,
    last_time_stamp TIMESTAMP,
    zone varchar(20) NOT NULL,

    PRIMARY KEY (id_no)
)


GRANT ALL PRIVILEGES ON class_recogn to synod;

\c recognise
SELECT version()
