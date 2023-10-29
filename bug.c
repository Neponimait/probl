#include <stdio.h>
#include <string.h>

#define MAXAD 101
#define MAX_CIS_ADR 50

//funkce pro prevod vsech pismen na mala
void prevedpismena(char adresy[MAX_CIS_ADR][MAXAD], char *klic) {
    int i = 0;
    int j = 0;

    while (i < MAX_CIS_ADR) {
        while (j < MAXAD) {
            if (adresy[i][j] >= 'A' && adresy[i][j] <= 'Z') {
                adresy[i][j] = adresy[i][j] - 'A' + 'a';
            }
            j++;
        }
        j = 0;
        i++;
    }

    for (int i = 0; klic[i]; i++) {
        if (klic[i] >= 'A' && klic[i] <= 'Z') {
            klic[i] = klic[i] + ('a' - 'A');
        }
    }
}

// hlavni funkce pro porovnani a vystup
void porovnej(char adresy[MAX_CIS_ADR][MAXAD], char *klic) {
    char shoda[MAXAD];
    int pocet_shod = 0;
    int i = 0;
    int j = 0;
    while(i < MAX_CIS_ADR){
            if(strcmp(klic[j], adresy[i][j] != 0)){
                break;  
            } else { 
            pocet_shod++;
            j++;
            continue;}
        i++;
    }
    for (int i = 0; i < MAX_CIS_ADR; i++) {
        if (strcmp(klic[i], adresy[i]) == 0) {
            pocet_shod++;
            strcpy(shoda, adresy[i]);
        }
    }

    if (pocet_shod == 1) {
        printf("Found: %s\n", shoda);
    } else if (pocet_shod == 0) {
        printf("Not found\n");
    }
}




int main(int argc, char *argv[]) {
    if (argc < 1) {
        printf("Chybí argumenty\n");
        return 1;
    }
    char adresy[MAX_CIS_ADR][MAXAD];
    //ulozeni klice do pole
  
    const char *retezec = argv[1];  // Získání prvního argumentu
     

    int klic[MAXAD];  // Pole integerů s pevnou délkou

    // Převod znaků na ASCII hodnoty a uložení do pole integerů
    for (int i = 0; i < MAXAD; i++) {
        klic[i] = (int)retezec[i];
    }

    // Výpis výsledného pole integerů
    //printf("Pole integerů: ");
   // for (int i = 0; i < delka; i++) {
   //     printf("%d ", klic[i]);
   // }
   // printf("\n");
   






    FILE *file = stdin;

    int c;
    int i = 0;
    int j = 0;
    while(i < MAX_CIS_ADR){
        while (j < MAXAD && (c = fgetc(file)) != EOF){
            adresy[i][j] = c;
            //printf("%d\n", adresy[i][j]);
            j++;
            if (c == '\0' || c == ' ' || c == 10){
                adresy[i][j] = '\0';
                j = 0;
                i++;
            }
        }
        
    }

    prevedpismena(adresy[MAX_CIS_ADR][MAXAD], *klic);
    porovnej(adresy[MAX_CIS_ADR][MAXAD], *klic);


//int n = 0;
//int m = 0;

//while(n < MAX_CIS_ADR){
  //  while(m < MAXAD){
   //     printf("%d\n", adresy[i][j]);
  //      j++;
//}
//    i++;
//}

    
    //prevedpismena(adresy);
   // porovnej(adresy);

    return 0;
}