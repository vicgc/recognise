CREATE USER synod WITH PASSWORD 'root';

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


GRANT ALL PRIVILEGES ON class_recogn to synod;


CREATE DATABASE recognise
  OWNER = synod
  ENCODING = 'UTF8'
  CONNECTION LIMIT = 25;
