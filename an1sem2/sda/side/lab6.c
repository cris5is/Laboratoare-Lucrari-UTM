#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int n;
    int comparatii;
    double timp_mediu;
    int index_gasit;
} Statistica;

int contor_comp = 0;

// Algoritmul tău: Căutare binară recursivă
int cautare_binara_recursiva(int arr[], int stanga, int dreapta, int x) {
    if (dreapta >= stanga) {
        contor_comp++;
        int mijloc = stanga + (dreapta - stanga) / 2;

        if (arr[mijloc] == x)
            return mijloc;

        contor_comp++;
        if (arr[mijloc] > x)
            return cautare_binara_recursiva(arr, stanga, mijloc - 1, x);

        return cautare_binara_recursiva(arr, mijloc + 1, dreapta, x);
    }
    return -1;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Funcție pentru a rula testele pe seturi de date (10k, 100k, 1M)
void ruleaza_test_complet(int tip_tablou, int este_bsearch) {
    int volume[] = {10000, 100000, 1000000};
    int repetari = 100000;

    printf("\n%-20s | %-10s | %-12s | %-15s\n", "Metoda", "N", "Comp.", "Timp Mediu (s)");
    printf("--------------------------------------------------------------------------\n");

    for (int v = 0; v < 3; v++) {
        int n = volume[v];
        int* arr = (int*)malloc(n * sizeof(int));

        // Populare tablou conform variantei
        for (int i = 0; i < n; i++) {
            if (tip_tablou == 4)
                arr[i] = (n - i) * 2;  // Descrescator
            else
                arr[i] = i * 2;  // Crescator / Aleator (simplificat)
        }

        int cheie = arr[n - 1];  // Căutăm ultimul element
        Statistica s;
        s.n = n;

        clock_t start = clock();
        for (int r = 0; r < repetari; r++) {
            contor_comp = 0;
            if (este_bsearch) {
                bsearch(&cheie, arr, n, sizeof(int), compare);
            } else {
                s.index_gasit = cautare_binara_recursiva(arr, 0, n - 1, cheie);
            }
        }
        clock_t end = clock();

        s.timp_mediu = ((double)(end - start) / CLOCKS_PER_SEC) / repetari;
        s.comparatii = (este_bsearch) ? -1 : contor_comp;  // bsearch nu expune comparatiile

        char eticheta[20];
        if (este_bsearch)
            sprintf(eticheta, "bsearch()");
        else
            sprintf(eticheta, "Recursiv Var.%d", tip_tablou);

        printf("%-20s | %-10d | %-12d | %.10f\n", eticheta, s.n, s.comparatii, s.timp_mediu);

        free(arr);
    }
}

int main() {
    int optiune;
    srand(time(NULL));

    do {
        printf("\n========== MENIU ANALIZA ==========\n");
        printf("1. Tablou demonstrativ (n=10)\n");
        printf("2. Tablou cu valori ALEATORII (n=10k, 100k, 1M)\n");
        printf("3. Tablou sortat CRESCATOR (n=10k, 100k, 1M)\n");
        printf("4. Tablou sortat DESCRESCATOR (n=10k, 100k, 1M)\n");
        printf("5. Analiza bsearch() (Standard Library)\n");
        printf("0. Iesire\n");
        printf("===================================\n");
        printf("Alegeti optiunea: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1: {
                int n_demo = 10;
                int demo_arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
                contor_comp = 0;
                int idx = cautare_binara_recursiva(demo_arr, 0, n_demo - 1, 14);
                printf("\n[DEMO] Am cautat valoarea 14 in tablou de 10 elemente.\n");
                printf("Rezultat: Index %d | Comparatii efectuate: %d\n", idx, contor_comp);
                break;
            }
            case 2:
                printf("\n--- ANALIZA: VALORI ALEATORII (Sortate pt. cautare) ---");
                ruleaza_test_complet(2, 0);
                break;
            case 3:
                printf("\n--- ANALIZA: VALORI CRESCATOARE ---");
                ruleaza_test_complet(3, 0);
                break;
            case 4:
                printf("\n--- ANALIZA: VALORI DESCRESCATOARE ---");
                printf("(Nota: Cautarea binara standard va esua aici)\n");
                ruleaza_test_complet(4, 0);
                break;
            case 5:
                printf("\n--- ANALIZA: FUNCTIA STANDARD bsearch() ---");
                ruleaza_test_complet(5, 1);
                break;
            case 0:
                printf("Program terminat.\n");
                break;
            default:
                printf("Optiune invalida!\n");
        }
    } while (optiune != 0);

    return 0;
}