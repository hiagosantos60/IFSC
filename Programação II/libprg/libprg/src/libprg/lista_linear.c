#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <libprg/libprg.h>

// --- Estrutura da Lista ---
typedef struct lista_linear {
    int *elementos; //ponteiro para apontar onde estão os elementos de fato
    int tamanho; //quantidade de elementos armazenados
    int capacidade; //capacidade total que cabe na lista
    bool ordenada; //flag para verificar se a lista é ordenada
} lista_t;


// Cria uma lista vazia
lista_t *criar_lista(int capacidade, bool ordenada) {
    if (capacidade <= 0) capacidade = 10; // Garantia mínima
    lista_t *lista = malloc(sizeof(lista_t));
    if (lista == NULL) {
        perror("Erro ao alocar lista");
        exit(1);
    }
    lista->elementos = malloc(sizeof(int) * capacidade);
    if (lista->elementos == NULL) {
        perror("Erro ao alocar elementos");
        free(lista);
        exit(1);
    }
    lista->capacidade = capacidade;
    lista->tamanho = 0;
    lista->ordenada = ordenada;
    return lista;
}

int tamanho_lista_linear(lista_t *lista) {
    return lista->tamanho;
}

//liberar a memória alocada para a lista
void destruir_lista(lista_t *lista) {
    free(lista->elementos);
    free(lista);
}

//verifica se a lista está vazia
bool verificar_lista_vazia(lista_t *lista) {
    return lista->tamanho == 0;
}

//verifica se a lista está cheia
bool verificar_lista_cheia(lista_t *lista) {
    return lista->tamanho == lista->capacidade;
}

// Função interna, chamada por inserir_lista
void inserir_nao_ordenada(lista_t *lista, int valor_a_inserir) {
    //adiciona o elemento na primeira posição livre
    lista->elementos[lista->tamanho] = valor_a_inserir;
    lista->tamanho++;
}

// Função interna, chamada por inserir_lista
void inserir_ordenada(lista_t *lista, int valor_a_inserir) {
    // CORREÇÃO: A verificação de 'cheia' e 'realloc' foi movida para 'inserir_lista'.
    // Esta função agora assume que há espaço.

    int i = 0;
    //encontra a posição correta para o novo valor
    while (i < lista->tamanho && lista->elementos[i] < valor_a_inserir) {
        i++;
    }
    //desloca os elementos maiores para a direita
    for (int j = lista->tamanho; j > i; j--) {
        lista->elementos[j] = lista->elementos[j - 1];
    }
    //insere o novo valor na posição correta
    lista->elementos[i] = valor_a_inserir;
    lista->tamanho++;
}

void inserir_lista(lista_t *lista, const int valor_a_inserir) {
    // A lógica de realocação é centralizada aqui.
    if (verificar_lista_cheia(lista)) {
        lista->capacidade *= 2;
        // CORREÇÃO: 'realloc' recebe o ponteiro dos elementos, não a struct da lista.
        lista->elementos = realloc(lista->elementos, sizeof(int) * lista->capacidade);
        if (lista->elementos == NULL) {
            perror("Erro ao realocar lista");
            exit(1);
        }
    }

    if (lista->ordenada) {
        inserir_ordenada(lista, valor_a_inserir);
    } else {
        inserir_nao_ordenada(lista, valor_a_inserir);
    }
}

int busca_linear(lista_t *lista, int valor_a_buscar) {
    for (int i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i] == valor_a_buscar) {
            return i; //retorna o índice
        }
    }
    return -1;
}

int busca_binaria(lista_t *lista, int valor_a_buscar) {
    int esquerda = 0;
    int direita = lista->tamanho - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (lista->elementos[meio] == valor_a_buscar) {
            return meio;
        }
        if (lista->elementos[meio] < valor_a_buscar) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1;
}


int buscar_elementos_lista(lista_t *lista, int valor_a_buscar) {
    if (lista->ordenada) {
        return busca_binaria(lista, valor_a_buscar);
    } else {
        return busca_linear(lista, valor_a_buscar);
    }
}

int buscar_na_posicao_lista(lista_t *lista, int posicao) {
    // CORREÇÃO: Adicionada verificação de limites
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Erro: Posicao %d invalida.\n", posicao);
        return -1; // Retorna um valor de erro
    }
    return lista->elementos[posicao]; // retornando o valor que o indice está indicando
}

// implementação lab 8
void inserir_na_posicao_lista(lista_t *lista, int valor_a_inserir, int posicao) {
    // CORREÇÃO: Inserir por posição quebra a ordenação.
    if (lista->ordenada) {
        printf("'inserir_na_posicao_lista' nao e permitido em listas ordenadas.\n");
        printf("Use 'inserir_lista()' para manter a ordem.\n");
        return;
    }

    // Garante espaço (lógica de 'inserir_lista')
    if (verificar_lista_cheia(lista)) {
        lista->capacidade *= 2;
        lista->elementos = realloc(lista->elementos, sizeof(int) * lista->capacidade);
        if (lista->elementos == NULL) {
            perror("Erro ao realocar lista");
            exit(1);
        }
    }

    int i_pos;
    // Limita a posição: 0 <= i_pos <= tamanho
    // (inserir na posição 'tamanho' é válido, significa inserir no final)
    if (posicao < 0) i_pos = 0; // se negativa vai se a primeira posicao
    else if (posicao > lista->tamanho) i_pos = lista->tamanho; // se maior que a lista vai ser o último elemento
    else i_pos = posicao; // caso correto que o indice recebe a posicao indicada pelo usuario

    // Desloca os elementos para a direita
    for (int j = lista->tamanho; j > i_pos; j--) { // percorre de trás para frente
        lista->elementos[j] = lista->elementos[j - 1];
    }

    lista->elementos[i_pos] = valor_a_inserir;
    lista->tamanho++;
}


void remover_elemento_lista(lista_t *lista, int valor_a_remover) {
    if (verificar_lista_vazia(lista)) {
        return;
    }

    int indice = buscar_elementos_lista(lista, valor_a_remover);

    if (indice < 0) {
        printf("Aviso: Valor %d nao encontrado para remocao.\n", valor_a_remover);
        return;
    }

    // A lógica original está correta
    if (lista->ordenada) {
        // Desloca para a esquerda
        for (int i = indice; i < lista->tamanho - 1; i++) {
            lista->elementos[i] = lista->elementos[i + 1];
        }
    } else {
        //para listas não ordenadas vamos substituir pelo último (mais rápido)
        lista->elementos[indice] = lista->elementos[lista->tamanho - 1];
    }
    lista->tamanho--;
}

// implementacao remocao de elemento na lista
void remover_na_posicao_lista(lista_t *lista, int posicao) {
    if (verificar_lista_vazia(lista)) {
        return;
    }

    // Valida o índice (0 <= posicao < tamanho)
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posicao %d invalida para remocao.\n", posicao);
        return;
    }

    //  Lógica de remoção por posicao
    if (lista->ordenada) {
        // Desloca para a esquerda no caso de ordenada
        for (int i = posicao; i < lista->tamanho - 1; i++) {
            lista->elementos[i] = lista->elementos[i + 1];
        }
    } else {
        // Substitui pelo último quando não ordenada
        lista->elementos[posicao] = lista->elementos[lista->tamanho - 1];
    }
    lista->tamanho--;
}

//Imprime o primeiro elemento da lista e o tamanho da lista
void imprimir_primeiro_e_tamanho(lista_t *lista) {
    if (verificar_lista_vazia(lista)) {
        printf("A lista esta vazia.\n");
    } else {
        printf("Primeiro elemento: %d | Tamanho atual: %d\n", lista->elementos[0], lista->tamanho);
    }
}

//Imprime todos os números da lista
void imprimir_lista_completa(lista_t *lista) {
    if (verificar_lista_vazia(lista)) {
        printf("A lista esta vazia.\n");
        return;
    }
    printf("Elementos: [ ");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i]);
    }
    printf("]\n");
}
