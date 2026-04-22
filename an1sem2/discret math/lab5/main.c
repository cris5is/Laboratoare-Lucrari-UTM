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
                scanf("%d", &n);
                init_retea(&r, n);
                citire_retea(&r, NULL);
                retea_creata = 1;
                break;
            case 2:
                if (!retea_creata) {
                    printf("Creati reteaua intai!\n");
                    break;
                }
                printf("Nod intrare (a): ");
                scanf("%d", &sursa);
                printf("Nod iesire (b): ");
                scanf("%d", &destinatie);
                flux_max = ford_fulkerson(&r, sursa - 1, destinatie - 1);
                printf("Calcul finalizat.\n");
                break;
            case 3:
                if (retea_creata)
                    afisare_rezultate(&r, flux_max);
                break;
            case 4:
                if (retea_creata)
                    free_retea(&r);
                return 0;
        }
    } while (1);

    return 0;
}