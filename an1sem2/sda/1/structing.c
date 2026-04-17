#include "structing.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc -o program main.c structing.c
void menu() {
    printf(" 1. Alocarea dinamic a memoriei pentru tablou.\n");
    printf(" 2. Introducerea informatiei despre elementele tabloului de la tastatura. \n");
    printf(" 3. Afisarea informatiei despre elementele tabloului la ecran. \n");
    printf(" 4. Cautarea elementului in tablou.\n");
    printf(" 5. Modificarea campurilor a unui element din tablou\n");
    printf(" 6. Interschimbarea a doua elemente indicate din tablou\n");
    printf(" 7. Sortarea tabloului. \n");
    printf(" 8. Adaugarea unui element nou la sfarsitul tabloului\n");
    printf(" 9. Adaugarea unui element nou la inciputul tabloului.\n");
    printf("10. Inserarea unui element nou dupa elementul indicat al tabloului. \n");
    printf("11. Inserarea unui element nou inainte elementul indicat al tabloului. \n");
    printf("12. Stergerea elementului indicat al tabloului\n");
    printf("13. Salvarea informatiei despre elementele tabloului in fisier. \n");
    printf("14. Citirea informatiei despre elementele tabloului din fisier. \n");
    printf("15. Eliberarea memoriei alocate pentru tablou. \n");
    printf(" 0. Iesire din program.\n");
}

Muzeu* aloc_mem_struct(int* size) {
    int n = 0;
    printf("\nIntroduceti un numar de la 1 la cat doriti\n");
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

Muzeu* add_start_struct(Muzeu* curr, int* size) {
    int new_size = *size + 1;
    Muzeu* temp = (Muzeu*) realloc(curr, new_size * sizeof(Muzeu));

    for (int i = new_size - 1; i > 0; i--) {
        temp[i] = temp[i - 1];
    }
    curr = temp;
    read_struct(&curr[0]);
    *size = new_size;
    return curr;
}

Muzeu* modify_obj_struct(Muzeu* curr, int size) {
    int n = 0;
    printf("\nAlege de la 1 la %d: ", size);
    if (scanf("%d", &n) != 1 || (!(n >= 1 && n <= size))) {
        printf("\nEroare\n", size);
        while (getchar() != '\n');
    };
    while (getchar() != '\n');
    read_struct(&curr[n - 1]);
}

void search_obj(Muzeu* curr, int size) {
    char dest[100];
    printf("\nIntroduceti denumirea muzeului: ");
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

int diff_struct_name(const void* a, const void* b) {
    const Muzeu* A = (const Muzeu*) a;
    const Muzeu* B = (const Muzeu*) b;
    return strcmp(A->denumirea, B->denumirea);
}

int diff_struct_address(const void* a, const void* b) {
    const Muzeu* A = (const Muzeu*) a;
    const Muzeu* B = (const Muzeu*) b;
    return strcmp(A->adresa, B->adresa);
}

int diff_struct_telefon(const void* a, const void* b) {
    const Muzeu* A = (const Muzeu*) a;
    const Muzeu* B = (const Muzeu*) b;
    return strcmp(A->telefonul, B->telefonul);
}
int diff_struct_exponate(const void* a, const void* b) {
    const Muzeu* A = (const Muzeu*) a;
    const Muzeu* B = (const Muzeu*) b;
    if (A->numar_exponate > B->numar_exponate) return 1;
    if (A->numar_exponate == B->numar_exponate) return 0;
    if (A->numar_exponate < B->numar_exponate) return -1;
}
int diff_struct_pret(const void* a, const void* b) {
    const Muzeu* A = (const Muzeu*) a;
    const Muzeu* B = (const Muzeu*) b;
    if (A->pret_bilet > B->pret_bilet) return 1;
    if (A->pret_bilet == B->pret_bilet) return 0;
    if (A->pret_bilet < B->pret_bilet) return -1;
}

void sort_struct(Muzeu* curr, int size) {
    int choice;
    printf("Alege:\n");
    printf("1. Sortare dupa denumire (alfabetic)\n");
    printf("2. Sortare dupa adresa (alfabetic)\n");
    printf("3. Sortare dupa nr. de telefon (alfabetic?)\n");
    printf("4. Sortare dupa nr. exponate (crescator)\n");
    printf("5. Sortare dupa pretul biletului (crescator)\n");
    if ((scanf("%d", &choice) != 1) && choice <= 5 && choice >= 1) {
        printf("ce cu tine atata");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    switch (choice) {
        case 1:
            qsort(curr, size, sizeof(Muzeu), diff_struct_name);
            break;
        case 2:
            qsort(curr, size, sizeof(Muzeu), diff_struct_address);
            break;
        case 3:
            qsort(curr, size, sizeof(Muzeu), diff_struct_telefon);
            break;
        case 4:
            qsort(curr, size, sizeof(Muzeu), diff_struct_exponate);
            break;
        case 5:
            qsort(curr, size, sizeof(Muzeu), diff_struct_pret);
            break;
    }
    print_struct(curr, size);
}

Muzeu* delete_obj(Muzeu* curr, int* size) {
    int choice;
    printf("\nAlege un numar de la 1 la %d:", *size);
    if ((scanf("%d", &choice) != 1) && (choice <= *size && choice >= 1)) {
        printf("out of range");
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
Muzeu* add_before_i_struct(Muzeu* curr, int* size) {
    int ind;
    printf("\nAlege un numar de la 1 la %d:", *size);
    if ((scanf("%d", &ind) != 1) && (ind <= *size && ind >= 1)) {
        printf("out of range");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    int new_size = *size + 1;  // ######## (7,4-1)
    Muzeu* temp = (Muzeu*) realloc(curr, new_size * sizeof(Muzeu));
    for (int i = new_size - 1; i > ind - 1; i--) {
        temp[i] = temp[i - 1];
    }
    curr = temp;
    read_struct(&curr[ind - 1]);
    *size = new_size;
    return curr;
}
Muzeu* add_after_i_struct(Muzeu* curr, int* size) {
    int ind;
    printf("\nAlege un numar de la 1 la %d:", *size);
    if ((scanf("%d", &ind) != 1) && (ind <= *size && ind >= 1)) {
        printf("out of range");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    int new_size = *size + 1;
    Muzeu* temp = (Muzeu*) realloc(curr, new_size * sizeof(Muzeu));
    for (int i = new_size - 1; i >= ind; i--) {
        temp[i] = temp[i - 1];
    }
    curr = temp;
    read_struct(&curr[ind]);
    *size = new_size;
    return curr;
}
void switch_i_j(Muzeu* curr, int size) {
    print_struct(curr, size);
    int k = 0, l = 0;
    printf("\nAlege primul de la 1 la %d:", size);
    if (scanf("%d", &k) != 1 && (k <= size && k >= 1)) {
        printf("out of range");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    printf("\nAlege al doilea de la 1 la %d:", size);
    if (scanf("%d", &l) != 1 && (l <= size && l >= 1)) {
        printf("out of range");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');

    Muzeu temp = curr[k - 1];
    curr[k - 1] = curr[l - 1];
    curr[l - 1] = temp;
}
void write_info(Muzeu* curr, int size) {
    if (curr == NULL || size == 0) {
        printf("nothing to save\n");
        return;
    }
    FILE* fptr = fopen("log.txt", "w");
    if (fptr == NULL) {
        printf("eroare ceva\n");
        return;
    }
    fprintf(fptr, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(fptr, "%s\n", curr[i].denumirea);
        fprintf(fptr, "%s\n", curr[i].adresa);
        fprintf(fptr, "%s\n", curr[i].telefonul);
        fprintf(fptr, "%d\n", curr[i].numar_exponate);
        fprintf(fptr, "%.2f\n", curr[i].pret_bilet);
    }
    fclose(fptr);
}
Muzeu* read_info(Muzeu* curr, int* size) {
    char filename[100];
    printf("\nNumele\\locatia fisierului:\n");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("eroare ceva\n");
        return NULL;
    }
    int new_size = 0;
    if (fscanf(fptr, "%d\n", &new_size) != 1) {
        printf("eroare ceva");
        return NULL;
    }
    if (new_size <= 0) return NULL;

    Muzeu* temp = (Muzeu*) malloc(new_size * sizeof(Muzeu));

    for (int i = 0; i < new_size; i++) {
        fgets(temp[i].denumirea, 100, fptr);
        temp[i].denumirea[strcspn(temp[i].denumirea, "\n")] = 0;
        fgets(temp[i].adresa, 100, fptr);
        temp[i].adresa[strcspn(temp[i].adresa, "\n")] = 0;
        fgets(temp[i].telefonul, 10, fptr);
        temp[i].telefonul[strcspn(temp[i].telefonul, "\n")] = 0;
        fscanf(fptr, "%d", &temp[i].numar_exponate);
        fgetc(fptr);
        fscanf(fptr, "%f", &temp[i].pret_bilet);
        fgetc(fptr);
    }
    fclose(fptr);
    *size = new_size;
    return temp;
}

Muzeu* free_struct(Muzeu* curr, int* size) {
    free(curr);
    curr = NULL;
    *size = 0;
    return curr;
}