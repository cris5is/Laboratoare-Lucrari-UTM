#include <stdio.h>
#include <stdlib.h>

#include "minim.h"
int main() {
    Graph g;
    g.adi_mat = NULL;
    int cond = 0;
    int n = 0, option = 0;
    do {
        printf("1. Introducerea grafului(matricea de adiacenta ponderata)\n2. Afisarea matricei de adiacenta\n");
        printf("3. Drum Minim (Ford)\n4. Drum Minim (Bellman-Calaba)\n");
        printf("5. Iesire\n");
        printf("Alege optiunea: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Nr. de varfuri: ");
                scanf("%d", &n);
                printf("\n");
                readMat(&g, n);
                break;
            case 2:
                printf("Matricea de adiacenta ponderata:\n");
                printMat(&g, n);
                break;
            case 3:
                fordMinim(&g, n);
                break;
            case 4:
                bellman_kalabaMinim(&g, n);
                break;
            case 5:
                freeMem(&g, n);
                cond = 1;
                break;
        }
    } while (!cond);
    freeMem(&g, n);
    return 0;
}