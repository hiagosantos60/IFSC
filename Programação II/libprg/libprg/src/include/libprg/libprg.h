#ifndef LIBPRG_H
#define LIBPRG_H
#include <stdbool.h>

//pilha
typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t *ponteiro, int elemento);
int desempilhar(pilha_t *ponteiro);
int mostrar_topo_pilha(pilha_t *ponteiro);
int* mostra_pilha(pilha_t *ponteiro);
void destruir_pilha(pilha_t* ponteiro);
void imprimir_pilha(pilha_t *ponteiro);


//fila
typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
void enfileirar(fila_t* fila, int valor);
int desenfileirar(fila_t *f);
void destruir_fila(fila_t *f);
bool fila_cheia(fila_t *f);
int tamanho_fila (fila_t *f);
int fim_fila(fila_t *f);
int inicio_fila(fila_t *f);
void mostrar_elementos(fila_t *f);


//lista
typedef struct lista_linear lista_t;
lista_t* criar_lista(int capacidade, bool ordenada);
void destruir_lista (lista_t* lista);
bool verificar_lista_cheia(lista_t* lista);
bool verificar_lista_vazia(lista_t* lista);
void remover_elemento_lista(lista_t* lista, int valor_a_remover);
int buscar_elementos_lista(lista_t* lista, int valor_a_buscar);
void inserir_lista (lista_t* lista, int valor_a_inserir);
void imprimir_primeiro_e_tamanho(lista_t *lista);
void imprimir_lista_completa(lista_t *lista);
int tamanho_lista_linear(lista_t *lista);
int buscar_na_posicao_lista(lista_t *lista, int posicao);
void inserir_na_posicao_lista(lista_t *lista, int valor_a_inserir, int posicao);
void remover_na_posicao_lista(lista_t *lista, int posicao);

//lista ligada
typedef struct no no_t;
no_t* criar_lista_encadeada (int valor);
void inserir_elemento_lista_encadeada(no_t** inicio, int valor_a_inserir);
void remover_elementos_lista_encadeada(no_t** inicio, int valor_a_remover);
no_t *buscar_elementos_lista_encadeada(no_t *inicio, int valor_a_buscar);
void destruir_lista_ligada (no_t **inicio);
void inserir_na_posicao_lista_encadeada(no_t **inicio, int valor, int posicao);
void remover_na_posicao_lista_encadeada(no_t **inicio, int posicao);


//lista_circular
no_t *criar_lista_encadeada_circular(int valor);
void inserir_elemento_lista_encadeada_circular(no_t **inicio, int valor_a_inserir);
void destruir_lista_ligada_circular (no_t **inicio);
void listar_lista_encadeada_lab_7(no_t* inicio);
no_t* inicio_lista_encadeada_lab_7(no_t* inicio);
void inserir_na_posicao_lista_circular(no_t **inicio, int valor, int posicao);
void remover_na_posicao_lista_circular(no_t **inicio, int posicao);


//lista encadeada dupla
typedef struct no_duplo no_duplo_t;
no_duplo_t* criar_lista_encadeada_dupla(int valor);
void adicionar_na_lista_encadeada_dupla(no_duplo_t **inicio, int valor);
no_duplo_t *buscar_na_lista_encadeada_dupla(no_duplo_t *inicio, int valor);
void remover_da_lista_encadeada_dupla(no_duplo_t** inicio, int valor);
void remover_na_posicao_lista_dupla(no_duplo_t **inicio, int posicao);

//algoritimos de ordenação
void selection_sort(int* arr, int tamanho);
void bubble_sort(int* arr, int tamanho);
void insertion_sort(int* arr, int tamanho);
int* merge_sort(int* arr, int esquerda, int direita);
int* quicksort(int* arr, int inicio, int fim) ;

//arvore binaria
typedef struct no_arvore no_arvore;
int altura_arvore(no_arvore* raiz);
int menor_valor_arvore(no_arvore *raiz);
int maior_valor_arvore(no_arvore *raiz);
no_arvore* remover_valor_arvore(no_arvore *raiz, int valor);
bool buscar_valor_arvore(no_arvore *raiz, int valor);
no_arvore* inserir_valor_arvore(no_arvore *raiz, int valor);
void destruir_no_arvore(no_arvore *no);
no_arvore* criar_no_arvore(int valor);
void imprimir_arvore_pre_order(no_arvore *raiz);
void imprimir_arvore_pos_order(no_arvore *raiz);
void imprimir_arvore_in_order (no_arvore *raiz);
//arvore avl
typedef struct arvore_avl_t no_avl_t;
no_avl_t* criar_arvore_avl(int valor, int altura);
int altura_arvore_avl(no_avl_t* v);
no_avl_t* inserir_na_arvore_avl(no_avl_t* raiz, int valor);
no_avl_t* remover_da_arvore_avl(no_avl_t* raiz, int valor);
void destruir_arvore_avl(no_avl_t* raiz);
void imprimir_arvore_avl_in_order(no_avl_t *raiz);

//dicionario (hash table)
typedef struct dicionario dicionario_t;
typedef struct no no_t;
typedef struct pessoa pessoa_t;
void destruir_pessoa(pessoa_t* pessoa);
void destruir_no(no_t* no);
bool inserir_pessoa(dicionario_t* d, char* chave, pessoa_t* valor);
void destruir_dicionario(dicionario_t *d);

#endif