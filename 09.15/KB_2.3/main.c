#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<2;i++)
    {
        pelda_1();
    }
    FILE *fptr1, *fptr2;
    char filename[100], c;

    printf("Add meg a masolni kivant fajlt \n");
    scanf("%s", filename);

    fptr1 = fopen(filename, "r");
    if (fptr1 == NULL)
    {
        printf("Nem lehet megnyitni %s fajlt \n", filename);
        exit(0);
    }

    printf("Add meg,hogy melyik fajlba masolja at \n");
    scanf("%s", filename);

    fptr2 = fopen(filename, "w");
    if (fptr2 == NULL)
    {
        printf("Nem lehet megnyitni %s fajlt \n", filename);
        exit(0);
    }

    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }

    printf("A tartalom at lett masolva %s fajlba", filename);

    fclose(fptr1);
    fclose(fptr2);
    return 0;
}

void pelda_1() {
        FILE *fp;
        char ch;
        char fnev[50];
        printf("Filenev: ");
        scanf("%s", fnev);
        fp = fopen(fnev, "w");
        printf("Uzenet ");
        while( (ch = getchar()) != '#') {
  putc(ch, fp);
        }
        fclose(fp);

        fp = fopen(fnev, "r");
        while ( (ch = getc(fp))  != EOF ) {
   printf("%c",ch);
       }
      fclose(fp);
}
