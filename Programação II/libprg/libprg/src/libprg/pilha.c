#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>

typedef struct pilha {
    int *elementos;
    int topo;
    int capacidade;
} pilha_t;

//criar a pilha na memória
pilha_t *criar_pilha(int capacidade) {
    pilha_t *ponteiro = malloc(sizeof(pilha_t));
    ponteiro->elementos = malloc(sizeof(int) * capacidade);
    ponteiro->topo = -1;
    ponteiro->capacidade = capacidade;
    return ponteiro;
}

//adiciona elemento na pilha
int empilhar(pilha_t *ponteiro, int elemento) {
    if (ponteiro->topo < ponteiro->capacidade - 1) {
        ponteiro->topo++;
        ponteiro->elementos[ponteiro->topo] = elemento;
        return 1;
    } else {
        return 0;
    }
}

//remover elemento da pilha
int desempilhar(pilha_t *ponteiro) {
    if (ponteiro->topo >= 0) {
        int elemento = ponteiro->elementos[ponteiro->topo];
        ponteiro->topo--;
        return elemento;
    } else {
        return -1;
    }
}

//mostra o topo da pilha
int mostrar_topo_pilha(pilha_t *ponteiro) {
    if (ponteiro->topo >= 0) {
        return ponteiro->elementos[ponteiro->topo];
    } else {
        //se a pilha estiver vazia
        return -1;
    }
}

//mostrar pilha
int *mostra_pilha(pilha_t *ponteiro) {
    int *elementos_copia = malloc(sizeof(int) * (ponteiro->topo + 1));
    for (int i = 0; i <= ponteiro->topo; i++) {
        elementos_copia[i] = ponteiro->elementos[i];
    }
    return elementos_copia;
}

void imprimir_pilha(pilha_t *ponteiro) {
    for (int i = 0; i <= ponteiro->topo; i++) {
        printf("%d ", ponteiro->elementos[i]);
    }
}

//destruir pilha
void destruir_pilha(pilha_t *ponteiro) {
    free(ponteiro->elementos);
    free(ponteiro);
}


