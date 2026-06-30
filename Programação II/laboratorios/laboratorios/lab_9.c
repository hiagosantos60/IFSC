//lab 9 recursao interativo e recursivo
#include <stdio.h>
#include "headers/lab9.h"

#include <stdlib.h>

#include "libprg/libprg.h"

int fatorial_interativo (int a) {
    int resultado = 1;
    for (int i = 2; i <= a; i++) {
        resultado = resultado*i;
    }
    return resultado;
}

int fatorial_recursivo (int a) {
    if (a <= 1) return 1;
    return a * fatorial_recursivo(a-1);
}

int fibonacci (int ultimo, int penultimo, int tamanho) {
    if (tamanho == 0) return ultimo;

    int proximo = ultimo + penultimo;

    penultimo = ultimo;
    ultimo = proximo;
    printf("%d ", penultimo);
    return fibonacci(ultimo,penultimo,tamanho - 1);
}

void mostrar_pinos (pilha_t* pilha_a, pilha_t* pilha_b, pilha_t* pilha_c) {

    printf("Pilha A: "); imprimir_pilha(pilha_a); printf("\n");
    printf("Pilha B: "); imprimir_pilha(pilha_b); printf("\n");
    printf("Pilha C: "); imprimir_pilha(pilha_c); printf("\n\n\n");
    printf("---------------------------------------------------------\n");

}

/*
- pilha_a é a origem
- pilha_b é a auxiliar
- pilha_c é o destino
 */

void hanoi(int n, pilha_t* origem, pilha_t* auxiliar, pilha_t* destino, pilha_t* aux_a, pilha_t* aux_b, pilha_t* aux_c) {
    if (n > 0) {
        if (n == 1) {
            int disco = desempilhar(origem);

            empilhar(destino, disco);

            mostrar_pinos(aux_a, aux_b, aux_c);
        }
        else {
            hanoi(n - 1, origem, destino, auxiliar, aux_a, aux_b, aux_c);

            int disco = desempilhar(origem);
            empilhar(destino, disco);

            mostrar_pinos(aux_a, aux_b , aux_c);

            hanoi(n - 1, auxiliar, origem, destino, aux_a, aux_b, aux_c);
        }
    }
}


void lab_9() {
    printf("\n --- Lab 9 --- \n");

    int resultado_fatorial_interativo = fatorial_interativo(6);
    printf("Resultado fatorial interativo = %d \n", resultado_fatorial_interativo);

    int resultado_fatorial_indutivo = fatorial_recursivo(6);
    printf("Resultado fatorial indutivo = %d \n", resultado_fatorial_indutivo);

    int tamanho = 0;
    printf("Qual tamanho da sequencia que você quer: ");
    scanf("%d", &tamanho);
    printf("A sequencia ficou: ");
    fibonacci(0,1,tamanho);
    printf("\n\n\n");

    //-----------------------------------------------------//
    //hanoi
    // quantidade de discos
    printf("--- Problema da torre de hanoi --- \n");

    int n = 10;

    // pinos para movimentar os discos
    pilha_t* pilha_a = criar_pilha(n);
    pilha_t* pilha_b = criar_pilha(n);
    pilha_t* pilha_c = criar_pilha(n);

    // empilhar elementos de 0 a n na pilha_a
    for (int i = n; i > 0 ; i--) {
        empilhar(pilha_a, i);
    }

    hanoi(n, pilha_a, pilha_b, pilha_c, pilha_a, pilha_b, pilha_c); // chama a função de hanoi para trocar o pino

    free(pilha_a);
    free(pilha_b);
    free(pilha_c);

    printf(" \n --- Fim Lab 9 --- \n");
}

