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
    int n = 0, option = 0, k = 0, option2 = 0;
    do {
        printf("1. Introducerea grafului\n2. Afisarea grafului\n");
        printf("3. Determinarea grafului de acoperire si afisarea lui (adi_mat)\n");
        printf("4. Salvarea in fisier (graf)\n5. Iesire\n");
        printf("Alege optiunea: ");
        while (scanf("%d", &option) != 1 || option < 1 || option > 5) {
            printf("Introduceti valoarea din limitele propuse [1,5]: ");
        }
        switch (option) {
            case 1:
                printf("1. Matricea de incidenta\n");
                printf("2. Matricea de adiacenta\n");
                printf("3. Lista de adiacenta\n");
                printf("Alege optiunea: ");
                while (scanf("%d", &option2) != 1 || option2 < 1 || option2 > 3) {
                    printf("Introduceti valoarea din limitele propuse [1,3]: ");
                }
                switch (option2) {
                    case 1:
                        printf("cititi valorile dupa forma\nn k\n");
                        scanf("%d %d", &n, &k);
                        read_mat_inc(&g, n, k);
                        inc_to_list(&g, n, k);
                        break;
                    case 2:
                        printf("n=");
                        scanf("%d", &n);
                        read_mat_adi(&g, n);
                        adi_to_list(&g, n);
                        break;
                    case 3:
                        printf("n=");
                        scanf("%d", &n);
                        read_list_adi(&g, n);
                        break;
                    default:
                        printf("Patare\n");
                        break;
                }
                break;
            case 2:

                switch (option2) {
                    case 1:
                        print_inc_mat(&g, n, k);
                        break;
                    case 2:
                        print_adi_mat(&g, n);
                        break;
                    case 3:
                        print_adi_list(&g, n);
                        break;
                    default:
                        printf("Patare\n");
                        break;
                }
                break;
            case 3:
                printf("Alegeti un nod de inceput de la 1 la %d: ", n);
                int start = 0;
                while (scanf("%d", &start) != 1 || start < 1 || start > n) {
                    printf("Introduceti valoarea din limitele propuse [1,%d]: ", n);
                }
                acoperireAdiList(&g, n, &FA1first, &FA1last, &FA2first, &FA2last, start);
                break;
            case 4:

                break;
            case 5:
                cond = 1;
                break;
            default:
                printf("Patare\n");
                break;
        }
    } while (!cond);
    freeMem(&g, n, k);
    return 0;
}