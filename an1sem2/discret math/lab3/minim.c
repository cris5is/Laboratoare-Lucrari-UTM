#include "minim.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void push(ElementStack** top, int* newNode) {
    ElementStack* temp;
    temp = (ElementStack*)calloc(1, sizeof(*temp));
    if (temp == NULL)
        return;
    temp->address = newNode;
    temp->next = *top;
    *top = temp;
}
int* pop(ElementStack** top) {
    ElementStack* temp;
    int* result;
    temp = *top;
    result = temp->address;
    *top = temp->next;
    free(temp);
    return result;
}
void readMat(Graph* g, int n) {
    g->adi_mat = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->adi_mat[i] = (int*)calloc(n, sizeof(int));
        printf("arr[%d] ponderat (scrie tot randul): ", i);
        for (int j = 0; j < n; j++) {
            while (scanf("%d", &g->adi_mat[i][j]) != 1) {
                printf("Valoare invalida, citeste din nou de la arr[%d][%d] elementele ramase in rand\n", i, j);
            }
        }
    }
}

void printMat(Graph* g, int n) {
    printf("     |   ");
    for (int i = 0; i < n; i++) {
        printf("x%d  ", i + 1);
    }
    printf("\n ");
    for (int i = 0; i < n * 5 - 1; i++) {
        printf("-");
    }
    for (int i = 0; i < n; i++) {
        printf("\n  x%d | ", i + 1);
        for (int j = 0; j < n; j++) {
            printf("%3d ", g->adi_mat[i][j]);
        }
    }
    printf("\n\n");
}

void writeInfo(Graph* g, int n) {
    if (g == NULL || n == 0 || g->adi_mat == NULL) {
        printf("nothing to save\n");
        return;
    }
    FILE* fptr = fopen("log.txt", "w");
    if (fptr == NULL) {
        printf("eroare ceva\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(fptr, "%d ", g->adi_mat[i][j]);
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);
}

void freeMem(Graph* g, int n) {
    if (g->adi_mat != NULL) {
        for (int i = 0; i < n; i++) free(g->adi_mat[i]);
        free(g->adi_mat);
        g->adi_mat = NULL;
    }
}
void printDrumuriF(Graph* g, int* h, int curent, int final, int* drum, int pas, int n) {
    drum[pas] = curent;
    if (curent == final) {
        for (int i = 0; i <= pas; i++) {
            printf("%d%s", drum[i] + 1, (i == pas ? "" : "->"));
        }
        printf("\n");
        return;
    }
    for (int j = 0; j < n; j++) {
        int pondere = g->adi_mat[curent][j];
        if (pondere != 0) {
            if (h[j] - h[curent] == pondere) {
                printDrumuriF(g, h, j, final, drum, pas + 1, n);
            }
        }
    }
}
void fordMinim(Graph* g, int n) {
    if (g == NULL || g->adi_mat == NULL)
        return;

    int* h = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) h[i] = 1000000;
    h[0] = 0;

    int schimbat;
    for (int k = 0; k < n - 1; k++) {
        schimbat = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g->adi_mat[i][j] != 0 && h[i] != 1000000) {
                    if (h[j] > h[i] + g->adi_mat[i][j]) {
                        h[j] = h[i] + g->adi_mat[i][j];
                        schimbat = 1;
                    }
                }
            }
        }
        if (!schimbat)
            break;
    }
    int* drum = (int*)malloc(n * sizeof(int));
    if (h[n - 1] == 1000000) {
        printf("Nu exista drum de la nodul 1 la %d\n", n);
    } else {
        printf("Lungimea minima a drumului: %d\n", h[n - 1]);
        printDrumuriF(g, h, 0, n - 1, drum, 0, n);
    }

    free(drum);
    free(h);
}
void printDrumuriBK(Graph* g, int* V, int curent, int final, int* drum, int pas, int n) {
    drum[pas] = curent;
    if (curent == final) {
        for (int i = 0; i <= pas; i++) {
            printf("%d%s", drum[i] + 1, (i == pas ? "" : " -> "));
        }
        printf("\n");
        return;
    }

    for (int j = 0; j < n; j++) {
        if (curent != j && g->adi_mat[curent][j] != 0) {
            int pondere = g->adi_mat[curent][j];
            if (V[curent] == pondere + V[j]) {
                printDrumuriBK(g, V, j, final, drum, pas + 1, n);
            }
        }
    }
}

void bellman_kalabaMinim(Graph* g, int n) {
    if (g == NULL || g->adi_mat == NULL)
        return;

    int** M = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        M[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i == j)
                M[i][j] = 0;
            else if (g->adi_mat[i][j] != 0)
                M[i][j] = g->adi_mat[i][j];
            else
                M[i][j] = 1000000;
        }
    }

    int* V0 = (int*)malloc(n * sizeof(int));
    int* V1 = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) V0[i] = M[i][n - 1];

    int stop = 0;
    while (!stop) {
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                V1[i] = 0;
                continue;
            }
            int minim = V0[i];
            for (int j = 0; j < n; j++) {
                if (i != j && M[i][j] + V0[j] < minim) {
                    minim = M[i][j] + V0[j];
                }
            }
            V1[i] = minim;
        }
        stop = 1;
        for (int i = 0; i < n; i++) {
            if (V1[i] != V0[i]) {
                stop = 0;
                break;
            }
        }
        if (!stop) {
            for (int i = 0; i < n; i++) V0[i] = V1[i];
        }
    }
    int* drum = (int*)malloc(n * sizeof(int));

    if (V0[0] >= 1000000) {
        printf("Nu exista drum de la nodul 1 la %d\n", n);
    } else {
        printf("Lungimea minima a drumului: %d\n", V0[0]);
        printDrumuriBK(g, V0, 0, n - 1, drum, 0, n);
    }

    free(drum);
    for (int i = 0; i < n; i++) free(M[i]);
    free(M);
    free(V0);
    free(V1);
}