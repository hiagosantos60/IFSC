#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libprg/libprg.h"

typedef struct pessoa {
    char* cpf;
    char* nome;
    char* email;
} pessoa_t;

typedef struct no {
    char* chave;
    pessoa_t* valor;
    struct no* prox; // para apontar para o próximo valor
} no_t;

typedef struct dicionario {
    int tamanho; // tamanho do vetor
    no_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    if (m < 1) {
        return NULL;
    }
    if ((d = (dicionario_t *) malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }

    d->tamanho = m;
    if ((d->vetor = calloc(m, sizeof(no_t *))) == NULL) {
        return NULL;
    }

    // O calloc já deve colocar NULL, mas deixo aqui de forma explícita
    for (int i = 0; i < m; ++i) {
        d->vetor[i] = NULL;
    }
    return d;
}

int hash(const char* chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        int valor_do_char = chave[i]*1; // pega o valor ascii e coloca em int
        soma += (i + 1) * valor_do_char; // multiplica na posição para ser unica (exemplo: lago | gola)
    }
    return soma % m;
}

void destruir_pessoa(pessoa_t* pessoa) {
    if (pessoa->cpf != NULL) {
        free(pessoa->cpf);
    }
    if (pessoa->nome != NULL) {
        free(pessoa->nome);
    }
    if (pessoa->email!= NULL) {
        free(pessoa->email);
    }
    free(pessoa);
}

void destruir_no(no_t* no) {
    if (no != NULL) {
        free(no->chave);
        destruir_pessoa(no->valor);
        free(no);
    }
}

void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {

            destruir_no(d->vetor[i]);
        }
        free(d->vetor);
        free(d);
    }
}

bool inserir_pessoa(dicionario_t* d, char* chave, pessoa_t* valor) {
    int indice = hash(chave, d->tamanho);
    no_t *no = malloc(sizeof(no_t));
    if (no == NULL) {
        return false;
    }
    // strdup reserva memória para fazer a cópia da string. Presente em string.h padrão
    // C23 https://en.cppreference.com/w/c/string/byte/strdup
    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return false;
    }
    no->valor = valor;

    // se houver colisão é necessário usar uma lista encadeada
    no->prox = NULL;
    // libera a memória se existir um nó anterior na posição
    destruir_no(d->vetor[indice]);
    d->vetor[indice] = no;
}


