#ifndef TRABALHO_HASH_H
#define TRABALHO_HASH_H

#include "tree.h" // a hash precisa conhecer no_cdr_t
#include "cdr.h"

typedef struct tabela_hash tabela_hash_t;

// Esse código não deve ser modificado
tabela_hash_t *th_criar(int tamanho);
void th_destruir(tabela_hash_t *th);
int  th_inserir_cdr(tabela_hash_t *th, cdr_t* cdr);
no_cdr_t* th_buscar_cdr(tabela_hash_t *th, int ramal_origem);
void th_listar_cdr(tabela_hash_t *th, int ramal_origem);
int th_remover_cdr_antigos(tabela_hash_t *th, int data_hora);
/*----------------------------------*/

void th_carregar_arquivo(tabela_hash_t *th, char* nome_arquivo);
void th_salvar_arquivo(tabela_hash_t *th, char* nome_arquivo);
void th_remover_antigos(tabela_hash_t *th, long long data_limite);
void th_listar_intervalo(tabela_hash_t *th, int ramal, long long inicio, long long fim);

#endif //TRABALHO_HASH_H