#include <stdio.h>
#include "libprg/libprg.h"

void lab_13 () {
    printf("===Lab_13===");

    // instancia a arvore como vazia
    no_avl_t* arvore_avl = NULL;

    // adiciona elementos
    for (int i = 1; i < 21; i++) {
        arvore_avl = inserir_na_arvore_avl(arvore_avl, i);
    }

    arvore_avl = remover_da_arvore_avl(arvore_avl, 5);
    arvore_avl = remover_da_arvore_avl(arvore_avl, 6);
    arvore_avl = remover_da_arvore_avl(arvore_avl, 18);
    arvore_avl = remover_da_arvore_avl(arvore_avl, 15);
    arvore_avl = remover_da_arvore_avl(arvore_avl, 11);

    imprimir_arvore_avl_in_order(arvore_avl);
}