#include <stdio.h>
#include <stdlib.h>
#include "../include/tree.h"
#include "../include/cdr.h"

typedef struct no_cdr {
    long long chave;
    cdr_t* dado;
    struct no_cdr *esquerda;
    struct no_cdr *direita;
} no_cdr_t;

no_cdr_t* criar_no_cdr_arvore(cdr_t* dado) {
    no_cdr_t* novo = malloc(sizeof(no_cdr_t));
    novo->chave = get_inicio(dado);
    novo->dado = dado;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

no_cdr_t* inserir_no_cdr_na_arvore(no_cdr_t* raiz, cdr_t *dado) {
    if (raiz == NULL) {
        return criar_no_cdr_arvore(dado);
    }
    long long chave_dado = get_inicio(dado); // recolhe a data da chamada para comparar
    if (chave_dado < raiz->chave) {
        raiz->esquerda = inserir_no_cdr_na_arvore(raiz->esquerda, dado);
    } else {
        raiz->direita = inserir_no_cdr_na_arvore(raiz->direita, dado);
    }
    return raiz;
}

void arvore_imprimir_in_order(no_cdr_t* raiz) {
    if (raiz != NULL) {
        arvore_imprimir_in_order(raiz->esquerda);
        printf("Data: %lld | Ramal: %d | Destino: %s | Duracao: %d | Tipo: %s\n",
               raiz->chave,
               get_ramal_origem(raiz->dado),
               get_num_destino(raiz->dado),
               get_duracao_seg(raiz->dado),
               get_tipo_chamada(raiz->dado));
        arvore_imprimir_in_order(raiz->direita);
    }
}

void arvore_imprimir_por_ramal(no_cdr_t* raiz, int ramal_filtro) {
    if (raiz != NULL) {
        arvore_imprimir_por_ramal(raiz->esquerda, ramal_filtro);
        if (get_ramal_origem(raiz->dado) == ramal_filtro) {
            printf("Data: %lld | Ramal: %d | Destino: %s | Duracao: %ds | Tipo: %s\n",
                   raiz->chave,
                   get_ramal_origem(raiz->dado),
                   get_num_destino(raiz->dado),
                   get_duracao_seg(raiz->dado),
                   get_tipo_chamada(raiz->dado));
        }
        arvore_imprimir_por_ramal(raiz->direita, ramal_filtro);
    }
}

void arvore_imprimir_intervalo_de_tempo(no_cdr_t* raiz, int ramal_filtro, long long data_inicio, long long data_fim) {
    if (raiz != NULL) {
        if (raiz->chave >= data_inicio) {
            arvore_imprimir_intervalo_de_tempo(raiz->esquerda, ramal_filtro, data_inicio, data_fim);
        }

        if (raiz->chave >= data_inicio && raiz->chave <= data_fim && get_ramal_origem(raiz->dado) == ramal_filtro) {
            printf("Data: %lld | Destino: %s | Duracao: %ds | Tipo: %s\n",
                   raiz->chave,
                   get_num_destino(raiz->dado),
                   get_duracao_seg(raiz->dado),
                   get_tipo_chamada(raiz->dado)
            );
        }

        if (raiz->chave <= data_fim) {
            arvore_imprimir_intervalo_de_tempo(raiz->direita, ramal_filtro, data_inicio, data_fim);
        }
    }
}

void destruir_arvore(no_cdr_t* raiz) {
    if (raiz != NULL) {
        destruir_arvore(raiz->esquerda);
        destruir_arvore(raiz->direita);
        free(raiz->dado);
        free(raiz);
    }
}

void destruir_nos_e_dados(no_cdr_t* raiz) {
    if (raiz != NULL) {
        destruir_nos_e_dados(raiz->esquerda);
        destruir_nos_e_dados(raiz->direita);
        free(raiz->dado);
        free(raiz);
    }
}

no_cdr_t* arvore_remover_antigos_data(no_cdr_t* raiz, long long data_solicitada) {
    if (raiz == NULL) return NULL;

    if (raiz->chave < data_solicitada) {
        no_cdr_t* nova_raiz = arvore_remover_antigos_data(raiz->direita, data_solicitada);
        destruir_nos_e_dados(raiz->esquerda);
        free(raiz->dado);
        free(raiz);
        return nova_raiz;
    }
    else {
        raiz->esquerda = arvore_remover_antigos_data(raiz->esquerda, data_solicitada);
        return raiz;
    }
}

void arvore_salvar_arquivo(no_cdr_t* raiz, FILE* arq) {
    if (raiz != NULL) {
        arvore_salvar_arquivo(raiz->esquerda, arq);
        fprintf(arq, "%d;%s;%lld;%d;%s\n",
            get_ramal_origem(raiz->dado),
            get_num_destino(raiz->dado),
            get_inicio(raiz->dado),
            get_duracao_seg(raiz->dado),
            get_tipo_chamada(raiz->dado));
        arvore_salvar_arquivo(raiz->direita, arq);
    }
}