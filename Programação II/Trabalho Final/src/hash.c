#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/hash.h"
#include "../include/tree.h"
#include "../include/cdr.h"

typedef struct tabela_hash {
    no_cdr_t **buckets; // vetor de ponteiros para raizes de arvores
    int tamanho; // tamanho da tabela
} tabela_hash_t;

// função de hash para designar ramal
int hash_funcao(int ramal, int tamanho) {
    return ramal % tamanho;
}

tabela_hash_t *th_criar(int tamanho) {
    tabela_hash_t* th = malloc(sizeof(struct tabela_hash));
    if (th != NULL) {
        th->tamanho = tamanho;
        // calloc para não ter lixo de memória, ser tudo zero nas raizes
        th->buckets = calloc(tamanho, sizeof(no_cdr_t *));
    }
    return th;
}

int th_inserir_cdr(tabela_hash_t *th, cdr_t* cdr) {
    if (th == NULL || cdr == NULL) return 0; // se não receber os parametros certos

    int ramal_origem = get_ramal_origem(cdr); // identificar ramal de origem

    int indice = hash_funcao(ramal_origem, th->tamanho); // escolher qual árvore será usada para armazenar os dados

    // enviamos a raiz atual e o cdr para inserir, após isso,
    // atualiza qual a raiz da arvore naquela posicao da hash table
    th->buckets[indice] = inserir_no_cdr_na_arvore(th->buckets[indice], cdr);

    return 1; // informa que deu certo
}


void th_listar_cdr(tabela_hash_t *th, int ramal_origem) {
    if (th == NULL) return;

    // descobri em qual árvore o refistro estś
    int indice = hash_funcao(ramal_origem, th->tamanho);

    printf("--- Relatorio do Ramal %d (Bucket %d) ---\n", ramal_origem, indice);

    if (th->buckets[indice] != NULL) {
        // função da arvore para fazer a varredura
        arvore_imprimir_in_order(th->buckets[indice]);
    } else {
        printf("Registro não encontrado...\n");
    }
}

no_cdr_t* th_buscar_cdr(tabela_hash_t *th, int ramal_origem) {
    if (th == NULL) {
        return NULL;
    }

    int indice = hash_funcao(ramal_origem, th->tamanho);

    return th->buckets[indice];
}


void th_destruir(tabela_hash_t *th) {
    if (th == NULL) return; // se nao tiver nada

    //destruir as raizes, perdendo a referecia
    for (int i = 0; i < th->tamanho; i++) {
        if (th->buckets[i] != NULL) {
            destruir_arvore(th->buckets[i]);
        }
    }

    // destruir o ponteiro para as raízes
    free(th->buckets);

    // destruindo a tabela da memória
    free(th);
}

void th_remover_antigos(tabela_hash_t *th, long long data_limite) {
    if (th == NULL) return;

    for (int i = 0; i < th->tamanho; i++) {
        if (th->buckets[i] != NULL) {
            // Atualiza a raiz do bucket após a remoção
            th->buckets[i] = arvore_remover_antigos_data(th->buckets[i], data_limite);
        }
    }
    printf("Registros anteriores a %lld removidos com sucesso.\n", data_limite);
}

void th_salvar_arquivo(tabela_hash_t *th, char* nome_arquivo) {
    FILE* arq = fopen(nome_arquivo, "w");
    if (!arq) {
        printf("Erro ao abrir arquivo para salvar.\n");
        return;
    }
    for (int i = 0; i < th->tamanho; i++) {
        arvore_salvar_arquivo(th->buckets[i], arq);
    }
    fclose(arq);
}

void th_carregar_arquivo(tabela_hash_t *th, char* nome_arquivo) {
    FILE* arq = fopen(nome_arquivo, "r");
    if (!arq) return; // Arquivo não existe, primeira execução

    int ramal, duracao;
    long long inicio;
    char destino[32], tipo[16];

    // Ler linha a linha (o formato deve combinar com o fprintf)
    while (fscanf(arq, "%d;%31[^;];%lld;%d;%15[^\n]\n", &ramal, destino, &inicio, &duracao, tipo) == 5) {
        cdr_t* novo = criar_cdr(ramal, destino, inicio, duracao, tipo);
        th_inserir_cdr(th, novo);
    }
    fclose(arq);
}

void th_listar_intervalo(tabela_hash_t *th, int ramal, long long inicio, long long fim) {
    if (th == NULL) return;

    // descobre o ramal
    int indice = hash_funcao(ramal, th->tamanho);

    if (th->buckets[indice] != NULL) {
        printf("--- Relatorio por Intervalo (Ramal %d) ---\n", ramal);
        arvore_imprimir_intervalo_de_tempo(th->buckets[indice], ramal, inicio, fim);
    } else {
        printf("Nenhum registro encontrado para esse ramal.\n");
    }
}