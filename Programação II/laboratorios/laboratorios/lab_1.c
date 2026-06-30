#include <stdio.h>
#include <stdlib.h>
#include "headers/lab_1.h"

void ex_1() {
    int var = 42;
    int *p = &var;
    printf("Endereço de memória da variável: %p\n", (void *) &var);
    printf("Endereço de memória do ponteiro: %p\n", (void *) p);
}

void ex_2() {
    int vetor[5] = {0, 1, 2, 3, 4};
    int *ponteiro = &vetor[0];

    for (int i = 0; i < 5; i++) {
        ponteiro = &vetor[i];
        printf("Posição %d e valor armazenado no ponteiro: %p \n", i, (void *) ponteiro);
    }
}

void ex_3() {
    int valor = 5;
    int *ponteiro_tres = &valor;

    printf("Valor original: %d\n", valor);
    *ponteiro_tres = 10; // modifica via ponteiro
    printf("Valor modificado via ponteiro: %d\n", valor);
}

void ex_4() {
    int tamanho_array = 0;
    printf("Qual será o tamanho do array: ");
    scanf("%d", &tamanho_array);

    int *array_quatro = (int *) malloc(tamanho_array * sizeof(int));
    if (array_quatro == NULL) {
        printf("erro na alocação\n");
        return;
    }

    for (int i = 0; i < tamanho_array; i++) {
        printf("Qual valor da posição %d: ", i);
        scanf("%d", &array_quatro[i]);
    }

    printf("O array ficou: ");
    for (int i = 0; i < tamanho_array; i++) {
        printf("%d ", array_quatro[i]);
    }
    printf("\n");

    free(array_quatro);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ex_6() {
    char string[21] = "Teste de string em C";
    char *p;
    for (int i = 0; i < 20; i++) {
        p = &string[i];
        printf("%c", *p);
    }
    printf("\n");
}

void ex_8() {
    int tamanho = 5;
    int *array = (int *) malloc(tamanho * sizeof(int));

    if (array == NULL) {
        printf("erro de alocação\n");
        return;
    }

    printf("Digite %d números inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int novo_tamanho = 10;
    int *array_realloc = (int *) realloc(array, novo_tamanho * sizeof(int));

    if (array_realloc == NULL) {
        printf("erro ao realocar\n");
        free(array);
        return;
    }
    array = array_realloc;

    printf("Digite mais 5 números inteiros:\n");
    for (int i = tamanho; i < novo_tamanho; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Array completo:\n");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}

void ex_9() {
    char nome_arquivo[100];
    char texto[256];

    printf("Digite o nome do arquivo: ");
    scanf("%99s", nome_arquivo);

    getchar();

    printf("Digite o texto a ser armazenado no arquivo: ");
    fgets(texto, sizeof(texto), stdin);

    FILE *arquivo = fopen(nome_arquivo, "r+");

    if (arquivo == NULL) {
        printf("não foi possível abrir o arquivo\n");
        return;
    }

    fprintf(arquivo, "%s", texto);

    fclose(arquivo);

    printf("Texto escrito no arquivo '%s'\n", nome_arquivo);
}

void ex_10() {
    char nome_arquivo[101];

    printf("Digite o nome do arquivo de texto existente: ");
    scanf("%100s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro: arquivo '%s' não existe ou não pode ser aberto.\n", nome_arquivo);
        return;
    }

    printf("\nConteúdo do arquivo '%s':\n", nome_arquivo);

    char caracteres;
    while ((caracteres = fgetc(arquivo)) != EOF) {
        putchar(caracteres);
    }

    fclose(arquivo);

    printf("\nLeitura concluída.\n");
}

void ex_11() {
    char arquivo_origem[100];
    char arquivo_destino[100];

    printf("Digite o nome do arquivo de origem: ");
    scanf("%99s", arquivo_origem);

    printf("Digite o nome do arquivo de destino: ");
    scanf("%99s", arquivo_destino);

    FILE *origem = fopen(arquivo_origem, "r");
    if (origem == NULL) {
        printf("Erro: não foi possível abrir o arquivo de origem '%s'.\n", arquivo_origem);
        return;
    }

    FILE *destino = fopen(arquivo_destino, "w");
    if (destino == NULL) {
        printf("Erro: não foi possível criar ou abrir o arquivo de destino '%s'.\n", arquivo_destino);
        fclose(origem);
        return;
    }

    char caractere;
    while ((caractere = fgetc(origem)) != EOF) {
        fputc(caractere, destino);
    }

    fclose(origem);
    fclose(destino);

    printf("\nConteúdo copiado de '%s' para '%s'\n", arquivo_origem, arquivo_destino);
}

void lab_1() {
    printf("\n --- Lab 1 --- \n");
    ex_1();
    ex_2();
    ex_3();
    ex_4();
    ex_6();
    ex_8();
    ex_9();
    ex_10();
    ex_11();
    printf("\n --- Fim Lab 1 --- \n");
}
