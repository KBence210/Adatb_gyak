create database h5beu4;

use h5beu4;

create table oktato(
	neptunkod VARCHAR(6) PRIMARY KEY,
	nev VARCHAR(30),
	tanszek VARCHAR(20)
);

create table targy(
	kod INT NOT NULL PRIMARY KEY,
	kredit INT(1),
	megnevezes VARCHAR(20)
);

create table hallgato(
	neptunkod VARCHAR(6) PRIMARY KEY,
	nev VARCHAR(20),
	tankor VARCHAR(20),
	szul_d DATE,
	eletkor INT(2),
	irszam INT(4),
	varos VARCHAR(20),
	utca VARCHAR(20),
	hsz INT(3)
);


create table hallgat(
	kod INT NOT NULL,
	neptunkod VARCHAR(6),
	felev INT(1),
	vizsgajegy INT(1)
	FOREIGN KEY(kod) references targy(kod),
	FOREIGN KEY(neptunkod) references hallgato(kod);
);
