#include "headers/lab_10.h"
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void lab_10() {
    printf("\n --- Lab 10 --- \n");

    int n = 500000; // tamanho array

    // Alocação de memória
    int* vet_original = (int*) malloc(n * sizeof(int));
    int* vet_copia = (int*) malloc(n * sizeof(int));

    // povoamento do vetor
    srand(1); // Seed fixa para reprodutibilidade

    for (int i = 0; i < n; i++) {
        vet_original[i] = rand() % 101; // numeros entre 0 e 100
    }

    // mostra o vetor original se for pequeno
    if (n <= 20) {
        printf("Vetor Original: ");
        for (int i = 0; i < n; i++) printf("%d ", vet_original[i]);
        printf("\n\n");
    }

    // Variáveis de tempo
    clock_t start_cpu, end_cpu;
    time_t start_wall, end_wall;
    double cpu_time, wall_time;

    printf("Executando Bubble Sort \n");
    memcpy(vet_copia, vet_original, n * sizeof(int));

    time(&start_wall);
    start_cpu = clock();

    bubble_sort(vet_copia, n);

    end_cpu = clock();
    time(&end_wall);

    if (n <= 20) {
        printf("Bubble Sort Resultado: ");
        for (int i = 0; i < n; i++) printf("%d ", vet_copia[i]);
        printf("\n");
    }

    cpu_time = ((double)(end_cpu - start_cpu)) / CLOCKS_PER_SEC;
    wall_time = difftime(end_wall, start_wall);
    printf("Tempo CPU: %f s | Tempo Real: %f s\n\n", cpu_time, wall_time);


    printf("Executando Insertion Sort \n");
    memcpy(vet_copia, vet_original, n * sizeof(int)); // Reseta o vetor novamente

    time(&start_wall);
    start_cpu = clock();

    insertion_sort(vet_copia, n);

    end_cpu = clock();
    time(&end_wall);

    if (n <= 20) {
        printf("Insertion Sort Resultado: ");
        for (int i = 0; i < n; i++) printf("%d ", vet_copia[i]);
        printf("\n");
    }

    cpu_time = ((double)(end_cpu - start_cpu)) / CLOCKS_PER_SEC;
    wall_time = difftime(end_wall, start_wall);
    printf("Tempo CPU: %f s | Tempo Real: %f s\n\n", cpu_time, wall_time);

    printf("Executando Selection Sort \n");
    memcpy(vet_copia, vet_original, n * sizeof(int)); // Reseta o vetor novamente

    time(&start_wall);
    start_cpu = clock();

    selection_sort(vet_copia, n);

    end_cpu = clock();
    time(&end_wall);

    if (n <= 20) {
        printf("Selection Sort Resultado: ");
        for (int i = 0; i < n; i++) printf("%d ", vet_copia[i]);
        printf("\n");
    }

    cpu_time = ((double)(end_cpu - start_cpu)) / CLOCKS_PER_SEC;
    wall_time = difftime(end_wall, start_wall);
    printf("Tempo CPU: %f s | Tempo Real: %f s\n\n", cpu_time, wall_time);

    // Limpeza
    free(vet_original);
    free(vet_copia);

    printf("\n --- Fim Lab 10 --- \n");
}