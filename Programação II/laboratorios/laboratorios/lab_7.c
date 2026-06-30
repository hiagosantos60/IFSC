#include <stdio.h>
#include "libprg/libprg.h"
void lab_7() {
    printf("\n --- Lab 7 --- \n");
    no_t* lista = NULL;

    printf(" inserindo elementos \n");
    inserir_elemento_lista_encadeada(&lista, 30);
    inserir_elemento_lista_encadeada(&lista, 20);
    inserir_elemento_lista_encadeada(&lista, 10);
    listar_lista_encadeada_lab_7(lista);

    no_t* encontrado = buscar_elementos_lista_encadeada(lista, 10);
    if (encontrado != NULL) {
        printf("\n Elemento 10 encontrado.\n");
    } else {
        printf("Elemento 10 NAO encontrado.\n");
    }

    printf("\n removendo o elemento do meio (20) ---\n");
    remover_elementos_lista_encadeada(&lista, 20);
    listar_lista_encadeada_lab_7(lista);

    printf("\n destruindo lista\n");
    destruir_lista_ligada(&lista);
    listar_lista_encadeada_lab_7(lista);

    printf("\n --- Fim Lab 7 --- \n");
}