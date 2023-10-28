#include <stdio.h>
#include <string.h>

#define MAXAD 101
#define MAX_CIS_ADR 50


void prevedpismena(char adresy[MAX_CIS_ADR][MAXAD]) {
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
}

void porovnej(char adresy[MAX_CIS_ADR][MAXAD]) {
    char shoda[MAXAD];
    int pocet_shod = 0;

    for (int i = 2; i < MAX_CIS_ADR; i++) {
        if (strcmp(adresy[1], adresy[i]) == 0) {
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
    if (argc < 2) {
        printf("Chybí argumenty\n");
        return 1;
    }
    char adresy[MAX_CIS_ADR][MAXAD];
    int pocet_adr = 0;

    FILE *file = stdin;

    int c;
    int i = 0;
    int j = 0;
    while(i < MAX_CIS_ADR){
        while (j < MAXAD && (c = fgetc(file)) != EOF){
            adresy[i][j] == c;
            j++;
            if (c == '\0' || c == ' '){
                adresy[i][j] = '\0';
                j = 0;
            }
        }
        
    }
    for(int i = 0; i < MAX_CIS_ADR; i++){
    printf("N");
    }
    prevedpismena(adresy);
    porovnej(adresy);

    return 0;
}