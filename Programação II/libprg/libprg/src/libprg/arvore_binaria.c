#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct no_arvore {
    int valor;
    struct no_arvore *esquerda;
    struct no_arvore *direita;
} no_arvore;

no_arvore* criar_no_arvore(int valor) {
    no_arvore *no = (no_arvore*)malloc(sizeof(no_arvore));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

void destruir_no_arvore(no_arvore *no) {
    if (no != NULL) {
        destruir_no_arvore(no->esquerda);
        destruir_no_arvore(no->direita);
        free(no);
    }
}

no_arvore* inserir_valor_arvore(no_arvore *raiz, int valor) {
    if (raiz == NULL) {
        return criar_no_arvore(valor);
    } else if (valor < raiz->valor) {
        raiz->esquerda = inserir_valor_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_valor_arvore(raiz->direita, valor);
    }
    return raiz;
}

bool buscar_valor_arvore(no_arvore *raiz, int valor) {
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return buscar_valor_arvore(raiz->esquerda, valor);
    return buscar_valor_arvore(raiz->direita, valor);
}

no_arvore* remover_valor_arvore(no_arvore *raiz, int valor) {
    if (raiz == NULL) return raiz; // se a arvore estiver vazia

    if (valor < raiz->valor) { // valores menores a esquerda
        raiz->esquerda = remover_valor_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) { // valores maiores a direita
        raiz->direita = remover_valor_arvore(raiz->direita, valor);
    } else { // caso o valor passado seja igual ao nó
        if (raiz->esquerda == NULL) { // sobe o da direita
            no_arvore *aux = raiz->direita;
            free(raiz);
            return aux;
        } else if (raiz->direita == NULL) { // sobe o da esquerda
            no_arvore *aux = raiz->esquerda;
            free(raiz);
            return aux;
        } else { // caso se o nó tiver dois filhos
            no_arvore *aux = raiz->direita;

            while (aux && aux->esquerda != NULL) { // vai descendo pela esquerda
                aux = aux->esquerda;
            }

            raiz->valor = aux->valor;
            raiz->direita = remover_valor_arvore(raiz->direita, aux->valor);
        }
    }
    return raiz;
}


int maior_valor_arvore(no_arvore *raiz) {
    if (raiz == NULL) return 0;

    no_arvore *aux = raiz;

    while (aux->direita != NULL) {
        aux = aux->direita;
    }

    return aux->valor;
}

int menor_valor_arvore(no_arvore *raiz) {
    if (raiz == NULL) return 0;

    no_arvore *aux = raiz;

    while (aux->esquerda != NULL) {
        aux = aux->esquerda;
    }

    return aux->valor;
}

int altura_arvore(no_arvore* raiz) {
    if (raiz == NULL) return 0;

    int pela_esquerda = altura_arvore(raiz->esquerda);
    int pela_direita = altura_arvore(raiz->direita);

    if (pela_direita > pela_esquerda) {
        return 1 + pela_direita;
    } else {
        return 1 + pela_esquerda;
    }
}

//depth-first
void imprimir_arvore_in_order (no_arvore *raiz) {
    if (raiz != NULL) {
        imprimir_arvore_in_order(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_arvore_in_order(raiz->direita);
    }
}

void imprimir_arvore_pos_order(no_arvore *raiz) {
    if (raiz != NULL) {
        imprimir_arvore_pos_order(raiz->esquerda);
        imprimir_arvore_pos_order(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void imprimir_arvore_pre_order(no_arvore *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimir_arvore_pre_order(raiz->esquerda);
        imprimir_arvore_pre_order(raiz->direita);
    }
}

// void imprimir_arvore_por_niveis(no_arvore *raiz) {
//     if (raiz == NULL) return; // Se a árvore for vazia, não faz nada
//
//     // cria a fila
//     fila_t* fila = criar_fila(tamanho_arvore);
//
//     enfileirar(fila, raiz);
//
//     while (!fila_vazia(fila)) {
//
//         no_arvore* atual = desenfileirar(fila);
//
//         printf("%d ", atual->valor);
//
//         if (atual->esquerda != NULL) {
//             enfileirar(fila, atual->esquerda);
//         }
//
//         if (atual->direita != NULL) {
//             enfileirar(fila, atual->direita);
//         }
//     }
//
//     destruir_fila(fila);
// }

//------------Árvore AVL--------------

#include <math.h>
#include "libprg/libprg.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct arvore_avl_t {
    int valor;
    int altura;
    struct arvore_avl_t *esquerda;
    struct arvore_avl_t *direita;
} no_avl_t;

no_avl_t* criar_arvore_avl(int valor, int altura) {
    no_avl_t* u = (no_avl_t*) malloc(sizeof(no_avl_t));
    u->valor = valor;
    u->altura = altura;
    u->esquerda = NULL;
    u->direita = NULL;
    return u;
}

no_avl_t* rotacao_avl_esquerda(no_avl_t* v) {
    no_avl_t* u = v->direita;
    v->direita = u->esquerda;
    u->esquerda = v;

    v->altura = max(altura_arvore_avl(v->esquerda), altura_arvore_avl(v->direita)) + 1;
    u->altura = max(altura_arvore_avl(u->esquerda), altura_arvore_avl(u->direita)) + 1;

    return u;
}

no_avl_t* rotacao_avl_direita(no_avl_t* v) {
    no_avl_t* u = v->esquerda;
    v->esquerda = u->direita;
    u->direita = v;

    v->altura = max(altura_arvore_avl(v->esquerda), altura_arvore_avl(v->direita)) + 1;
    u->altura = max(altura_arvore_avl(u->esquerda), altura_arvore_avl(u->direita)) + 1;

    return u;
}

no_avl_t* rotacao_dupla_direita(no_avl_t* v) {
    v->esquerda = rotacao_avl_esquerda(v->esquerda);
    return rotacao_avl_direita(v);
}

no_avl_t* rotacao_dupla_esquerda(no_avl_t* v) {
    v->direita = rotacao_avl_direita(v->direita);
    return rotacao_avl_esquerda(v);
}

int altura_arvore_avl(no_avl_t* v) {
    if (v == NULL) {
        return 0;
    } else {
        return v->altura;
    }
}

// negativo se a subárvore direita for maior
int fator_balanceamento(no_avl_t* v) {
    if (v == NULL) {
        return 0;
    } else {
        return altura_arvore_avl(v->esquerda) - altura_arvore_avl(v->direita);
    }
}

no_avl_t* balancear(no_avl_t* v) {
    int fb = fator_balanceamento(v);
    if (fb > 1){// nó desregulado tem filho desregulado à esquerda
        if (fator_balanceamento(v->esquerda) > 0) {
            // caso esquerda−esquerda
            return rotacao_avl_direita(v);
        } else {
            // caso esquerda−direita
            return rotacao_dupla_direita(v);
        }
    } else if (fb < -1) { // nó desregulado tem filho desregulado à direita
        if (fator_balanceamento(v->direita) < 0) {
            // caso direita−direita
            return rotacao_avl_esquerda(v);
        } else {
            // caso direita−esquerda
            return rotacao_dupla_esquerda(v);
        }
    }
    return v;
}

no_avl_t* inserir_na_arvore_avl(no_avl_t* raiz, int valor) {
    if (raiz == NULL) {
        return criar_arvore_avl(valor, 0);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir_na_arvore_avl(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_na_arvore_avl(raiz->direita, valor);
    } else {
        return raiz; // valor duplicado não é inserido
    }

    //ajustar altura da arvore
    raiz->altura = 1 + max(altura_arvore_avl(raiz->esquerda), altura_arvore_avl(raiz->direita));

    return balancear(raiz);
}

no_avl_t* remover_da_arvore_avl(no_avl_t* raiz, int valor) {
    if (raiz == NULL) return raiz;

    if (valor < raiz->valor) {
        raiz->esquerda = remover_da_arvore_avl(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover_da_arvore_avl(raiz->direita, valor);
    } else {

        // no com dois filhos
        // encontrar o menor valor para subir
        if (raiz->esquerda != NULL && raiz->direita != NULL) {

            no_avl_t* sucessor = raiz->direita;
            while (sucessor->esquerda != NULL) {
                sucessor = sucessor->esquerda;
            }

            raiz->valor = sucessor->valor;

            raiz->direita = remover_da_arvore_avl(raiz->direita, sucessor->valor);
        }
        else {
            no_avl_t *temp;

            if (raiz->esquerda != NULL) {
                temp = raiz->esquerda; // pega o filho da esquerda
            } else {
                temp = raiz->direita;  // se não tem esquerda, pega o da direita
            }

            if (temp == NULL) {
                free(raiz);
                return NULL;
            } else {
                no_avl_t* aux = temp;
                free(raiz);
                return aux;
            }
        }
    }

    // se a arvore ficou vazia
    if (raiz == NULL) return raiz;

    raiz->altura = 1 + max(altura_arvore_avl(raiz->esquerda), altura_arvore_avl(raiz->direita));

    return balancear(raiz);
}

void destruir_arvore_avl(no_avl_t* raiz) {
    if (raiz)
    {
        destruir_arvore_avl(raiz->esquerda);
        destruir_arvore_avl(raiz->direita);
        free(raiz);
    }
}

void imprimir_arvore_avl_in_order(no_avl_t *raiz) {
    if (raiz != NULL) {
        imprimir_arvore_avl_in_order(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_arvore_avl_in_order(raiz->direita);
    }
}