#include <stdio.h>
#include <stdlib.h>

#include "acoperire.h"
int main() {
    Graph g;
    g.inc_mat = NULL;
    g.adi_mat = NULL;
    g.adi_list = NULL;
    ElementQueue *FA1first = NULL, *FA1last = NULL, *FA2first = NULL, *FA2last = NULL;
    int cond = 0;
    int n = 0, option = 0;
    do {
        printf("1. Introducerea grafului(matricea de adiacenta ponderata)\n2. Afisarea matricei de adiacenta\n");
        printf("3. Drum Minim (Ford)\n4. Drum Minim (Bellman-Calaba)\n");
        printf("5. Salvarea in fisier (graf)\n6. Iesire\n");
        printf("Alege optiunea: ");
        scanf("%d", &option);
        switch (option) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 6:

                cond = 1;
                break;
        }
    } while (!cond);

    return 0;
}