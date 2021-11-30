create database dchcas_9_2;

use dchcas_9_2;

create table tanfolyam(
	tkod INT,
    ar INT CHECK(ar>0),
    megnevezes VARCHAR(50),
    tipus VARCHAR(1)
);

create table befizetes(
	kurzus INT REFERENCES tanfolyam(tkod),
	diak boolean references resztvevo(tajszam),
    befizetes  INT 
);

create table resztvevo(
	tajszam varchar(12),
    nev varchar(50),
    lakcim varchar(100)
);
