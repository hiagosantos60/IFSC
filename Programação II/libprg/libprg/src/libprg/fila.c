#include <stdbool.h>
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int* elementos;
    int tamanho;
    int capacidade;
    int inicio;
    int fim;
}fila_t;

fila_t *criar_fila(int capacidade) {
    fila_t *f = malloc(sizeof(fila_t));

    f->elementos = malloc(capacidade * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    f->capacidade = capacidade;

    return f;
}

void enfileirar(fila_t *f, int valor) {
    if (fila_cheia(f)) {
        exit(EXIT_FAILURE);
    } else {
        f->elementos[f->fim] = valor;
        if (f->fim == f->capacidade - 1) {
            f->fim = 0;
        } else {
            f->fim++;
        }
        f->tamanho++;
    }
}

int desenfileirar(fila_t *f) {
    if (f->tamanho == 0) {
        exit(EXIT_FAILURE);
    } else {
        int elemento = f->elementos[f->inicio];
        if (f->inicio == f->capacidade - 1) {
            f->inicio = 0;
        } else {
            f->inicio++;
        }
        f->tamanho--;
        return elemento;
    }
}

//usar em outras funções para verificar a continuidade da fila e do código
bool fila_cheia(fila_t *f) {
    return f->tamanho == f->capacidade;
}

//mostrar elemento no inicio da fila
int inicio_fila(fila_t *f) {
    return f->elementos[f->inicio];
}

//mostar o que está no final da fila
int fim_fila(fila_t *f){
    int indice = (f->fim - 1 + f->capacidade) % f->capacidade;
    return f->elementos[indice];
}

//mostrar o tamanho da fila
int tamanho_fila (fila_t *f){
    return f->tamanho;
}

//mostrar elementos fila
void mostrar_elementos(fila_t *f) {
    for (int i = 0; i < f->tamanho; i++) {
        int indice = (f->inicio + i) % f->capacidade;
        printf("%d ", f->elementos[indice]);
    }
}

//liberar o espaço de memória alocado
void destruir_fila(fila_t *f) {
    free(f->elementos);
    free(f);
}


