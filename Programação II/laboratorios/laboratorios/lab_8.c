#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "headers/lab8.h"
#include <libprg/libprg.h>

/**
 * @brief Imprime um cabeçalho padronizado para cada seção de teste.
 */
void imprimir_cabecalho(const char* titulo) {
    printf("\n==========================================\n");
    printf("--- Testando %s ---\n", titulo);
    printf("==========================================\n");
}

void testar_lista_linear() {
    imprimir_cabecalho("Lista Linear (NAO Ordenada)");
    lista_t *lista_nao_ord = criar_lista(3, false); // Capacidade inicial 3

    printf("Inserindo 3 elementos:\n");
    inserir_lista(lista_nao_ord, 10);
    inserir_lista(lista_nao_ord, 20);
    inserir_lista(lista_nao_ord, 30);
    imprimir_lista_completa(lista_nao_ord);

    printf("\nTestando realocacao (inserindo 4o elemento):\n");
    inserir_lista(lista_nao_ord, 40);
    imprimir_lista_completa(lista_nao_ord);

    printf("\nTestando insercao por posicao (0, 3 e 99):\n");
    inserir_na_posicao_lista(lista_nao_ord, 5, 0);   // Início
    inserir_na_posicao_lista(lista_nao_ord, 99, 3);  // Meio
    inserir_na_posicao_lista(lista_nao_ord, 111, 99); // Fim (posicao > total)
    imprimir_lista_completa(lista_nao_ord);

    printf("\nTestando remocao por posicao (nao ordenada) (pos 3, 0 e 4):\n");
    remover_na_posicao_lista(lista_nao_ord, 3); // Remove 99
    imprimir_lista_completa(lista_nao_ord);
    remover_na_posicao_lista(lista_nao_ord, 0); // Remove 5
    imprimir_lista_completa(lista_nao_ord);
    remover_na_posicao_lista(lista_nao_ord, 4); // Remove 30 (último)
    imprimir_lista_completa(lista_nao_ord);

    printf("\nTestando remocao por valor (10):\n");
    remover_elemento_lista(lista_nao_ord, 10);
    imprimir_lista_completa(lista_nao_ord);

    printf("\nTestando buscas (nao ordenada):\n");
    printf("Posicao do 20 (linear): %d\n", buscar_elementos_lista(lista_nao_ord, 20));
    printf("Valor na posicao 1: %d\n", buscar_na_posicao_lista(lista_nao_ord, 1));
    destruir_lista(lista_nao_ord);

    // --- Parte Ordenada ---
    imprimir_cabecalho("Lista Linear (ORDENADA)");
    lista_t *lista_ord = criar_lista(5, true);

    printf("Inserindo 4 elementos (fora de ordem):\n");
    inserir_lista(lista_ord, 20);
    inserir_lista(lista_ord, 10);
    inserir_lista(lista_ord, 40);
    inserir_lista(lista_ord, 30);
    imprimir_lista_completa(lista_ord); // Deve imprimir [ 10 20 30 40 ]

    printf("\nTestando insercao por posicao (deve falhar em lista ordenada):\n");
    inserir_na_posicao_lista(lista_ord, 99, 1);
    imprimir_lista_completa(lista_ord); // Sem mudança

    printf("\nTestando busca binaria (ordenada):\n");
    printf("Posicao do 30 (binaria): %d\n", buscar_elementos_lista(lista_ord, 30));

    printf("\nTestando remocao por posicao (ordenada) (pos 1):\n");
    remover_na_posicao_lista(lista_ord, 1); // Remove 20 (deve deslocar)
    imprimir_lista_completa(lista_ord);

    printf("\nTestando remocao por valor (40):\n");
    remover_elemento_lista(lista_ord, 40);
    imprimir_lista_completa(lista_ord);

    destruir_lista(lista_ord);
    printf("\n--- Teste Lista Linear Concluido ---\n");
}

void testar_lista_encadeada_simples() {
    imprimir_cabecalho("Lista Encadeada (SIMPLES)");
    no_t* lista_simples = NULL;

    printf("Inserindo 3 elementos (inicio):\n");
    inserir_elemento_lista_encadeada(&lista_simples, 10);
    inserir_elemento_lista_encadeada(&lista_simples, 20);
    inserir_elemento_lista_encadeada(&lista_simples, 30);
    listar_lista_encadeada_lab_7(lista_simples); // Esperado: [ 30 20 10 ]

    printf("\nTestando insercao por posicao (0, 2 e 99):\n");
    inserir_na_posicao_lista_encadeada(&lista_simples, 5, 0);   // Início
    inserir_na_posicao_lista_encadeada(&lista_simples, 99, 2);  // Meio
    inserir_na_posicao_lista_encadeada(&lista_simples, 111, 99); // Fim
    listar_lista_encadeada_lab_7(lista_simples);

    printf("\nTestando remocao por posicao (0, 2 e 3):\n");
    remover_na_posicao_lista_encadeada(&lista_simples, 0); // Início
    listar_lista_encadeada_lab_7(lista_simples);
    remover_na_posicao_lista_encadeada(&lista_simples, 2); // Meio
    listar_lista_encadeada_lab_7(lista_simples);
    remover_na_posicao_lista_encadeada(&lista_simples, 3); // Fim
    listar_lista_encadeada_lab_7(lista_simples);

    printf("\nTestando busca (99):\n");
    no_t* achado = buscar_elementos_lista_encadeada(lista_simples, 99);
    if (achado != NULL) {
        printf("Busca por 99: Encontrado (ponteiro nao nulo).\n");
    } else {
        printf("Busca por 99: Nao encontrado (ponteiro nulo).\n");
    }

    printf("\nTestando remocao por valor (99):\n");
    remover_elementos_lista_encadeada(&lista_simples, 99);
    listar_lista_encadeada_lab_7(lista_simples);

    printf("\nDestruindo lista:\n");
    destruir_lista_ligada(&lista_simples);
    listar_lista_encadeada_lab_7(lista_simples); // Deve imprimir lista vazia
    printf("\n--- Teste Lista Simples Concluido ---\n");
}

void testar_lista_encadeada_dupla() {
    imprimir_cabecalho("Lista Encadeada (DUPLA)");
    no_duplo_t* lista_dupla = NULL;

    printf("Inserindo 3 elementos:\n");
    adicionar_na_lista_encadeada_dupla(&lista_dupla, 10);
    adicionar_na_lista_encadeada_dupla(&lista_dupla, 20);
    adicionar_na_lista_encadeada_dupla(&lista_dupla, 30);

    // Funções de impressão e destruição específicas parecem
    // não estar disponíveis no 'libprg.h', por isso foram omitidas.
    printf("[Impressao da lista dupla nao disponivel no .h]\n");

    printf("\nTestando busca (20):\n");
    no_duplo_t* achado = buscar_na_lista_encadeada_dupla(lista_dupla, 20);
    if (achado != NULL) {
        printf("Busca por 20: Encontrado (ponteiro nao nulo).\n");
    } else {
        printf("Busca por 20: Nao encontrado (ponteiro nulo).\n");
    }

    printf("\nTestando remocao por valor (20, 30, 10):\n");
    remover_da_lista_encadeada_dupla(&lista_dupla, 20); // Meio
    remover_da_lista_encadeada_dupla(&lista_dupla, 30); // Início
    remover_da_lista_encadeada_dupla(&lista_dupla, 10); // Único
    printf("[Remocoes concluidas, lista deve estar vazia]\n");

    printf("\n--- Teste Lista Dupla Concluido ---\n");
}

void testar_lista_encadeada_circular() {
    imprimir_cabecalho("Lista Encadeada (CIRCULAR)");
    no_t* lista_circular = NULL;

    printf("Inserindo 3 elementos:\n");
    inserir_elemento_lista_encadeada_circular(&lista_circular, 10);
    inserir_elemento_lista_encadeada_circular(&lista_circular, 20);
    inserir_elemento_lista_encadeada_circular(&lista_circular, 30);

    // A função 'listar_lista_encadeada_lab_7' não é apropriada
    // para listas circulares, pois causaria um loop infinito.
    printf("[Impressao omitida para evitar loop infinito]\n");

    printf("\nTestando insercao por posicao (0 e 2):\n");
    inserir_na_posicao_lista_circular(&lista_circular, 5, 0);  // Início
    inserir_na_posicao_lista_circular(&lista_circular, 99, 2); // Meio
    printf("[Insercoes concluidas]\n");

    printf("\nTestando remocao por posicao (0, 2 e 2):\n");
    remover_na_posicao_lista_circular(&lista_circular, 0); // Início
    remover_na_posicao_lista_circular(&lista_circular, 2); // Meio
    remover_na_posicao_lista_circular(&lista_circular, 2); // Fim
    printf("[Remocoes concluidas]\n");

    destruir_lista_ligada_circular(&lista_circular);
    printf("\n--- Teste Lista Circular Concluido ---\n");
}

// Esta função chama todas as outras
void lab8() {
    printf("\n --- Lab 8 --- \n");

    testar_lista_linear();
    testar_lista_encadeada_simples();
    testar_lista_encadeada_dupla();
    testar_lista_encadeada_circular();

    printf("\n --- Fim Lab 8 --- \n");

}