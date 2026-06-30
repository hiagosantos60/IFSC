#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

typedef struct no_duplo {
    //definindo o que é um nó duplamente ligada
    int valor; // valor do nó
    struct no_duplo *anterior; // ponteiro para o nó anterior ao atual
    struct no_duplo *proximo; // ponteiro para o próximo nó da lista
} no_duplo_t;

no_duplo_t *criar_lista_encadeada_dupla(int valor) {
    no_duplo_t *no_duplo = malloc(sizeof(no_duplo_t)); // alocando memória
    if (no_duplo == NULL) {
        perror("Falha ao alocar memoria");
        exit(1);
    }
    no_duplo->valor = valor; // declarando o valor
    no_duplo->proximo = NULL; // não temos o próximo
    no_duplo->anterior = NULL; // não temos anterior será usado depois

    return no_duplo; // retorna o nó criado
}

void adicionar_na_lista_encadeada_dupla(no_duplo_t **inicio, int valor) {
    no_duplo_t *novo_no_duplo = criar_lista_encadeada_dupla(valor); // criando um novo nó

    novo_no_duplo->proximo = *inicio; // o novo nó vai começar a apontar para o que já existia
    novo_no_duplo->anterior = NULL; // o anterior do novo nó vai ser NULL

    if (*inicio != NULL) {
        (*inicio)->anterior = novo_no_duplo; // o nó antigo vai ter como anterior o nó que adicionamos agora
    }

    *inicio = novo_no_duplo; // o novo inicio é o novo nó
}

no_duplo_t *buscar_na_lista_encadeada_dupla(no_duplo_t *inicio, int valor) {
    no_duplo_t *atual = inicio;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void remover_da_lista_encadeada_dupla(no_duplo_t **inicio, int valor) {
    no_duplo_t *atual = *inicio;

    // Encontrar o nó
    while (atual != NULL) {
        if (atual->valor == valor) {
            break;
        }
        atual = atual->proximo;
    }

    // Se não encontrou
    if (atual == NULL) {
        return;
    }

    // Lógica de remoção
    if (atual->anterior != NULL) {
        // Nó do meio ou fim
        atual->anterior->proximo = atual->proximo;
    } else {
        // É o primeiro nó
        *inicio = atual->proximo;
    }

    if (atual->proximo != NULL) {
        // Nó do início ou meio
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
}

void inserir_na_posicao_lista_dupla(no_duplo_t **inicio, int valor, int posicao) {

    // Inserir no início ou lista vazia
    if (posicao <= 0 || *inicio == NULL) {
        adicionar_na_lista_encadeada_dupla(inicio, valor);
        return;
    }

    // Vai até o nó que ESTÁ na posicao
    no_duplo_t *atual = *inicio;
    int i = 0;
    while (atual != NULL && i < posicao) {
        atual = atual->proximo;
        i++;
    }

    no_duplo_t *novo_no = criar_lista_encadeada_dupla(valor);

    if (atual == NULL) {
        // Precisamos ir até o último nó (não 'atual', que é NULL)
        no_duplo_t *ultimo = *inicio;
        while (ultimo->proximo != NULL) {
            ultimo = ultimo->proximo;
        }

        // Adiciona depois do ultimo
        ultimo->proximo = novo_no;
        novo_no->anterior = ultimo;
        novo_no->proximo = NULL;
    } else {
        // Inserir no Meio insere antes do atual
        no_duplo_t *anterior_no = atual->anterior;

        // Religa os 4 ponteiros
        novo_no->proximo = atual;
        novo_no->anterior = anterior_no;

        atual->anterior = novo_no;

        // anterior_no não será NULL, pois posicao > 0
        if (anterior_no != NULL) {
            anterior_no->proximo = novo_no;
        }
    }
}

void remover_na_posicao_lista_dupla(no_duplo_t **inicio, int posicao) {
    if (*inicio == NULL || posicao < 0) {
        return; // Lista vazia ou posição inválida
    }

    // vai até o nó na posicao
    no_duplo_t *atual = *inicio;
    int i = 0;
    while (atual != NULL && i < posicao) {
        atual = atual->proximo;
        i++;
    }

    // Se atual é NULL, a posição está fora dos limites
    if (atual == NULL) {
        printf("Posicao %d invalida para remocao.\n", posicao);
        return;
    }

    if (atual->anterior != NULL) {
        // Não é o primeiro nó
        atual->anterior->proximo = atual->proximo;
    } else {
        // é o primeiro nó
        *inicio = atual->proximo;
    }

    if (atual->proximo != NULL) {
        // se não é o último nó
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
}