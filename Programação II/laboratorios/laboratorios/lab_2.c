#include <stdio.h>
#include <stdlib.h>
#include <libprg/libprg.h>

void lab_2() {
    printf("\n --- Lab 2 --- \n");

    pilha_t *minha_pilha = criar_pilha(10);

    for (int i = 1; i <= 10; i++) {
        empilhar(minha_pilha, i);
    }

    printf("Topo da pilha: %d\n", mostrar_topo_pilha(minha_pilha));

    // tamanho correto: topo + 1
    int tamanho = 0;
    int topo_valor = mostrar_topo_pilha(minha_pilha);
    if (topo_valor != -1) { // pilha não está vazia
        // aqui teria que acessar o índice do topo, mas como não expomos a struct,
        // melhor seria ter uma função tamanho_pilha()
        tamanho = 10; // pq empilhamos 10
    }
    printf("Tamanho da pilha: %d\n", tamanho);

    for (int i = 0; i < 3; i++) {
        int removido = desempilhar(minha_pilha);
        printf("Elemento removido: %d\n", removido);
    }

    printf("Pilha atual: ");
    int *copia = mostra_pilha(minha_pilha);
    for (int i = 0; i < tamanho - 3; i++) { // restaram 7
        printf("%d ", copia[i]);
    }
    free(copia);
    printf("\n");

    destruir_pilha(minha_pilha);

    printf("\n --- Fim Lab 2 --- \n");
}
