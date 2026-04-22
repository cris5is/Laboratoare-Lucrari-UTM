#include "flux.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addQueue(ElementQueue** first, ElementQueue** last, int* newNode) {
    ElementQueue* temp = (ElementQueue*)calloc(1, sizeof(*temp));
    if (temp == NULL)
        return;
    temp->address = newNode;
    temp->next = NULL;
    if (*first == NULL)
        *first = temp;
    else
        (*last)->next = temp;
    *last = temp;
}

int* delQueue(ElementQueue** first, ElementQueue** last) {
    if (*first == NULL)
        return NULL;
    ElementQueue* temp = *first;
    int* result = temp->address;
    if (temp == *last)
        *first = *last = NULL;
    else
        *first = temp->next;
    free(temp);
    return result;
}

void init_retea(Retea* r, int n) {
    r->n = n;
    r->M_capacity = (int**)calloc(n, sizeof(int*));
    r->M_flux = (int**)calloc(n, sizeof(int*));
    r->parinte = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        r->M_capacity[i] = (int*)calloc(n, sizeof(int));
        r->M_flux[i] = (int*)calloc(n, sizeof(int));
    }
}

void citire_retea(Retea* r, Graph* g) {
    int u, v, cap;
    printf("Introduceti arcele sub forma 'sursa destinatie capacitate' (0 0 0 pentru stop):\n");
    while (scanf("%d %d %d", &u, &v, &cap) == 3 && (u != 0)) {
        if (u > 0 && u <= r->n && v > 0 && v <= r->n) {
            r->M_capacity[u - 1][v - 1] = cap;
        } else {
            printf("Noduri invalide!\n");
        }
    }
}

bool bfs_flux(Retea* r, int sursa, int destinatie) {
    int* vizitat = (int*)calloc(r->n, sizeof(int));
    int* nodes = (int*)malloc(r->n * sizeof(int));
    for (int i = 0; i < r->n; i++) nodes[i] = i;

    ElementQueue *first = NULL, *last = NULL;

    vizitat[sursa] = 1;
    r->parinte[sursa] = -1;
    addQueue(&first, &last, &nodes[sursa]);

    bool gasit = false;
    while (first != NULL) {
        int u = *(delQueue(&first, &last));

        for (int v = 0; v < r->n; v++) {
            if (!vizitat[v] && (r->M_capacity[u][v] - r->M_flux[u][v] > 0)) {
                r->parinte[v] = u;
                vizitat[v] = 1;
                addQueue(&first, &last, &nodes[v]);
                if (v == destinatie) {
                    gasit = true;
                    break;
                }
            }
        }
        if (gasit)
            break;
    }
    while (first != NULL) delQueue(&first, &last);
    free(vizitat);
    free(nodes);
    return gasit;
}

int ford_fulkerson(Retea* r, int sursa, int destinatie) {
    int flux_max = 0;
    while (bfs_flux(r, sursa, destinatie)) {
        int flux_drum = 10000000;

        for (int v = destinatie; v != sursa; v = r->parinte[v]) {
            int u = r->parinte[v];
            if (r->M_capacity[u][v] - r->M_flux[u][v] < flux_drum)
                flux_drum = r->M_capacity[u][v] - r->M_flux[u][v];
        }

        for (int v = destinatie; v != sursa; v = r->parinte[v]) {
            int u = r->parinte[v];
            r->M_flux[u][v] += flux_drum;
            r->M_flux[v][u] -= flux_drum;
        }
        flux_max += flux_drum;
    }
    return flux_max;
}

void afisare_rezultate(Retea* r, int flux_max) {
    printf("\nFlux Maxim: %d\n", flux_max);
    printf("Distributia fluxului:\n");
    for (int i = 0; i < r->n; i++) {
        for (int j = 0; j < r->n; j++) {
            if (r->M_capacity[i][j] > 0)
                printf("Arc (%d->%d): %d/%d\n", i + 1, j + 1, r->M_flux[i][j], r->M_capacity[i][j]);
        }
    }
}

void free_retea(Retea* r) {
    for (int i = 0; i < r->n; i++) {
        free(r->M_capacity[i]);
        free(r->M_flux[i]);
    }
    free(r->M_capacity);
    free(r->M_flux);
    free(r->parinte);
}