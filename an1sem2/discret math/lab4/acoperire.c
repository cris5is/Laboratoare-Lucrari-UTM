#include "acoperire.h"

#include <stdio.h>
#include <stdlib.h>
void addQueue(ElementQueue** first, ElementQueue** last, int* newNode) {
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

int* delQueue(ElementQueue** first, ElementQueue** last) {
    ElementQueue* temp;
    int* result;
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

void freeMem(Graph* g, int n, int k) {
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
            g->adi_list[enter] =
                (int*)realloc(g->adi_list[enter], (count[enter] + 1) * sizeof(int));
            g->adi_list[enter][count[enter] - 1] = exit;
            g->adi_list[enter][count[enter]] = 0;
            enter = -1;
            exit = -1;
        }
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
void acoperireAdiList(Graph* g, Graph* acoperit, int n, ElementQueue** FA1First, ElementQueue** FA1Last, ElementQueue** FA2First, ElementQueue** FA2Last, int start) {
    int* visited = (int*)calloc(n, sizeof(int));
    if (visited == NULL)
        return;
    int* nodes = (int*)malloc(n * sizeof(int));
    if (nodes == NULL) {
        free(visited);
        return;
    }
    acoperit->adi_mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        acoperit->adi_mat[i] = (int*)calloc(n, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        nodes[i] = i;
    }
    int s = start - 1;
    for (int i = 0; i < n; i++) {
        int radacina = (i == 0) ? s : i;
        if (visited[radacina] != 0)
            continue;
        visited[radacina] = 1;
        addQueue(FA1First, FA1Last, &nodes[radacina]);
        while (*FA1First != NULL) {
            while (*FA1First != NULL) {
                int* curr = delQueue(FA1First, FA1Last);
                int len = 0;
                while (g->adi_list[*curr][len] != 0) len++;
                for (int j = 0; j < len; j++) {
                    int adiacent = g->adi_list[*curr][j] - 1;
                    if (visited[adiacent] == 0) {
                        visited[adiacent] = 1;
                        addQueue(FA2First, FA2Last, &nodes[adiacent]);
                        acoperit->adi_mat[*curr][adiacent] = 1;
                    }
                }
            }
            *FA1First = *FA2First;
            *FA1Last = *FA2Last;
            *FA2First = *FA2Last = NULL;
        }
    }
    adi_to_list(acoperit, n);
    print_adi_list(acoperit, n);
    free(visited);
    free(nodes);
}