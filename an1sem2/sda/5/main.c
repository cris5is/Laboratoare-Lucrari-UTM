#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_rec_tree.h"
int main() {
    Node* root = NULL;
    int option = -1, showMethod = -1;
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
                createNode(&root);
                break;
            case 2:
                printf("Selectati metoda:\n1. Root, Left, Right\n2. Root, Right, Left\n");
                printf("3. Left, Root, Right\n4. Right, Root, Left\n");
                printf("5. Left, Right, Root\n6. Right,Left, Root\n");
                if (scanf("%d", &showMethod) != 1 || showMethod < 1 || showMethod > 6) {
                    printf("Alegeti o optiune valabila\n");
                    while (getchar() != '\n');
                    continue;
                }
                while (getchar() != '\n');
                switch (showMethod) {
                    case 1:
                        showTreeRSD(root);
                        break;
                    case 2:
                        showTreeRDS(root);
                        break;
                    case 3:
                        showTreeSRD(root);
                        break;
                    case 4:
                        showTreeDRS(root);
                        break;
                    case 5:
                        showTreeSDR(root);
                        break;
                    case 6:
                        showTreeDSR(root);
                        break;
                }
                break;
            case 3:
                char dest[100];
                printf("\nIntroduceti denumirea muzeului: ");
                fgets(dest, 100, stdin);
                dest[strcspn(dest, "\n")] = 0;
                searchTree(root, dest);
                break;
            case 4:
                modifyNode(root);
                break;
            case 5:
                printf("Size: %d\n", sizeTree(root));
                break;
            case 6:
                printf("Height: %d\n", heightTree(root));
                break;
            case 7:
                freeTree(&root);
                root = NULL;
                break;
            default:
                if (option != 0)
                    printf("Optiune invalida\n");
        }
    }
    freeTree(&root);
    root = NULL;
    return 0;
}