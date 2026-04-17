#include "acoperire.h"

#include <stdio.h>
#include <stdlib.h>
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
void acoperireAdiList(Graph* g, int n, ElementQueue** FA1First, ElementQueue** FA1Last, ElementQueue** FA2First, ElementQueue** FA2Last, int start) {
    int* visited = (int*)calloc(n, sizeof(int));
    if (visited == NULL) {
        free(visited);
        return;
    }
    int* nodes = (int*)malloc(n * sizeof(int));
    if (nodes == NULL) {
        free(visited);
        free(nodes);
        return;
    }
    for (int i = start; i < n; i++) {
        nodes[i] = i;
    }
    for (int i = start; i < n; i++) {
        if (visited[i] != 0)
            continue;

        visited[i] = 1;
        printf("%d ", nodes[i] + 1);
        addQueue(FA1First, FA1Last, &nodes[i]);
        while (*FA1First != NULL) {
            while (*FA1First != NULL) {
                int* curr = delQueue(FA1First, FA1Last);
                visited[*curr] = 1;
                int len = 0;
                for (int j = 0; g->adi_list[*curr][j] != 0; j++) len++;
                for (int j = 0; j < len; j++) {
                    int adiacent = g->adi_list[*curr][j] - 1;
                    if (visited[adiacent] == 0) {
                        addQueue(FA2First, FA2Last, &nodes[adiacent]);
                        printf("%d ", adiacent + 1);
                        visited[adiacent] = 1;
                    }
                }
            }
            *FA1First = *FA2First;
            *FA1Last = *FA2Last;
            *FA2First = *FA2Last = NULL;
        }
    }
    printf("\n");
    free(visited);
    free(nodes);
}