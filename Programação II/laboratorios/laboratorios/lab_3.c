#include "headers/lab_3.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libprg/libprg.h>

double operacoes(double num_a, double num_b, char operador) {
    double resultado;

    if (operador == '+') {
        resultado = num_a + num_b;
    } else if (operador == '-') {
        resultado = num_a - num_b;
    } else if (operador == '*') {
        resultado = num_a * num_b;
    } else if (operador == '/') {
        resultado = num_a / num_b;
    } else if (operador == '^') {
        resultado = pow(num_a, num_b);
    } else if (operador == '%') {
        resultado = fmod(num_a, num_b);
    } else {
        printf("Problema na operação: operador %c não reconhecido\n", operador);
        return -1;
    }
    return resultado;
}

//notacao_polonesa_reversa
void lab_3() {
    printf("\n --- Lab 3 --- \n");

    pilha_t *entrada_usuario = criar_pilha(50);
    char entrada[20];
    int continuar = 1;

    printf("Digite sua operação em Notação polonesa reversa (digite '=' no final da expressão para calcular):\n");
    printf("Exemplo: 3 2 + = \n \n");

    while (continuar) {
        scanf("%s", entrada);

        if (entrada[0] == '=') {
            continuar = 0;
        } else if (entrada[0] == '+' || entrada[0] == '-' ||
                   entrada[0] == '*' || entrada[0] == '/' ||
                   entrada[0] == '%' || entrada[0] == '^') {

            double b = desempilhar(entrada_usuario);
            double a = desempilhar(entrada_usuario);

            double resultado = operacoes(a, b, entrada[0]);

            empilhar(entrada_usuario, resultado);
                   } else {
                       int numero = atoi(entrada);
                       empilhar(entrada_usuario, numero);
                   }
    }

    double resultado_final = desempilhar(entrada_usuario);
    printf("Resultado: %.6f\n", resultado_final);

    destruir_pilha(entrada_usuario);

    printf("\n --- Fim Lab 3 --- \n");
}