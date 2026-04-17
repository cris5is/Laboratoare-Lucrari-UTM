#include "graph_stuff.h"

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

void print_adi_list(Graph* g, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        for (int j = 0; g->adi_list[i][j] != 0; j++) {
            printf("%d ", g->adi_list[i][j]);
        }
        printf("0\n");
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

void freeMem(Graph* g, int n) {
    if (g->adi_list != NULL) {
        for (int i = 0; i < n; i++) free(g->adi_list[i]);
        free(g->adi_list);
        g->adi_list = NULL;
    }
}

void adancime(Graph* g, int n, ElementStack** top, int needed) {
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
    for (int i = 0; i < n; i++) {
        nodes[i] = i;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] != 0)
            continue;
        if (needed != 0 && i == needed - 1) {
            printf("%d\n", i + 1);
            return;
        }
        push(top, &nodes[i]);
        while (*top != NULL) {
            int* curr = pop(top);
            if (visited[*curr] != 0)
                continue;
            visited[*curr] = 1;

            printf("%d ", *curr + 1);
            int len = 0;
            for (int j = 0; g->adi_list[*curr][j] != 0; j++) len++;
            for (int j = len - 1; j >= 0; j--) {
                int adiacent = g->adi_list[*curr][j] - 1;
                if (needed != 0 && adiacent == needed - 1) {
                    printf("%d\n", adiacent + 1);
                    return;
                }
                if (visited[adiacent] == 0) {
                    push(top, &nodes[adiacent]);
                }
            }
        }
    }
    printf("\n");
    free(visited);
    free(nodes);
}

void latime(Graph* g, int n, ElementQueue** FA1First, ElementQueue** FA1Last, ElementQueue** FA2First, ElementQueue** FA2Last, int needed) {
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
    for (int i = 0; i < n; i++) {
        nodes[i] = i;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] != 0)
            continue;
        if (needed != 0 && i == needed - 1) {
            printf("%d\n", i + 1);
            return;
        }
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
                    if (needed != 0 && adiacent == needed - 1) {
                        printf("%d\n", adiacent + 1);
                        return;
                    }
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
void writeInfo(Graph* g, int n) {
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
