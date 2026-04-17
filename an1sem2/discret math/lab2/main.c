#include <stdio.h>
#include <stdlib.h>

#include "graph_stuff.h"

int main() {
    Graph g;
    g.adi_list = NULL;
    int cond = 0;
    ElementStack* top = NULL;
    ElementQueue *FA1first = NULL, *FA1last = NULL, *FA2first = NULL, *FA2last = NULL;
    int n = 0, needed = 0, option = 0, option2 = 0;
    do {
        printf("1. Introducerea grafului(lista de adiacenta)\n2. Afisarea listei de adiacenta\n");
        printf("3. Parcurgere in adancime\n4. Parcurgere in latime\n");
        printf("5. Salvarea in fisier\n6. Iesire\n");
        printf("Alege optiunea: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Nr. de varfuri: ");
                scanf("%d", &n);
                printf("\n");
                read_list_adi(&g, n);
                break;
            case 2:
                printf("Lista de adiacenta:\n");
                print_adi_list(&g, n);
                break;
            case 3:
                printf("1. Cautarea unui varf\n2. Parcurgere totala\nAlege optiunea: ");
                scanf("%d", &option2);
                switch (option2) {
                    case 1:
                        printf("Introdu varful cautat: ");
                        scanf("%d", &needed);
                        if (needed > 0 || needed <= n)

                            adancime(&g, n, &top, needed);
                        else
                            printf("Nu a fost gasit\n");
                        break;
                        printf("\n");
                    case 2:
                        adancime(&g, n, &top, needed);
                        break;
                    default:
                        printf("Optiune invalida!\n");
                }
                break;
            case 4:
                printf("1. Cautarea unui varf\n2. Parcurgere totala\nAlege optiunea: ");
                scanf("%d", &option2);
                switch (option2) {
                    case 1:
                        printf("Introdu varful cautat: ");
                        scanf("%d", &needed);
                        printf("\n");
                        if (needed > 0 || needed <= n) {
                            latime(&g, n, &FA1first, &FA1last, &FA2first, &FA2last, needed);
                        } else {
                            printf("Nu a fost gasit\n");
                        }
                        break;
                    case 2:
                        latime(&g, n, &FA1first, &FA1last, &FA2first, &FA2last, needed);
                        break;
                    default:
                        printf("Optiune invalida!\n");
                }
                break;
            case 5:
                writeInfo(&g, n);
                cond = 1;
                break;
            case 6:
                cond = 1;
                break;
            default:
                printf("Optiune invalida!\n");
        }
        needed = 0;
    } while (!cond);
    freeMem(&g, n);
    return 0;
}