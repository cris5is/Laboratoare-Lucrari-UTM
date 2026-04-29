#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "complexity.h"
int main() {
    int option = -1, sizes[] = {10000, 100000, 1000000};
    int n = 0;
    srand(time(NULL));
    while (option != 0) {
        printf("1. Tabloul demonstrativ de n elemente (5<= n <=20)\n ");
        printf("2. Tabloul cu valori aleatorii (n=10000, n=100000, n=1000000).\n ");
        printf("3. Tabloul sortat crescator (n=10000, n=100000, n=1000000).\n ");
        printf("4. Tabloul sortat descrescator (n=10000, n=100000, n=1000000).\n ");
        printf("0. Iesire. \n ");
        scanf("%d", &option);
        switch (option) {
            case 0:
                break;
            case 1:
                printf("n=");
                scanf("%d", &n);
                analizaEmpirica(n, 1);
                break;
            case 2:
            case 3:
            case 4:
                for (int i = 0; i < 3; i++) analizaEmpirica(sizes[i], option);
                break;
            default:
                printf("Introduceti valoare valida [0,4]");
                break;
        }
    }
    return 0;
}