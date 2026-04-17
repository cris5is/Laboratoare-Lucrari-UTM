#include "binary_tree.h"

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

void addQueue(ElementQueue** first, ElementQueue** last, Node* newNode) {
    ElementQueue* temp;
    temp = (ElementQueue*)calloc(1, sizeof(*temp));
    if (temp == NULL)
        return;
    temp->address = newNode;
    temp->next = NULL;
    if (*first == NULL)
        *first = temp;
    else {
        (*last)->next = temp;
    }
    *last = temp;
}

Node* delQueue(ElementQueue** first, ElementQueue** last) {
    ElementQueue* temp;
    Node* result;
    temp = *first;
    result = temp->address;
    if (temp == *last) {
        *first = *last = NULL;
    } else {
        *first = temp->next;
    }
    free(temp);
    return result;
}

void push(ElementStack** top, Node* newNode) {
    ElementStack* temp;
    temp = (ElementStack*)calloc(1, sizeof(*temp));
    if (temp == NULL)
        return;
    temp->address = newNode;
    temp->next = *top;
    *top = temp;
}

Node* pop(ElementStack** top) {
    ElementStack* temp;
    Node* result;
    temp = *top;
    result = temp->address;
    *top = temp->next;
    free(temp);
    return result;
}

void createQueue(ElementQueue** first, ElementQueue** last, Node** root) {
    Node *curr, *child;
    *root = NULL;
    *first = *last = NULL;
    int option;
    printf("Doriti sa creati arborele binar (radacina)? (0,1): ");
    if (scanf("%d", &option) != 1 || option < 0 || option > 1) {
        printf("Valoare invalida\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    if (option == 0) {
        printf("Arborele nu a fost creat.\n");
        return;
    }
    curr = (Node*)malloc(sizeof(*curr));
    if (curr == NULL) {
        printf("Nu s-a putut aloca memorie pentru radacina.\n");
        return;
    }
    read_struct(&curr->data);
    addQueue(first, last, curr);
    if (*last == NULL) {
        printf("Nu s-a putut adăuga nodul la coada.\n");
        return;
    }
    *root = curr;
    while (*first) {
        curr = delQueue(first, last);
        printf("Doriti sa creati copilul stang al nodului cu numele %s ? (0,1): ", curr->data.denumirea);
        if (scanf("%d", &option) != 1 || option < 0 || option > 1) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        if (option == 0)
            curr->left = NULL;
        else {
            child = (Node*)malloc(sizeof(*child));
            if (child == NULL) {
                printf("Eroare la alocarea memoriei pentru copil.\n");
                return;
            }
            child->left = child->right = NULL;
            curr->left = child;
            read_struct(&child->data);
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        }
        printf("Doriti sa creati copilul drept al nodului cu numele %s ? (0,1): ", curr->data.denumirea);
        if (scanf("%d", &option) != 1 || option < 0 || option > 1) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        if (option == 0)
            curr->right = NULL;
        else {
            child = (Node*)malloc(sizeof(*child));
            if (child == NULL) {
                printf("Eroare la alocarea memoriei pentru copil.\n");
                return;
            }
            child->left = child->right = NULL;
            curr->right = child;
            read_struct(&child->data);
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        }
    }
}

void createStack(ElementStack** top, Node** root) {
    Node *curr, *child;
    *root = NULL;
    *top = NULL;
    int option;
    printf("Doriti sa creati arborele binar (radacina)? (0,1): ");
    if (scanf("%d", &option) != 1 || option < 0 || option > 1) {
        printf("Valoare invalida\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    if (option == 0) {
        printf("Arborele nu a fost creat.\n");
        return;
    }
    curr = (Node*)malloc(sizeof(*curr));
    if (curr == NULL) {
        printf("Nu s-a putut aloca memorie pentru radacina.\n");
        return;
    }
    read_struct(&curr->data);
    push(top, curr);
    if (*top == NULL) {
        printf("Nu s-a putut adauga nodul la stiva.\n");
        return;
    }
    *root = curr;
    while (*top) {
        curr = pop(top);
        printf("Doriti sa creati copilul drept a nodului cu numele %s ? (0,1): ", curr->data.denumirea);
        if (scanf("%d", &option) != 1 || option < 0 || option > 1) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        if (option == 0)
            curr->right = NULL;
        else {
            child = (Node*)malloc(sizeof(*child));
            if (child == NULL) {
                printf("Nu s-a putut aloca memorie pentru copil.\n");
                return;
            }
            curr->right = child;
            read_struct(&child->data);
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adăuga copilul la stiva.\n");
                return;
            }
        }
        printf("Doriti sa creati copilul stang al nodului cu numele %s ? (0,1): ", curr->data.denumirea);
        if (scanf("%d", &option) != 1 || option < 0 || option > 1) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        if (option == 0)
            curr->left = NULL;
        else {
            child = (Node*)malloc(sizeof(*child));
            if (child == NULL) {
                printf("Nu s-a putut aloca memorie pentru copil.\n");
                return;
            }
            curr->left = child;
            read_struct(&child->data);
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return;
            }
        }
    }
}

void printStruct(Muzeu* curr) {
    printf("    Denumirea: %s\n", curr->denumirea);
    printf("    Adresa: %s\n", curr->adresa);
    printf("    Telefonul: %s\n", curr->telefonul);
    printf("    Nr. Exponate: %d\n", curr->numar_exponate);
    printf("    Pret Bilet: %.2f $\n", curr->pret_bilet);
}

void showQueue(ElementQueue** first, ElementQueue** last, Node* root) {
    Node *curr, *child;
    *first = *last = NULL;
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    addQueue(first, last, root);
    if (*last == NULL) {
        printf("Nu s-a putut adauga radacina la coada.\n");
        return;
    }
    printf("Nodurile Arborelui:\n");
    while (*first) {
        curr = delQueue(first, last);
        printf("Node: %p Left: %p Right: %p\n", curr, curr->left, curr->right);
        printStruct(&curr->data);
        child = curr->left;
        if (child) {
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        }
        child = curr->right;
        if (child) {
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        }
    }
}
void showStack(ElementStack** top, Node* root) {
    Node *curr, *child;
    *top = NULL;
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    push(top, root);
    if (*top == NULL) {
        printf("Nu s-a putut adauga radacina la stiva.\n");
        return;
    }
    printf("Nodurile Arborelui:\n");
    while (*top) {
        curr = pop(top);
        printf("Node: %p Left: %p Right: %p\n", curr, curr->left, curr->right);
        printStruct(&curr->data);
        child = curr->right;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return;
            }
        }
        child = curr->left;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return;
            }
        }
    }
}

void searchQueue(ElementQueue** first, ElementQueue** last, Node* root) {
    Node *curr, *child;
    *first = *last = NULL;
    addQueue(first, last, root);
    if (*last == NULL) {
        printf("Eroare la adaugarea radacinei in coada.\n");
        return;
    }
    char dest[100];
    printf("\nIntroduceti denumirea muzeului: ");
    fgets(dest, 100, stdin);
    dest[strcspn(dest, "\n")] = 0;
    while (*first) {
        curr = delQueue(first, last);
        if (strcmp(curr->data.denumirea, dest) == 0) {
            printf("Node : %p Left : %p Right : %p\n", curr, curr->left, curr->right);
            printStruct(&curr->data);
            return;
        }
        child = curr->left;
        if (child) {
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        }
        child = curr->right;
        if (child) {
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        }
    }
    printf("Nu s-a gasit nodul necesar.\n");
}
void searchStack(ElementStack** top, Node* root) {
    Node *curr, *child;
    *top = NULL;
    push(top, root);
    if (*top == NULL) {
        printf("Nu s-a putut adauga radacina la stiva.\n");
        return;
    }
    char dest[100];
    printf("\nIntroduceti denumirea muzeului: ");
    fgets(dest, 100, stdin);
    dest[strcspn(dest, "\n")] = 0;
    while (*top) {
        curr = pop(top);
        if (strcmp(curr->data.denumirea, dest) == 0) {
            printf("Node : %p Left : %p Right : %p\n", curr, curr->left, curr->right);
            printStruct(&curr->data);
            return;
        }
        child = curr->right;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return;
            }
        }
        child = curr->left;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return;
            }
        }
    }
    printf("Nu s-a gasit nodul necesar.\n");
}

void modifyQueue(ElementQueue** first, ElementQueue** last, Node* root) {
    Node *curr, *child;
    *first = *last = NULL;
    int option = -1, where = -1;
    addQueue(first, last, root);
    if (*last == NULL) {
        printf("Eroare la adaugarea radacinei in coada.\n");
        return;
    }
    while (*first) {
        curr = delQueue(first, last);
        printf("Doriti sa modificati nodul cu numele %s ? (0,1): ", curr->data.denumirea);
        if (scanf("%d", &option) != 1 || option < 0 || option > 1) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        if (option == 1) {
            read_struct(&curr->data);
        } else if (option == 0) {
            printf("La care nod vreti sa treceti? (0 - [%s], 1 - [%s]): ", curr->left->data.denumirea, curr->right->data.denumirea);
            if (scanf("%d", &where) != 1 || where < 0 || where > 1) {
                printf("Valoare invalida\n");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
            if (where == 0)
                child = curr->left;
            else
                child = curr->right;
            if (child) {
                addQueue(first, last, child);
                if (*last == NULL) {
                    printf("Nu s-a putut adauga copilul la coada.\n");
                    return;
                }
            }
        }
    }
}

void modifyStack(ElementStack** top, Node* root) {
    Node *curr, *child;
    *top = NULL;
    int option = -1, where = -1;
    push(top, root);
    if (*top == NULL) {
        printf("Eroare la adaugarea radacinei in stiva.\n");
        return;
    }
    while (*top) {
        curr = pop(top);
        printf("Doriti sa modificati nodul cu numele %s ? (0,1): ", curr->data.denumirea);
        if (scanf("%d", &option) != 1 || option < 0 || option > 1) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');
        if (option == 1) {
            read_struct(&curr->data);
            return;
        } else if (option == 0) {
            printf("La care nod vreti sa treceti? (0 - [%s], 1 - [%s]): ", curr->left->data.denumirea, curr->right->data.denumirea);
            if (scanf("%d", &where) != 1 || where < 0 || where > 1) {
                printf("Valoare invalida\n");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
            if (where == 0)
                child = curr->left;
            else
                child = curr->right;
            if (child) {
                push(top, child);
                if (*top == NULL) {
                    printf("Nu s-a putut adauga copilul la stiva.\n");
                    return;
                }
            }
        }
    }
}

int sizeQueue(ElementQueue** first, ElementQueue** last, Node* root) {
    Node *curr, *child;
    int n = 0;
    *first = *last = NULL;
    addQueue(first, last, root);
    if (*last == NULL) {
        printf("Nu s-a putut adauga radacina la coada.\n");
        return 0;
    }
    while (*first) {
        curr = delQueue(first, last);
        n++;
        child = curr->left;
        if (child) {
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return 0;
            }
        }
        child = curr->right;
        if (child) {
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return 0;
            }
        }
    }
    return n;
}
int sizeStack(ElementStack** top, Node* root) {
    Node *curr, *child;
    int n = 0;
    *top = NULL;
    push(top, root);
    if (*top == NULL) {
        printf("Nu s-a putut adauga radacina la stiva.\n");
        return 0;
    }
    while (*top) {
        curr = pop(top);
        n++;
        child = curr->right;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return 0;
            }
        }
        child = curr->left;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return 0;
            }
        }
    }
    return n;
}

void heightQueue(ElementQueue** first, ElementQueue** last, Node* root) {
    int n, presentCounter = 0, absentCounter = 0, final, height;
    Node *curr, *child;
    *first = *last = NULL;
    height = 0;
    curr = root;
    if (curr == NULL) {
        printf("Radacina == NULL => Inaltimea arborelui : 0\n");
        return;
    }
    n = 1;
    addQueue(first, last, curr);
    if (*last == NULL) {
        {
            printf("Nu s-a putut adauga radacina la coada.\n");
            return;
        }
    }
    while (*first) {
        curr = delQueue(first, last);
        child = curr->left;
        if (child) {
            presentCounter++;
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        } else {
            absentCounter++;
        }
        child = curr->right;
        if (child) {
            presentCounter++;
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        } else {
            absentCounter++;
        }
        final = 2 * n;
        if (final == presentCounter + absentCounter) {
            height = height + 1;
            n = presentCounter;
            presentCounter = 0;
            absentCounter = 0;
        }
    }
    printf("Inaltimea arborelui: %d\n", height);
}
void heightStack(ElementStack** top, Node* root) {
    int maxH = 0, currentH = 0, stackIndex = 0;
    Node *curr, *child;
    *top = NULL;
    curr = root;
    if (curr == NULL) {
        printf("Radacina == NULL => Inaltimea arborelui : 0\n");
        return;
    }
    int* levels = (int*)malloc(sizeStack(top, root) + 1 * sizeof(int));
    if (levels == NULL) {
        printf("Eroare la alocarea memoriei pentru nivele.\n");
        return;
    }
    push(top, root);
    levels[stackIndex] = 1;
    while (*top != NULL) {
        curr = pop(top);
        currentH = levels[stackIndex--];
        if (currentH > maxH)
            maxH = currentH;
        child = curr->right;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                free(levels);
                return;
            }
            levels[++stackIndex] = currentH + 1;
        }
        child = curr->left;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                free(levels);
                return;
            }
            levels[++stackIndex] = currentH + 1;
        }
    }
    printf("Inaltimea arborelui: %d\n", maxH);
    free(levels);
}

void freeQueue(ElementQueue** first, ElementQueue** last, Node** root) {
    Node *curr, *child;
    *first = *last = NULL;
    addQueue(first, last, *root);
    if (*last == NULL) {
        printf("Nu s-a putut adauga radacina la coada.\n");
        return;
    }
    while (*first) {
        curr = delQueue(first, last);
        child = curr->left;
        if (child) {
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        }
        child = curr->right;
        if (child) {
            addQueue(first, last, child);
            if (*last == NULL) {
                printf("Nu s-a putut adauga copilul la coada.\n");
                return;
            }
        }
        free(curr);
    }
    *root = NULL;
    *first = NULL;
    *last = NULL;
}
void freeStack(ElementStack** top, Node** root) {
    Node *curr, *child;
    ElementStack* temp;
    *top = NULL;
    push(top, *root);
    if (*top == NULL) {
        printf("Nu s-a putut adauga radacina la stiva.\n");
        return;
    }
    while (*top) {
        curr = pop(top);
        push(&temp, curr);
        child = curr->left;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return;
            }
        }
        child = curr->right;
        if (child) {
            push(top, child);
            if (*top == NULL) {
                printf("Nu s-a putut adauga copilul la stiva.\n");
                return;
            }
        }
        while (temp) {
            curr = pop(&temp);
            free(curr);
        }
        *root = NULL;
        *top = NULL;
    }
}
