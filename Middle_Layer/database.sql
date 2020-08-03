#All data is stored in mysql databses;
CREATE DATABASE db1;
USE db1;
#Table for water collection in reservoir
CREATE TABLE mydata(id varchar(10), name varchar(10), water_level double, last_updated timestamp);
INSERT INTO mydata(id,name,water_level) VALUES ('id_values','name',water_level);
SELECT*FROM mydata;

#Table for all whether data station
USE db1;
CREATE TABLE all_whether_station(temp double,humidity double, solar_raditon double,
 pressure double, evaporation double, windspeed double, last_updated timestamp);
INSERT INTO all_whether_station(id,name,water_level) VALUES ('id_values','name',water_level);
SELECT*FROM all_whether_station;
#databses for net reservoir level,canal level and precipitation

USE db1;
CREATE TABLE dam_data(frl double,elive_storage double,reservoir double,live_storage double,last_updated timestamp);
INSERT INTO dam_data(frl,elive_storage,reservoir,live_storage)
VALUES(frl_values,elive_storage_values,reservoir_values,live_storage_values);
SELECT*FROM dam_data;
#IN abouve all queries we are only creating tables for different parameters and feeding the data which 
#we got from govt and using our sensors in that table.We will be anylysing this data in Grafana usng graphs.
