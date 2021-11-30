create database dchcas_8a;

use dchcas_8a;

create table tulajdonos(
	tkod INT(3) PRIMARY KEY,
	nev VARCHAR(20),
	varos VARCHAR(20)
);

create table auto(
	rendszam CHAR(7) PRIMARY KEY,
	tipus VARCHAR(25) NOT NULL,
	szin VARCHAR(15),
    kor INT(2),
    ar INT(8),
	tulaj INT(3) REFERENCES tulajdonos(tkod)
);

insert into tulajdonos values (101,'Kis Janos','Miskolc');
insert into tulajdonos values (102,'Kis Eva','Szerencs');
insert into tulajdonos values (103,'Retek Ödön','Miskolc');
insert into tulajdonos values (104,'Virág Zoltán','Nyék');
insert into tulajdonos values (105,'Nagy Eszter','Nyék');
insert into tulajdonos values (106,'Kovács Magor','Szerencs');
insert into tulajdonos values (107,'Asztal Antal','Miskolc');

insert into auto values('FER-831','Opel Corsa','Piros',18,390,101);
insert into auto values('JXJ-239','Suzuki Swift','Zold',15,450,105);
insert into auto values('JAH-425','Skoda Fabia','Piros',13,620,102);
insert into auto values('MLM-211','Toyota Yaris','Feher',3,1850,105);
insert into auto values('KFT-204','Opel Astra','Szurke',7,1250,106);
insert into auto values('JCD-443','Opel Astra','Feher',12,990,1007);
insert into auto values('KAP-290','BMW 316','Fekete',6,2350,102);
insert into auto values('GDF-525','Renault Twingo','Fekete',16,280,NULL);
insert into auto values('HUB-936','Suzuki Swift','Fekete',16,500,NULL);
