#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Muzeu {
    char denumirea[100];
    char adresa[100];
    char telefonul[10];
    int numar_exponate;
    float pret_bilet;
} Muzeu;

void menu() {
    printf("1. Alocarea dinamica a memoriei pentru tablou.\n");
    printf("2. Introducerea elementelor tabloului de la tastatura.\n");
    printf("3. Afisarea elementelor tabloului la ecran.\n");
    printf("4. Adaugarea unui element nou la sfarsit.\n");
    printf("5. Modificarea elementului tabloului.\n");
    printf("6. Cautarea elementului tabloului.\n");
    printf("7. Sortarea tabloului (dupa denumire).\n");
    printf("8. Eliminarea elementului indicat din tablou.\n");
    printf("9. Eliberarea memoriei alocate pentru tablou.\n");
    printf("0. Iesire din program.\n");
}

Muzeu* aloc_mem_struct(int* size) {
    int n = 0;
    printf("Introduceti un numar de la 1 la cat doriti\n");
    if ((scanf("%d", &n) != 1) && (n < 0)) {
        printf("Citeste numar\n");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    Muzeu* tablou = (Muzeu*) malloc(n * sizeof(Muzeu));
    *size = n;
    return tablou;
}

void read_struct(Muzeu* curr) {
    printf("Denumirea: ");
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

void insert_struct(Muzeu* curr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Introduceti datele pentru...\nMuzeul %d:\n", i + 1);
        read_struct(&curr[i]);
    }
}

void print_struct_by_i(Muzeu* curr, int i) {
    printf("Muzeul %d\n", i);
    printf("    Denumirea: %s\n", curr->denumirea);
    printf("    Adresa: %s\n", curr->adresa);
    printf("    Telefonul: %s\n", curr->telefonul);
    printf("    Nr. Exponate: %d\n", curr->numar_exponate);
    printf("    Pret Bilet: %.2f $\n", curr->pret_bilet);
}

void print_struct(Muzeu* curr, int size) {
    for (int i = 0; i < size; i++) {
        print_struct_by_i(&curr[i], i + 1);
    }
}

Muzeu* add_end_struct(Muzeu* curr, int* size) {
    int new_size = *size + 1;
    Muzeu* temp = (Muzeu*) realloc(curr, new_size * sizeof(Muzeu));
    curr = temp;
    read_struct(&curr[*size]);
    *size = new_size;
    return curr;
}

Muzeu* modify_obj_struct(Muzeu* curr, int size) {
    int n = 0;
    printf("Alege de la 1 la %d: ", size);
    if (scanf("%d", &n) != 1 || (!(n >= 1 && n <= size))) {
        printf("Eroare, alege numar normal de la 1 la %d\n", size);
        while (getchar() != '\n');
    };
    while (getchar() != '\n');
    read_struct(&curr[n - 1]);
}

void search_obj(Muzeu* curr, int size) {
    char dest[100];
    printf("Introduceti denumirea muzeului: ");
    fgets(dest, 100, stdin);
    dest[strcspn(dest, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(curr[i].denumirea, dest) == 0) {
            printf("\nMuzeu gasit la [%d]: \n", i + 1);
            print_struct_by_i(&curr[i], i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nNu s-a gasit\n");
    }
}

int diff_struct(const void* a, const void* b) {
    const Muzeu* A = (const Muzeu*) a;
    const Muzeu* B = (const Muzeu*) b;
    return strcmp(A->denumirea, B->denumirea);
}

void sort_struct(Muzeu* curr, int size) {
    qsort(curr, size, sizeof(Muzeu), diff_struct);
    print_struct(curr, size);
}

Muzeu* delete_obj(Muzeu* curr, int* size) {
    int choice;
    printf("Alege un numar de la 1 la %d:", *size);
    if ((scanf("%d", &choice) != 1) && (choice <= *size && choice >= 1)) {
        printf("ce cu tine atata");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    for (int i = choice - 1; i < *size - 1; i++) {
        curr[i] = curr[i + 1];
    }
    int new_size = *size - 1;
    Muzeu* temp = NULL;
    if (new_size > 0) {
        temp = (Muzeu*) realloc(curr, new_size * sizeof(Muzeu));
    } else {
        free(curr);
        curr = NULL;
    }
    *size = new_size;
    return (temp != NULL || *size == 0) ? temp : curr;
}

Muzeu* free_struct(Muzeu* curr, int* size) {
    free(curr);
    curr = NULL;
    *size = 0;
    return curr;
}

int main() {
    Muzeu* arr_muzee = NULL;
    int size = 0;
    int option;

    do {
        menu();
        if (scanf("%d", &option) != 1) {
            printf("Optiune invalida\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        switch (option) {
            case 1:
                arr_muzee = aloc_mem_struct(&size);
                break;
            case 2:
                insert_struct(arr_muzee, size);
                break;
            case 3:
                print_struct(arr_muzee, size);
                break;
            case 4:
                arr_muzee = add_end_struct(arr_muzee, &size);
                break;
            case 5:
                modify_obj_struct(arr_muzee, size);
                break;
            case 6:
                search_obj(arr_muzee, size);
                break;
            case 7:
                sort_struct(arr_muzee, size);
                break;
            case 8:
                arr_muzee = delete_obj(arr_muzee, &size);
                break;
            case 9:
                arr_muzee = free_struct(arr_muzee, &size);
                break;
            case 0:
                break;
            default:
                printf("Alegeti o optiune valabila: \n");
        }
    } while (option != 0);

    arr_muzee = free_struct(arr_muzee, &size);

    return 0;
}
