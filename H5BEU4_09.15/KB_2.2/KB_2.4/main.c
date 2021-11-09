#include <stdio.h>
#include <stdlib.h>

struct Auto{
char rendszam[6];
char tipus[20];
double ar;
};

int main()
{
    pelda_3_felvisz();
    int poz=lekerdez();
    pelda_3_olvas(poz);
    return 0;
}

void pelda_3_felvisz(){
    struct Auto autok[3];
    FILE *fdata;
    int i=0;
    for(i=0;i<3;i++)
    {
        printf("rsz:");
        scanf("%s",&autok[i].rendszam);
        printf("tipus:");
        scanf("%s",&autok[i].tipus);
        printf("ar:");
        scanf("%lf",&autok[i].ar);
        printf("\n");
    }

    fdata = fopen("Autok.dat","wb");
    for(int i=0;i<3;i++)
    {
        fwrite(&(autok[i]), sizeof(struct Auto), 1, fdata);
    }
    fclose(fdata);
}

int lekerdez()
{
    int poz;
    printf("hanyadik autora kivancsi?\n");
    scanf("%d",&poz);
    return poz;
}

void pelda_3_olvas(int poz)
{
    FILE *fdata;
    fdata=fopen("Autok.dat","rb");
    struct Auto aurek;

    if (fdata == NULL) {
        printf ("file hiba\n");
        return;
    }

    fseek(fdata, (poz-1)* sizeof(struct Auto), 0);
    fread(&aurek, sizeof(struct Auto), 1, fdata);

    printf ("rsz: %s\n", aurek.rendszam);
    printf ("tip: %s\n", aurek.tipus);
    printf ("ar:  %.2lf\n", aurek.ar);

    fclose(fdata);
}
