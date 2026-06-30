#include <stdio.h>
#include <stdlib.h>
#include "libprg/libprg.h"

//implementar pilha
void lab_4() {
    printf("\n --- Lab 4 --- \n");

    fila_t *minha_fila = criar_fila(10);

    enfileirar(minha_fila, 10);
    enfileirar(minha_fila, 20);
    enfileirar(minha_fila, 30);
    enfileirar(minha_fila, 40);
    enfileirar(minha_fila, 50);
    enfileirar(minha_fila, 60);
    enfileirar(minha_fila, 70);
    enfileirar(minha_fila, 80);
    enfileirar(minha_fila, 90);
    enfileirar(minha_fila, 100);

    printf("Topo da fila: %d\n", inicio_fila(minha_fila));
    printf("Tamanho da fila: %d\n\n", tamanho_fila(minha_fila));

    printf("Removendo: %d %d %d\n\n",
           desenfileirar(minha_fila),
           desenfileirar(minha_fila),
           desenfileirar(minha_fila));

    printf("Elementos restantes: ");
    mostrar_elementos(minha_fila);
    printf("\n");

    destruir_fila(minha_fila);

    printf("\n --- Fim Lab 4 --- \n");
}