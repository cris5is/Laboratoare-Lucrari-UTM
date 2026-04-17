#include <stdio.h>

#include "binary_tree.h"
int main() {
    Node* root = NULL;
    ElementQueue *first = NULL, *last = NULL;
    ElementStack* top = NULL;
    int option = -1, method = -1;
    while (option != 0) {
        Menu();
        printf("Alegeti optiunea: ");
        if (scanf("%d", &option) != 1) {
            printf("Optiune invalida\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (option) {
            case 1:
                printf("Selectati metoda:\n1. Prin coada\n2. Prin stiva\n");
                if (scanf("%d", &method) != 1 || method < 1 || method > 2) {
                    printf("Alegeti o optiune valabila\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (method == 1)
                    createQueue(&first, &last, &root);
                else
                    createStack(&top, &root);
                break;
            case 2:
                printf("Selectati metoda:\n1. Prin coada\n2. Prin stiva\n");
                if (scanf("%d", &method) != 1 || method < 1 || method > 2) {
                    printf("Alegeti o optiune valabila\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (method == 1)
                    showQueue(&first, &last, root);
                else
                    showStack(&top, root);
                break;
            case 3:
                printf("Selectati metoda:\n1. Prin coada\n2. Prin stiva\n");
                if (scanf("%d", &method) != 1 || method < 1 || method > 2) {
                    printf("Alegeti o optiune valabila\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (method == 1)
                    searchQueue(&first, &last, root);
                else
                    searchStack(&top, root);
                break;
            case 4:
                printf("Selectati metoda:\n1. Prin coada\n2. Prin stiva\n");
                if (scanf("%d", &method) != 1 || method < 1 || method > 2) {
                    printf("Alegeti o optiune valabila\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (method == 1)
                    modifyQueue(&first, &last, root);
                else
                    modifyStack(&top, root);
                break;
            case 5:
                printf("Selectati metoda:\n1. Prin coada\n2. Prin stiva\n");
                if (scanf("%d", &method) != 1 || method < 1 || method > 2) {
                    printf("Alegeti o optiune valabila\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (method == 1)
                    printf("Size: %d\n", sizeQueue(&first, &last, root));
                else
                    printf("Size: %d\n", sizeStack(&top, root));
                break;
            case 6:
                printf("Selectati metoda:\n1. Prin coada\n2. Prin stiva\n");
                if (scanf("%d", &method) != 1 || method < 1 || method > 2) {
                    printf("Alegeti o optiune valabila\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (method == 1)
                    heightQueue(&first, &last, root);
                else
                    heightStack(&top, root);
                break;
            case 7:
                printf("Selectati metoda:\n1. Prin coada\n2. Prin stiva\n");
                if (scanf("%d", &method) != 1 || method < 1 || method > 2) {
                    printf("Alegeti o optiune valabila\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                if (method == 1)
                    freeQueue(&first, &last, &root);
                else
                    freeStack(&top, &root);
                break;
            default:
                if (option != 0)
                    printf("Optiune invalida\n");
        }
    }
    return 0;
}