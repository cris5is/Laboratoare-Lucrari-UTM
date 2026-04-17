#include "binary_rec_tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu() {
    printf("1. Crearea nodurilor arborelui binar oarecare in memoria\n");
    printf("   dinamica si introducerea informatiei despre nodurile\n");
    printf("   arborelui de la tastatura in mod interactiv.\n");
    printf("2. Afisarea informatiei despre nodurile arborelui la ecran.\n");
    printf("3. Cautarea nodului in arbore.\n");
    printf("4. Modificarea informatiei unui nod din arbore.\n");
    printf("5. Determinarea numarului de noduri.\n");
    printf("6. Determinarea inaltimii arborelui.\n");
    printf("7. Eliberarea memoriei alocate pentru arbore.\n");
    printf("0. Iesirea din program.\n");
}
void read_struct(Muzeu* curr) {
    printf("  Denumirea: ");
    fgets(curr->denumirea, 100, stdin);
    curr->denumirea[strcspn(curr->denumirea, "\n")] = 0;
    printf("  Adresa: ");
    fgets(curr->adresa, 100, stdin);
    curr->adresa[strcspn(curr->adresa, "\n")] = 0;
    printf("  Telefonul: ");
    fgets(curr->telefonul, 10, stdin);
    curr->telefonul[strcspn(curr->telefonul, "\n")] = 0;
    printf("  Numarul de exponate: ");
    scanf("%d", &curr->numar_exponate);
    while (getchar() != '\n');
    printf("  Pretul biletului: ");
    scanf("%f", &curr->pret_bilet);
    while (getchar() != '\n');
}
void printStruct(Muzeu* curr) {
    printf("    Denumirea: %s\n", curr->denumirea);
    printf("    Adresa: %s\n", curr->adresa);
    printf("    Telefonul: %s\n", curr->telefonul);
    printf("    Nr. Exponate: %d\n", curr->numar_exponate);
    printf("    Pret Bilet: %.2f $\n", curr->pret_bilet);
}

void createNode(Node** root) {
    int option = -1;
    printf("Doriti sa creati nodul? (0-nu/1-da): \n");
    while (scanf("%d", &option) != 1 || option < 0 || option > 1) {
        printf("Valoare invalida\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    if (option == 0) {
        *root = NULL;
        return;
    }
    *root = (Node*)malloc(sizeof(Node));
    if (*root == NULL) {
        printf("Eroare la alocarea memoriei\n");
        return;
    }
    read_struct(&(*root)->data);
    printf("Copilul stang al nodului cu numele %s: \n", (*root)->data.denumirea);
    createNode(&(*root)->left);
    printf("Copilul drept al nodului cu numele %s: \n", (*root)->data.denumirea);
    createNode(&(*root)->right);
}

void showTreeRSD(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("Node: %p Left: %p Right: %p\n", root, root->left, root->right);
    printStruct(&root->data);
    showTreeRSD(root->left);
    showTreeRSD(root->right);
}
void showTreeRDS(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("Node: %p Left: %p Right: %p\n", root, root->left, root->right);
    printStruct(&root->data);
    showTreeRDS(root->right);
    showTreeRDS(root->left);
}
void showTreeSRD(Node* root) {
    if (root == NULL) {
        return;
    }
    showTreeSRD(root->left);
    printf("Node: %p Left: %p Right: %p\n", root, root->left, root->right);
    printStruct(&root->data);
    showTreeSRD(root->right);
}
void showTreeDRS(Node* root) {
    if (root == NULL) {
        return;
    }
    showTreeDRS(root->right);
    printf("Node: %p Left: %p Right: %p\n", root, root->left, root->right);
    printStruct(&root->data);
    showTreeDRS(root->left);
}
void showTreeSDR(Node* root) {
    if (root == NULL) {
        return;
    }
    showTreeSDR(root->left);
    showTreeSDR(root->right);
    printf("Node: %p Left: %p Right: %p\n", root, root->left, root->right);
    printStruct(&root->data);
}
void showTreeDSR(Node* root) {
    if (root == NULL) {
        return;
    }
    showTreeDSR(root->right);
    showTreeDSR(root->left);
    printf("Node: %p Left: %p Right: %p\n", root, root->left, root->right);
    printStruct(&root->data);
}
void searchTree(Node* root, char* target) {
    if (root == NULL) {
        return;
    }
    if (strcmp(root->data.denumirea, target) == 0) {
        printf("Node : %p Left : %p Right : %p\n", root, root->left, root->right);
        printStruct(&root->data);
        return;
    } else {
        if (root->left) {
            searchTree(root->left, target);
        }
        if (root->right) {
            searchTree(root->right, target);
        }
    }
}
void modifyNode(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("Node : %p Left : %p Right : %p\n", root, root->left, root->right);
    printStruct(&root->data);
    printf("Modificati informatia acestui nod? (0/1): ");
    int option = -1, direction = -1;
    while (scanf("%d", &option) != 1 || option < 0 || option > 1) {
        printf("Valoare invalida\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    if (option == 1) {
        read_struct(&root->data);
        return;
    } else {
        if (root->left == NULL && root->right == NULL) {
            return;
        }
        if (root->left != NULL && root->right == NULL) {
            modifyNode(root->left);
        } else if (root->right != NULL && root->left == NULL) {
            modifyNode(root->right);
        } else {
            printf("La care nod vreti sa treceti? (0-[%s]/1-[%s]): ", root->left->data.denumirea, root->right->data.denumirea);
            while (scanf("%d", &direction) != 1 || direction < 0 || direction > 1) {
                printf("Valoare invalida\n");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
            if (direction == 0)
                modifyNode(root->left);
            else
                modifyNode(root->right);
        }
    }
}

int sizeTree(Node* root) {
    int n;
    if (root == NULL)
        return 0;
    n = 1 + sizeTree(root->left) + sizeTree(root->right);
    return n;
}
int heightTree(Node* root) {
    int left, right;
    if (root == NULL)
        return 0;
    else {
        left = 1 + heightTree(root->left);
        right = 1 + heightTree(root->right);
    }
    if (left >= right)
        return left;
    return right;
}
void freeTree(Node** root) {
    freeTree(&(*root)->left);
    freeTree(&(*root)->right);
    free(*root);
    *root = NULL;
}