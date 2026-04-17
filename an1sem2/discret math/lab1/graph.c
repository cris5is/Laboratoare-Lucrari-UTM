#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int** inc_mat;
    int** adi_mat;
    int** adi_list;
} Graph;

void read_mat_inc(Graph* g, int n, int k) {
    g->inc_mat = (int**)malloc(k * sizeof(int*));
    for (int i = 0; i < k; i++) {
        g->inc_mat[i] = (int*)calloc(n, sizeof(int));
    }
    for (int i = 0; i < k; i++) {
        int one = 0, two = 0;
        printf("Scrie legatura %d in forma \none two(iesa intra)\n", i + 1);
        while (scanf("%d %d", &one, &two) != 2 || one < 1 || one > n || two < 1 || two > n) {
            printf("Valori invalide, cititi din nou sub forma\n");
            printf("Scrie legatura %d in forma \none two(iesa intra)\n", i + 1);
        }
        if (one != two) {
            g->inc_mat[i][one - 1] = -1;

            g->inc_mat[i][two - 1] = 1;
        } else {
            g->inc_mat[i][one - 1] = 2;
        }
    }
}
void read_mat_adi(Graph* g, int n) {
    g->adi_mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->adi_mat[i] = (int*)calloc(n, sizeof(int));
        printf("arr[%d]  (scrie tot randul)", i);
        for (int j = 0; j < n; j++) {
            while (scanf("%d", &g->adi_mat[i][j]) != 1 || g->adi_mat[i][j] < 0 ||
                   g->adi_mat[i][j] > n) {
                printf(
                    "Valoare invalida, citeste din nou de la arr[%d][%d] elementele ramase in "
                    "rand\n",
                    i,
                    j);
            }
        }
    }
}
void read_list_adi(Graph* g, int n) {
    g->adi_list = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        int member, count = 0;
        g->adi_list[i] = NULL;
        printf("Vf.%d (0 pentru stop): ", i + 1);
        while (scanf("%d", &member) == 1 && member != 0) {
            if (member > 0 && member <= n) {
                count++;
                g->adi_list[i] = (int*)realloc(g->adi_list[i], (count + 1) * sizeof(int));
                g->adi_list[i][count - 1] = member;
                g->adi_list[i][count] = 0;
            } else
                while (scanf("%d", &member) != 1 || member > n || member < 0)
                    printf("Citeste inca odata linia\n");
        }

        if (count == 0) {
            g->adi_list[i] = (int*)malloc(sizeof(int));
            g->adi_list[i][0] = 0;
        }
    }
}

void print_inc_mat(Graph* g, int n, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", g->inc_mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void print_adi_mat(Graph* g, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", g->adi_mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void print_adi_list(Graph* g, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        for (int j = 0; g->adi_list[i][j] != 0; j++) {
            printf("%d ", g->adi_list[i][j]);
        }
        printf("0\n");
    }
}
void list_to_inc(Graph* g, int n, int* k) {
    int kTemp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; g->adi_list[i][j] != 0; j++) {
            kTemp++;
        }
    }

    g->inc_mat = (int**)malloc(kTemp * sizeof(int*));
    for (int i = 0; i < kTemp; i++) g->inc_mat[i] = (int*)calloc(n, sizeof(int));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; g->adi_list[i][j] != 0; j++) {
            if (i + 1 != g->adi_list[i][j]) {
                g->inc_mat[count][i] = -1;
                g->inc_mat[count][g->adi_list[i][j] - 1] = 1;
                count++;
            } else {
                g->inc_mat[count][i] = 2;
                count++;
            }
        }
    }
    *k = kTemp;
    if (g->adi_list != NULL) {
        for (int i = 0; i < n; i++) free(g->adi_list[i]);

        free(g->adi_list);
        g->adi_list = NULL;
    }
}
void list_to_adi(Graph* g, int n) {
    g->adi_mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->adi_mat[i] = (int*)calloc(n, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; g->adi_list[i][j] != 0; j++) {
            g->adi_mat[i][g->adi_list[i][j] - 1] = 1;
        }
    }
    if (g->adi_list != NULL) {
        for (int i = 0; i < n; i++) free(g->adi_list[i]);
        free(g->adi_list);
        g->adi_list = NULL;
    }
}
void adi_to_list(Graph* g, int n) {
    g->adi_list = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        int count = 0;
        g->adi_list[i] = NULL;
        for (int j = 0; j < n; j++) {
            if (g->adi_mat[i][j] != 0) {
                count++;
                g->adi_list[i] = (int*)realloc(g->adi_list[i], (count + 1) * sizeof(int));
                g->adi_list[i][count - 1] = j + 1;
                g->adi_list[i][count] = 0;
            }
        }

        if (count == 0) {
            g->adi_list[i] = (int*)malloc(sizeof(int));
            g->adi_list[i][0] = 0;
        }
    }
    if (g->adi_mat != NULL) {
        for (int i = 0; i < n; i++) free(g->adi_mat[i]);
        free(g->adi_mat);
        g->adi_mat = NULL;
    }
}
void inc_to_list(Graph* g, int n, int k) {
    g->adi_list = (int**)malloc(n * sizeof(int*));
    int* count = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        g->adi_list[i] = (int*)malloc(sizeof(int));
        g->adi_list[i][0] = 0;
    }
    for (int i = 0; i < k; i++) {
        int enter = -1, exit = -1;
        for (int j = 0; j < n; j++) {
            if (g->inc_mat[i][j] == -1) {
                enter = j;
            } else if (g->inc_mat[i][j] == 1) {
                exit = j + 1;
            } else if (g->inc_mat[i][j] != 0) {
                enter = j;
                exit = j + 1;
            }
        }
        if (enter != -1 && exit != -1) {
            count[enter]++;
            printf("count[%d]=%d, exit=%d\n", enter, count[enter], exit);
            g->adi_list[enter] =
                (int*)realloc(g->adi_list[enter], (count[enter] + 1) * sizeof(int));
            g->adi_list[enter][count[enter] - 1] = exit;
            g->adi_list[enter][count[enter]] = 0;
            enter = -1;
            exit = -1;
        }
    }
    if (g->inc_mat != NULL) {
        for (int i = 0; i < k; i++) free(g->inc_mat[i]);
        free(g->inc_mat);
        g->inc_mat = NULL;
    }
}
void free_mem(Graph* g, int n, int k) {
    if (g->inc_mat != NULL) {
        for (int i = 0; i < k; i++) free(g->inc_mat[i]);
        free(g->inc_mat);
        g->inc_mat = NULL;
    }
    if (g->adi_mat != NULL) {
        for (int i = 0; i < n; i++) free(g->adi_mat[i]);
        free(g->adi_mat);
        g->adi_mat = NULL;
    }
    if (g->adi_list != NULL) {
        for (int i = 0; i < n; i++) free(g->adi_list[i]);
        free(g->adi_list);
        g->adi_list = NULL;
    }
}
void menu_inc() {
    printf(
        "\nAlege:\n1. Afiseaza matricea de incidenta\n2. Converteaza in lista\n3. Elibereaza "
        "memoria si opreste programul\n\n");
}
void menu_adi() {
    printf(
        "\nAlege:\n1. Afiseaza matricea de adiacenta\n2. Converteaza in lista\n3. Elibereaza "
        "memoria si opreste programul\n\n");
}
void menu_list() {
    printf("\nAlege:\n1. Afiseaza lista de adiacenta\n2. Converteaza in matrice de incidenta");
    printf(
        "\n3. Converteaza in matrice de adiacenta\n4. Salveaza in fisier .txt\n5. Elibereaza "
        "memoria si opreste programul\n");
}
void write_info(Graph* g, int n) {
    if (g == NULL || n == 0 || g->adi_list == NULL) {
        printf("nothing to save\n");
        return;
    }
    FILE* fptr = fopen("log.txt", "w");
    if (fptr == NULL) {
        printf("eroare ceva\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "%d: ", i + 1);
        for (int j = 0; g->adi_list[i][j] != 0; j++) {
            fprintf(fptr, "%d ", g->adi_list[i][j]);
        }
        fprintf(fptr, "0\n");
    }
    fclose(fptr);
}
int main() {
    Graph g;
    g.inc_mat = NULL;
    g.adi_mat = NULL;
    g.adi_list = NULL;
    int n = 0, k = 0;

    int choice = 0, choice2 = 0;

    printf(
        "\nAlege tipu:\n1. Matrice de incidenta\n2. Matrice de adiacenta\n3. Lista de "
        "adiacenta\n\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Introdu numerele n si k sub forma:\nn k\n");
            scanf("%d %d", &n, &k);
            read_mat_inc(&g, n, k);

            break;
        case 2:
            printf("Introdu numarul n:\n");
            scanf("%d", &n);
            read_mat_adi(&g, n);
            break;
        case 3:
            printf("Introdu numarul n:\n");
            scanf("%d", &n);
            read_list_adi(&g, n);
            break;
    }
    int cond = 0;
    do {
        choice2 = 0;
        switch (choice) {
            case 1:
                menu_inc();
                scanf("%d", &choice2);
                switch (choice2) {
                    case 1:
                        print_inc_mat(&g, n, k);
                        break;
                    case 2:
                        inc_to_list(&g, n, k);
                        choice = 3;
                        break;
                    case 3:
                        cond = 1;
                        break;
                }
                break;
            case 2:
                menu_adi();
                scanf("%d", &choice2);
                switch (choice2) {
                    case 1:
                        print_adi_mat(&g, n);
                        break;
                    case 2:
                        adi_to_list(&g, n);
                        choice = 3;
                        break;
                    case 3:
                        cond = 1;
                        break;
                }
                break;
            case 3:
                menu_list();
                scanf("%d", &choice2);
                switch (choice2) {
                    case 1:
                        print_adi_list(&g, n);
                        break;
                    case 2:
                        list_to_inc(&g, n, &k);
                        choice = 1;
                        break;
                    case 3:
                        list_to_adi(&g, n);
                        choice = 2;
                        break;
                    case 4:
                        write_info(&g, n);
                        break;
                    case 5:
                        cond = 1;
                        break;
                }
                break;
        }

    } while (!cond);

    free_mem(&g, n, k);
    return 0;
}