Create database wh8l7e_3;

use wh8l7e_3;

create table tanfolyam(
tkód int primary key,
ar int,
tipus varchar(30),
megnevezes varchar(50)
);

create table resztvevo(
tajszam int primary key,
lakcím varchar(40),
nev varchar(30)
);

create table befizetes(
tanulo int,
kurzus int,
befizetes int,
foreign key(tanulo) references resztvevo(tajszam),
foreign key(kurzus) references tanfolyam(tkód)
);
