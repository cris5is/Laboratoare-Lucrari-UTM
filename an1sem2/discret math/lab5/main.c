#include <stdio.h>
#include <stdlib.h>

#include "flux.h"

int main() {
    Retea r;
    int n, option, flux_max = 0;
    int sursa, destinatie;
    int retea_creata = 0;

    do {
        printf("1. Introducere retea transport\n");
        printf("2. Determinare flux maxim\n");
        printf("3. Afisare rezultate\n");
        printf("4. Iesire\n");
        printf("Optiune: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Nr. de varfuri: ");
                while (scanf("%d", &n) != 1 || n < 0) {
                    printf("Valoare invalida, introduceti din nou (n>=0): ");
                }
                citire_retea(&r, NULL, n);
                retea_creata = 1;
                break;
            case 2:
                if (!retea_creata) {
                    printf("Creati reteaua intai!\n");
                    break;
                }
                printf("Nod intrare: ");
                while (scanf("%d", &sursa) != 1 || sursa < 1 || sursa >= n) {
                    printf("Valoare invalida [1,%d]: ", n);
                }
                printf("Nod iesire: ");
                while (scanf("%d", &destinatie) != 1 || destinatie <= sursa || destinatie >= n) {
                    printf("Valoare invalida [%d,%d]: ", sursa, n);
                }
                flux_max = ford_fulkerson(&r, sursa - 1, destinatie - 1, n);
                break;
            case 3:
                if (retea_creata)
                    afisare_rezultate(&r, flux_max, n);
                break;
            case 4:
                if (retea_creata)
                    free_retea(&r, n);
                return 0;
            default:
                printf("Valoare invalida.\n");
                break;
        }
    } while (1);

    return 0;
}