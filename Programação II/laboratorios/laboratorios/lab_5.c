#include <stdio.h>
#include "headers/lab_5.h"
#include "libprg/libprg.h"

void lab_5() {
    printf("\n --- Lab 5 --- \n");
    lista_t *minha_lista = criar_lista(15, true);

    inserir_lista(minha_lista, 50);
    inserir_lista(minha_lista, 20);
    inserir_lista(minha_lista, 80);
    inserir_lista(minha_lista, 10);
    inserir_lista(minha_lista, 30);
    inserir_lista(minha_lista, 90);
    inserir_lista(minha_lista, 40);
    inserir_lista(minha_lista, 60);
    inserir_lista(minha_lista, 70);
    inserir_lista(minha_lista, 100);

    imprimir_lista_completa(minha_lista);

    imprimir_primeiro_e_tamanho(minha_lista);

    remover_elemento_lista(minha_lista, 10);
    remover_elemento_lista(minha_lista, 100);
    remover_elemento_lista(minha_lista, 20);

    imprimir_lista_completa(minha_lista);
    imprimir_primeiro_e_tamanho(minha_lista);

    destruir_lista(minha_lista);

    printf("\n --- Fim Lab 5 --- \n");
}