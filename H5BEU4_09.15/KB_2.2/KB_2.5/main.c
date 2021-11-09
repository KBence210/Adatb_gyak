#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "szemelyek.bin"
#define FILENAME_TEMP "szemelyek_temp.bin"

typedef struct szemely {
			char azonosito[10];
			char nev[10];
} Szemely;


void listaz();
void felvisz();
void torol();
void keres();
int azonosito_kereso(const char*);
void azo_kiir(const char*);


int main()
{
    char *menu[9] = { "\n", "1. Lista", "2. Felvitel", "3. Torles",
                    "----------", "0. Kilep", "\n", NULL};
    char **p;
    int ch;
    do {
        p = menu;
        while(*p) { printf("%s\n", *p); *p++; }
        scanf("%d", &ch);
        switch(ch) {
            case 0: break;
            case 1: listaz(); break;
            case 2: felvisz(); break;
            case 3: torol(); break;
            default: putchar('\a');
            }
    } while( ch!=0 );

    return 0;
}

void felvisz() {
    int i, db;
	FILE *fp;
	Szemely szemely;
	char c;

	fp=fopen(FILENAME,"ab");
	if (!fp) { printf("Error: cannot open file."); return; }

	do {
        printf("Hany adatot szeretne felvinni? ");
        scanf("%d", &db);
    } while ((c = getchar()) != '\n' && c != EOF);

	for (i = 0; i < db; i++) {
        printf("\nAzonosito: ");
        scanf("%s", szemely.azonosito);
        printf("Nev: ");
        scanf("%s", szemely.nev);


        if (azonosito_kereso(szemely.azonosito)==0)
            fwrite(&szemely, sizeof(Szemely), 1, fp);
        else printf("Hiba: azonosito létezik!");
    }
	fclose(fp);
	return;
}

void listaz() {
	FILE *fp;
	Szemely szemely;
	int i, filesize;

	fp=fopen(FILENAME,"rb");
	if (!fp) { printf("Error: cannot open file."); return; }

	fseek(fp, 0L, SEEK_END);
	filesize = ftell(fp)/sizeof(Szemely);

	if (filesize == 0) {
		printf("\nFile is empty.\n");
		return;
	}

    	for (i=0; i<filesize; i++) {
        fseek(fp,sizeof(Szemely)*i,SEEK_SET);
        fread(&szemely,sizeof(Szemely),1,fp);
		printf("\nAzonosito: %s, nev:%s",
		szemely.azonosito,szemely.nev);
	}
	fclose(fp);
	return;
}

int azonosito_kereso(const char* azo) {
    FILE *fp;
	Szemely szemely;
	int i, filesize;

	fp=fopen(FILENAME,"rb");
	if (!fp) { printf("Error: cannot open file."); return -1; }

	fseek(fp, 0L, SEEK_END);
	filesize = ftell(fp)/sizeof(Szemely);

    for (i=0; i<filesize; i++) {
        fseek(fp,sizeof(Szemely)*i,SEEK_SET);
        fread(&szemely,sizeof(Szemely),1,fp);
        if (strcmp(szemely.azonosito,azo) == 0) return 1;
	}
	fclose(fp);
    return 0;
}

void azo_kiir(const char* azo) {
    FILE *fp;
	Szemely szemely;
	int i, filesize;

	fp=fopen(FILENAME,"rb");
	if (!fp) { printf("Error: cannot open file."); return; }

	fseek(fp, 0L, SEEK_END);
	filesize = ftell(fp)/sizeof(Szemely);

    for (i=0; i<filesize; i++) {
        fseek(fp,sizeof(Szemely)*i,SEEK_SET);
        fread(&szemely,sizeof(Szemely),1,fp);
        if (strcmp(szemely.azonosito,azo) == 0)
            printf("\nAzonosito: %s, nev:%s",
            szemely.azonosito,szemely.nev);
	}
	fclose(fp);
    return;
}

void torol() {
    FILE *fp, *fp_tmp;
	Szemely szemely;
	int i, filesize;
	char azonosito[10];

	fp=fopen(FILENAME,"rb");
	if (!fp) { printf("Error: cannot open file."); return; }

    fp_tmp=fopen(FILENAME_TEMP,"wb+");
	if (!fp_tmp) { printf("Error: cannot open file."); return; }

	fseek(fp, 0L, SEEK_END);
	filesize = ftell(fp)/sizeof(Szemely);

    printf("Torlendo azonosito: ");
    scanf("%s", azonosito);

    if (azonosito_kereso(azonosito)==1) {
        azo_kiir(azonosito);
        for (i=0; i<filesize; i++) {
            fseek(fp,sizeof(Szemely)*i,SEEK_SET);
            fread(&szemely,sizeof(Szemely),1,fp);
            if (strcmp(szemely.azonosito,azonosito) != 0) {
                fwrite(&szemely, sizeof(Szemely), 1, fp_tmp);
            }
        }
        fclose(fp);
        fp=fopen(FILENAME,"wb");
        if (!fp) { printf("Error: cannot open file."); return; }
        for (i=0; i<filesize-1; i++) {
            fseek(fp_tmp,sizeof(Szemely)*i,SEEK_SET);
            fread(&szemely,sizeof(Szemely),1,fp_tmp);
            fwrite(&szemely, sizeof(Szemely), 1, fp);
        }
        printf("\nTorolve.");
    }
    else printf("Nem talalt.");

    fclose(fp);
    fclose(fp_tmp);
    return;
}
