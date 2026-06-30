#include "headers/lab_11.h"
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void lab_11() {
    printf("\n --- Lab 11 --- \n");

    int n = 500000;// Tamanho do teste

    int* vetor_merge = (int*)malloc(n * sizeof(int));
    int* vetor_quick = (int*)malloc(n * sizeof(int));

    srand(1); // Semente fixa para reproducao
    for (int i = 0; i < n; i++) {
        int num = rand() % 101;
        vetor_merge[i] = num;
        vetor_quick[i] = num;
    }

    // Variaveis de tempo
    clock_t start_cpu, end_cpu;
    time_t start_wall, end_wall;
    double cpu_time, wall_time;

    //mergesort
    printf(" Executando Merge Sort \n");
    time(&start_wall);
    start_cpu = clock();

    merge_sort(vetor_merge, 0, n - 1);

    end_cpu = clock();
    time(&end_wall);

    if (n <= 20) {
        printf("Merge Sort Resultado: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", vetor_merge[j]);
        }
        printf("\n");
    }

    cpu_time = ((double)(end_cpu - start_cpu)) / CLOCKS_PER_SEC;
    wall_time = difftime(end_wall, start_wall);

    printf("Tempo CPU: %f s | Tempo Real: %f s\n\n", cpu_time, wall_time);


    //teste quicksort
    printf(" Executando Quick Sort \n");
    time(&start_wall);
    start_cpu = clock();

    quicksort(vetor_quick, 0, n - 1);

    end_cpu = clock();
    time(&end_wall);

    if (n <= 20) {
        printf("Quick Sort Resultado: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", vetor_quick[j]);
        }
        printf("\n");
    }

    cpu_time = ((double)(end_cpu - start_cpu)) / CLOCKS_PER_SEC;
    wall_time = difftime(end_wall, start_wall);

    printf("Tempo CPU: %f s | Tempo Real: %f s\n\n", cpu_time, wall_time);

    free(vetor_merge);
    free(vetor_quick);

    printf("\n --- Fim Lab 11 --- \n");
}