#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu() {
    printf(" 1. Crearea listei in memoria dinamica.\n");
    printf(" 2. Introducerea informatiei despre elementele listei de la tastatura. \n");
    printf(" 3. Afisarea informatiei despre elementele listei la ecran. \n");
    printf(" 4. Cautarea elementului in lista. \n");
    printf(" 5. Modificarea campurilor a unui element din lista. \n");
    printf(" 6. Determinarea adresei ultimului element din lista. \n");
    printf(" 7. Determinarea lungimii listei (numarul de elemente). \n");
    printf(" 8. Interschimbarea a doua elemente indicate in lista. \n");
    printf(" 9. Sortarea listei. \n");
    printf("10. Adaugarea unui element la sfarsitul listei. \n");
    printf("11. Adaugarea unui element la inceputul listei. \n");
    printf("12. Inserarea unui element nou dupa elementul indicat al listei. \n");
    printf("13. Inserarea unui element nou inaintea elementului indicat in lista. \n");
    printf("14. Stergerea elementului indicat in lista. \n");
    printf("15. Divizarea listei in doua liste. \n");
    printf("16. Concatenarea a doua liste.\n");
    printf("17. Salvarea informatiei despre elementele listei in fisier. \n");
    printf("18. Citirea informatiei depre elementele listei din fisier. \n");
    printf("19. Eliberarea memoriei alocate pentru lista. \n");
    printf(" 0. Iesire din program.\n");
}
void alloc_list(Node** first) {
    int n = 0;
    Node *curr, *prev;
    printf("Introduceti un numar de la 1 pana la cat doriti\n");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Valoare invalida\n");
        while (getchar() != '\n');
        return;
    }
    for (int i = 0; i < n; i++) {
        curr = (Node*)calloc(1, sizeof(*curr));
        if (curr == NULL) {
            *first = NULL;
            return;
        }
        if (i == 0) {
            *first = curr;
        } else {
            prev->next = curr;
        }
        prev = curr;
    }
    curr->next = NULL;
    printf("Alocat %d celule de memorie\n", n);
}

void select_list(Node** arr, int size, Node** first, int* index) {
    if (size == 1) {
        *first = arr[0];
        *index = 0;
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d. %s [%p]\n", i + 1, arr[i]->data.denumirea, arr[i]);
    }
    printf("Alegeti lista\n");
    int choice = 0;
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > size) {
        printf("Valoare invalida\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    *first = arr[choice - 1];
    *index = choice - 1;
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

void read_list(Node* first) {
    if (first == NULL) {
        return;
    }
    Node* curr;
    curr = first;
    do {
        read_struct(&curr->data);
        curr = curr->next;
        if (curr == first)
            break;
    } while (curr != NULL);
}

void print_struct_element(Muzeu* curr) {
    printf("    Denumirea: %s\n", curr->denumirea);
    printf("    Adresa: %s\n", curr->adresa);
    printf("    Telefonul: %s\n", curr->telefonul);
    printf("    Nr. Exponate: %d\n", curr->numar_exponate);
    printf("    Pret Bilet: %.2f $\n", curr->pret_bilet);
}
void print_list(Node* first) {
    if (first == NULL) {
        printf("NULL\n");
        return;
    }
    Node* curr;
    curr = first;
    do {
        printf("[%p] to [%p]\n", curr, curr->next);
        print_struct_element(&curr->data);
        curr = curr->next;
        if (curr == first)
            break;
    } while (curr != NULL);
}

void search_node(Node* first) {
    if (first == NULL) {
        printf("Nothing to search for, the list is empty\n");
        return;
    }
    Node* curr;
    curr = first;
    char dest[100];
    printf("\nIntroduceti denumirea muzeului: ");
    fgets(dest, 100, stdin);
    dest[strcspn(dest, "\n")] = 0;
    int found = 0;
    do {
        if (strcmp(curr->data.denumirea, dest) == 0) {
            printf("\nMuzeu gasit pe adresa [%p] to [%p]: \n", curr, curr->next);
            print_struct_element(&curr->data);
            ;
            found = 1;
            break;
        }
        curr = curr->next;
    } while (curr != NULL);
    if (!found) {
        printf("\nNu s-a gasit\n");
    }
}
void modify_node_list(Node* first) {
    if (first == NULL) {
        printf("Nothing to modify, the list is empty\n");
        return;
    }
    Node* curr;
    curr = first;
    int modified = 0;
    int choice = -1;
    do {
        printf("Do you want to change this struct member de pe [%p] sau treceti  [%p]?\n", curr, curr->next);
        print_struct_element(&curr->data);
        printf("(1 => change ; 0 => go to next member)\n");
        if (scanf("%d", &choice) != 1 || choice < 0) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
            return;
        }
        while (getchar() != '\n');
        if (choice == 1) {
            read_struct(&curr->data);
            modified = 1;
        } else {
            curr = curr->next;
        }
        if (modified == 0 && curr == NULL) {
            printf("Nu ai schimbat nimic\n");
        }

    } while (curr != NULL && !modified);
}

void last_node_adress(Node* first) {
    if (first == NULL) {
        printf("Lista e goala\n");
        return;
    }
    Node* curr;
    curr = first;
    do {
        if (curr->next == NULL) {
            printf("Adresa ultimului element: %p\n", curr);
            return;
        }
        curr = curr->next;
    } while (curr != NULL);
}

int size_list(Node* first) {
    if (first == NULL) {
        return 0;
    }
    Node* curr;
    curr = first;
    int size = 0;
    do {
        curr = curr->next;
        size++;
    } while (curr != NULL);
    return size;
}

void swap(Node* one, Node* two) {
    Node temp;
    Node *next1, *next2;
    next1 = one->next;
    next2 = two->next;
    temp = *one;
    *one = *two;
    *two = temp;
    one->next = next1;
    two->next = next2;
    return;
}
void swap_selectable(Node* first) {
    if (first == NULL) {
        printf("Lista e goala\n");
        return;
    }
    Node *curr, *one, *two;
    curr = first;
    int swapped = 0;
    int choice = -1;
    do {
        printf("Doriti sa selectati nodul nr.%d de pe adresa [%p]->[%p]?\n", swapped + 1, curr, curr->next);
        print_struct_element(&curr->data);
        printf("(1 => selectare ; 0 => urmatorul nod)\n");
        if (scanf("%d", &choice) != 1 || choice < 0) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
            return;
        }
        while (getchar() != '\n');
        if (choice == 1) {
            if (swapped == 0) {
                one = curr;
                curr = first;
            } else if (swapped == 1) {
                two = curr;
                curr = first;
            }
            swapped++;
        } else {
            curr = curr->next;
        }

        if (swapped == 2 && one != two) {
            swap(one, two);
            return;
        } else if (one == two) {
            printf("E acelasi nod\n");
            return;
        }

        if (swapped != 2 && curr == NULL) {
            printf("Nu ati schimbat nimic\n");
        }

    } while (curr != NULL);
}
void sort_menu() {
    printf("\n1. Sortare dupa denumire\n");
    printf("2. Sortare dupa adresa\n");
    printf("3. Sortare dupa telefon\n");
    printf("4. Sortare dupa nr. de exponate\n");
    printf("5. Sortare dupa pret\n");
}

void sort_list(Node* first) {
    int i, k;
    Node *one, *two;

    int n;
    n = size_list(first);
    sort_menu();
    int sort_choice = 0, condition = 0;
    if (scanf("%d", &sort_choice) != 1 || sort_choice < 0 || sort_choice > 5) {
        printf("Valoare invalida\n");
        while (getchar() != '\n');
        return;
    }

    for (i = 0; i < n - 1; i++) {
        one = first;
        two = one->next;
        switch (sort_choice) {
            case 1:
                condition = strcmp(one->data.denumirea, two->data.denumirea) > 0;
                break;
            case 2:
                condition = strcmp(one->data.adresa, two->data.adresa) > 0;
                break;
            case 3:
                condition = strcmp(one->data.telefonul, two->data.telefonul) > 0;
                break;
            case 4:
                condition = one->data.numar_exponate > two->data.numar_exponate;
                break;
            case 5:
                condition = one->data.pret_bilet > two->data.pret_bilet;
                break;
        }
        for (k = 0; k < n - 1 - i; k++) {
            if (condition) {
                swap(one, two);
            }
            one = one->next;
            two = two->next;
        }
    }
}

void add_end_list(Node** first) {
    Node* new = (Node*)malloc(sizeof(Node));
    read_struct(&new->data);
    new->next = NULL;
    if (*first == NULL) {
        *first = new;
        return;
    }
    Node* curr = *first;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;
}

void add_start_list(Node** first) {
    Node* t = (Node*)calloc(1, sizeof(*t));
    if (t == NULL)
        return;
    read_struct(&t->data);
    t->next = *first;
    *first = t;
}

void add_before_list(Node** first) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (*first == NULL) {
        read_struct(&new->data);
        *first = new;
        new->next = NULL;
        return;
    }

    int choice = 0;
    Node *curr = *first, *prev = *first;

    do {
        printf("Vreti sa inserati un nod inaintea acestuia de pe adresa [%p]?\n", curr);
        print_struct_element(&curr->data);
        printf("(1 => selectare ; 0 => urmatorul nod)\n");
        if (scanf("%d", &choice) != 1 || choice < 0) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
            return;
        }
        while (getchar() != '\n');
        if (choice == 1) {
            read_struct(&new->data);
        } else {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            printf("Nu ai inserat nimic nimic\n");
            free(new);
        }
    } while (choice == 0 && curr != NULL);
    if (choice != 1)
        return;
    if (*first == curr) {
        new->next = *first;
        *first = new;
        return;
    }

    new->next = prev->next;
    prev->next = new;
}
void add_after_list(Node** first) {
    Node* new = (Node*)malloc(sizeof(Node));
    if (*first == NULL) {
        read_struct(&new->data);
        *first = new;
        new->next = NULL;
        return;
    }
    int choice = 0;
    Node* curr = *first;
    do {
        printf("Vreti sa inserati un nod dupa acesta de pe adresa [%p]?\n", curr);
        print_struct_element(&curr->data);
        printf("(1 => selectare ; 0 => urmatorul nod)\n");
        if (scanf("%d", &choice) != 1 || choice < 0) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
            return;
        }
        while (getchar() != '\n');
        if (choice == 1) {
            read_struct(&new->data);
        } else {
            curr = curr->next;
        }
        if (curr == NULL) {
            printf("Nu ai inserat nimic\n");
            free(new);
        }
    } while (choice == 0 && curr != NULL);
    if (choice != 1)
        return;

    new->next = curr->next;
    curr->next = new;
}

void delete(Node** first) {
    if (*first == NULL) {
        printf("Nu sunt noduri de sters\n");
        return;
    }
    int choice = 0;
    Node *curr = *first, *prev = *first;
    do {
        printf("Vreti sa stergeti nodul de pe adresa [%p]?\n", curr);
        print_struct_element(&curr->data);
        printf("(1 => selectare ; 0 => urmatorul nod)\n");
        if (scanf("%d", &choice) != 1 || choice < 0) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
            return;
        }
        while (getchar() != '\n');
        if (choice == 1) {
            if (curr == *first) {
                *first = curr->next;
                free(curr);
            } else {
                prev->next = curr->next;
                free(curr);
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) {
            printf("Nu ai ales nimic de sters\n");
        }
    } while (choice == 0 && curr != NULL);
}

Node** split_list(Node** arr, int* size, Node* first) {
    if (first == NULL) {
        printf("Nu sunt noduri deajuns\n");
        return arr;
    }
    if (first->next == NULL) {
        printf("Nu sunt noduri deajuns\n");
        return arr;
    }
    Node *curr = first, *after = NULL;
    int split = 0, choice = 0;
    do {
        printf(
            "Vreti sa impartiti lista in 2 de la adresa [%p] pana la adresa [%p]?\nLista urmatoare "
            "va incepe de la [%p].\n",
            first,
            curr,
            curr->next);
        print_struct_element(&curr->next->data);
        printf("(1 => selectare ; 0 => urmatorul nod)\n");
        if (scanf("%d", &choice) != 1 || choice < 0) {
            printf("Valoare invalida\n");
            while (getchar() != '\n');
            return arr;
        }
        while (getchar() != '\n');
        if (choice == 1) {
            after = curr->next;
            curr->next = NULL;
            split = 1;
        } else {
            curr = curr->next;
        }

    } while (curr != NULL && !split);

    int new_size = *size + 1;
    arr = (Node**)realloc(arr, new_size * sizeof(Node*));
    arr[new_size - 1] = after;
    *size = new_size;
    return arr;
}
void print_heads(Node** arr, int size) {
    for (int i = 0; i < size; i++) printf("%d. %s [%p] \n", i + 1, arr[i], arr[i]->data.denumirea);
}

Node** join_list(Node** arr, int* size, int one, int two) {
    if (one == two)
        return arr;

    Node* curr = arr[one];
    while (curr->next != NULL) curr = curr->next;
    curr->next = arr[two];
    for (int i = two; i < (*size) - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    arr = (Node**)realloc(arr, (*size) * sizeof(Node*));
    return arr;
}

void write_info(Node* first) {
    if (first == NULL) {
        printf("nothing to save\n");
        return;
    }
    Node* curr = first;
    FILE* fptr = fopen("log.txt", "w");

    if (fptr == NULL) {
        printf("eroare ceva\n");
        return;
    }
    while (curr != NULL) {
        fprintf(fptr, "%s\n", curr->data.denumirea);
        fprintf(fptr, "%s\n", curr->data.adresa);
        fprintf(fptr, "%s\n", curr->data.telefonul);
        fprintf(fptr, "%d\n", curr->data.numar_exponate);
        fprintf(fptr, "%.2f", curr->data.pret_bilet);
        if (curr->next != NULL) {
            fprintf(fptr, "\n");
        }
        curr = curr->next;
    }
    fclose(fptr);
}
void read_info(Node** first) {
    char filename[100];
    printf("\nNumele\\locatia fisierului:\n");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("eroare ceva\n");
        return;
    }
    Node *curr, *prev;
    int count = 0;
    while (!feof(fptr)) {
        if (count % 5 == 0) {
            curr = (Node*)calloc(1, sizeof(*curr));
            if (curr == NULL) {
                *first = NULL;
                fclose(fptr);
                return;
            }
            if (count == 0) {
                *first = curr;
            } else {
                prev->next = curr;
            }
            prev = curr;
        }
        count++;
        int c;
        while ((c = fgetc(fptr)) != '\n' && c != EOF);
    }
    curr->next = NULL;
    curr = *first;
    fseek(fptr, 0, SEEK_SET);
    for (int i = 0; i < count / 5; i++) {
        fgets(curr->data.denumirea, 100, fptr);
        curr->data.denumirea[strcspn(curr->data.denumirea, "\n")] = 0;
        fgets(curr->data.adresa, 100, fptr);
        curr->data.adresa[strcspn(curr->data.adresa, "\n")] = 0;
        fgets(curr->data.telefonul, 10, fptr);
        curr->data.telefonul[strcspn(curr->data.telefonul, "\n")] = 0;
        fscanf(fptr, "%d", &curr->data.numar_exponate);
        fgetc(fptr);
        fscanf(fptr, "%f", &curr->data.pret_bilet);
        fgetc(fptr);
        curr = curr->next;
    }
    fclose(fptr);
}
void free_list(Node** first) {
    Node *curr, *prev;
    curr = *first;
    while (curr) {
        prev = curr;
        curr = curr->next;
        free(prev);
        if (curr == *first)
            break;
    }
    *first = NULL;
}
