#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    int valor;
    struct no *proximo;
} no_t;

//--- Funções Originais Corrigidas ---

//criar lista e nós (Auxiliar)
no_t *criar_lista_encadeada(int valor) {
    no_t *no = malloc(sizeof(no_t));
    if (no == NULL) {
        perror("Erro ao alocar no");
        exit(1);
    }
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

//criar lista encadeada circular (Função auxiliar original, não recomendada para inserção)
no_t *criar_lista_encadeada_circular(int valor) {
    no_t *no = malloc(sizeof(no_t));
    if (no == NULL) {
        perror("Erro ao alocar no");
        exit(1);
    }
    no->valor = valor;
    no->proximo = no;

    return no;
}

//inserir elemento | nó (Insere no início da lista simples)
void inserir_elemento_lista_encadeada(no_t **inicio, int valor_a_inserir) {
    no_t *novo_no = criar_lista_encadeada(valor_a_inserir); //cria um novo nó
    novo_no->proximo = *inicio; // o novo nó aponta para o endereço do que já existia
    *inicio = novo_no; //o início agora é o nó que foi inserido
}

// (Inserção no início da lista circular)
void inserir_elemento_lista_encadeada_circular(no_t **inicio, int valor_a_inserir) {
    // CORREÇÃO: Lida com lista vazia e lógica de inserção

    // Usa a função 'criar_lista_encadeada' (não a circular)
    no_t* novo_no = criar_lista_encadeada(valor_a_inserir);

    if (*inicio == NULL) {
        // Lista está vazia
        *inicio = novo_no;
        novo_no->proximo = *inicio; // Aponta para si mesmo
    } else {
        // Lista não está vazia, insere no início
        no_t* ultimo = *inicio;
        // CORREÇÃO: Encontra o último (o que aponta para o início)
        while (ultimo->proximo != *inicio) {
            ultimo = ultimo->proximo; // Encontra o último
        }

        novo_no->proximo = *inicio;
        ultimo->proximo = novo_no;
        *inicio = novo_no; // Atualiza o início
    }
}


// buscar elementos na lista
no_t *buscar_elementos_lista_encadeada(no_t *inicio, int valor_a_buscar) {
    no_t *atual = inicio; //variável auxiliar

    while (atual != NULL) {
        // Deve verificar atual->valor
        if (atual->valor == valor_a_buscar) {
            return atual; //retorna o endereço de onde está o valor
        }
        atual = atual->proximo; //vou para o próximo nó
    }

    return NULL;
}

//remover elementos da lista encadeada (por valor)
void remover_elementos_lista_encadeada(no_t **inicio, int valor_a_remover) {
    no_t *atual = *inicio;
    no_t *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor_a_remover) {
            // CORREÇÃO: Verifica 'anterior' ANTES de usá-lo
            if (anterior != NULL) {
                // Remove do meio ou fim
                anterior->proximo = atual->proximo;
            } else {
                // Remove o primeiro nó
                *inicio = atual->proximo;
            }
            free(atual); //destroi o nó
            break; // Remove apenas a primeira ocorrência
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

void destruir_lista_ligada (no_t **inicio) {
    no_t* atual = *inicio;

    while (atual != NULL) {
        no_t* proximo = atual->proximo;
        free (atual);
        atual = proximo;
    }
    *inicio = NULL; // Importante
}

void destruir_lista_ligada_circular (no_t **inicio) {
    if (*inicio == NULL) return;

    no_t* atual = *inicio;
    no_t* ultimo = NULL;

    // CORREÇÃO: Encontra o último e quebra o ciclo
    while (ultimo == NULL || atual != *inicio) {
        if (atual->proximo == *inicio) {
            ultimo = atual;
        }
        atual = atual->proximo;
    }

    if (ultimo) {
        ultimo->proximo = NULL; // Quebra o ciclo
    }

    // Agora destrói como uma lista simples
    destruir_lista_ligada(inicio);
}

//--- Funções Laboratório (Corrigidas) ---

//imprimir elementos
// CORREÇÃO: Parâmetro 'inicio' deve ser 'no_t*' (leitura)
void listar_lista_encadeada_lab_7(no_t* inicio) {
    no_t* atual = inicio;

    printf("Lista: [ ");
    while (atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}


//mostrar primeiro
// CORREÇÃO: Parâmetro 'inicio' deve ser 'no_t*' (leitura)
no_t* inicio_lista_encadeada_lab_7(no_t* inicio) {
    if (inicio != NULL)
    {
        return inicio;
    }
    return NULL;
}

//--- EVOLUÇÃO (Novas Funções) ---

// (EVOLUÇÃO) Insere em uma posição específica (Lista Simples)
void inserir_na_posicao_lista_encadeada(no_t **inicio, int valor, int posicao) {
    if (posicao < 0) posicao = 0;

    if (posicao == 0) {
        inserir_elemento_lista_encadeada(inicio, valor);
        return;
    }

    no_t *atual = *inicio;
    no_t *anterior = NULL;
    int i = 0;

    while (atual != NULL && i < posicao) {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    if (anterior == NULL && *inicio != NULL) {
        return; // Não deve acontecer
    }

    no_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = atual;
    anterior->proximo = novo_no;
}

// (EVOLUÇÃO) Remove de uma posição específica (Lista Simples)
void remover_na_posicao_lista_encadeada(no_t **inicio, int posicao) {
    if (*inicio == NULL) return;

    no_t *atual = *inicio;
    no_t *anterior = NULL;
    int i = 0;

    while (atual != NULL && i < posicao) {
        anterior = atual;
        atual = atual->proximo;
        i++;
    }

    if (atual == NULL) {
        printf("Posicao %d invalida para remocao.\n", posicao);
        return;
    }

    if (anterior == NULL) {
        *inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

// (EVOLUÇÃO) Inserir por posição na circular
void inserir_na_posicao_lista_circular(no_t **inicio, int valor, int posicao) {
    if (posicao < 0) posicao = 0;

    if (posicao == 0 || *inicio == NULL) {
        inserir_elemento_lista_encadeada_circular(inicio, valor);
        return;
    }

    no_t *atual = *inicio;
    no_t *anterior = NULL;
    int i = 0;

    do {
        if (i == posicao) break;
        anterior = atual;
        atual = atual->proximo;
        i++;
    } while (atual != *inicio && i < posicao);

    no_t *novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = atual;
    anterior->proximo = novo_no;
}

// (EVOLUÇÃO) Remover por posição na circular
void remover_na_posicao_lista_circular(no_t **inicio, int posicao) {
    if (*inicio == NULL) return; // Vazia

    no_t *atual = *inicio;
    no_t *anterior = NULL;

    no_t *ultimo = *inicio;
    while (ultimo->proximo != *inicio) {
        ultimo = ultimo->proximo;
    }

    if (posicao <= 0) {
        if (atual->proximo == *inicio) {
            *inicio = NULL;
        } else {
            ultimo->proximo = atual->proximo;
            *inicio = atual->proximo;
        }
        free(atual);
    } else {
        int i = 0;
        do {
            if (i == posicao) break;
            anterior = atual;
            atual = atual->proximo;
            i++;
        } while (atual != *inicio && i <= posicao);

        if (atual == *inicio) {
            printf("Posicao %d invalida para remocao.\n", posicao);
            return;
        }

        anterior->proximo = atual->proximo;
        free(atual);
    }
}

