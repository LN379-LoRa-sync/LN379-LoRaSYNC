CREATE DATABASE db1;
USE db1;
CREATE TABLE mydata(id varchar(10), name varchar(10), water_level double, last_updated timestamp);
INSERT INTO mydata(id,name,water_level) VALUES ('id_values','name',water_level);
SELECT*FROM mydata;
