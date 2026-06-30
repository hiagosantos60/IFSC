#ifndef TRABALHO_TREE_H
#define TRABALHO_TREE_H

#include "cdr.h"

typedef struct no_cdr no_cdr_t;
no_cdr_t* criar_no_cdr_arvore(cdr_t *dado);
no_cdr_t* inserir_no_cdr_na_arvore(no_cdr_t* raiz, cdr_t *dado);
void arvore_imprimir_in_order(no_cdr_t* raiz);
void destruir_arvore(no_cdr_t* raiz);
void arvore_imprimir_por_ramal(no_cdr_t* raiz, int ramal_filtro);
void arvore_imprimir_intervalo_de_tempo(no_cdr_t* raiz, int ramal_filtro, long long data_inicio, long long data_fim);
no_cdr_t* arvore_remover_antigos_data(no_cdr_t* raiz, long long data_solicitada);
void arvore_salvar_arquivo(no_cdr_t* raiz, FILE* arq);

#endif //TRABALHO_TREE_H