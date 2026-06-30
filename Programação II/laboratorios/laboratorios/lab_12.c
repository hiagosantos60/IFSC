#include <stdio.h>
#include <libprg/libprg.h>

void lab_12 () {
    printf("\n --- Lab 12 --- \n");

    no_arvore* raiz = NULL;

    int valores[] = {50, 30, 20, 40, 70, 60, 80, 10, 90, 35};

    for(int i = 0; i < 10; i++) {
        raiz = inserir_valor_arvore(raiz, valores[i]);
        printf("Inserido: %d\n", valores[i]);
    }

    int maior_resultado = maior_valor_arvore(raiz);
    printf("Maior valor na arvore: %d\n", maior_resultado);

    int menor_resultado = menor_valor_arvore(raiz);
    printf("Menor valor na arvore: %d\n", menor_resultado);

    int tamanho_arvore = altura_arvore(raiz);
    printf("A altura da árvore é %d: \n", tamanho_arvore);

    printf("\n --- Fim Lab 12 --- \n");
}