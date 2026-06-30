/*
Codifique um programa que faça a leitura de dois número reais. A seguir o programa lê um caractere, que deve ser +, -, * ou /, e realiza a operação indicada pelo caractere sobre os valores lidos;
O programa deve imprimir o resultado da operação realizada sobre eles, como mostra o exemplo a seguir (exibindo exatamente duas casas decimais):
Resultado: 4.50 + 5.00 = 9.50
Seu programa deve usar o comando switch.
*/

#include <stdio.h>

int main() {
    float n1, n2, resultado;
    char opcao;
    
    printf("Primeiro valor: ");
    scanf("%f", &n1);

    printf("Qual operação você deseja fazer: \n");
    printf("Soma(+) \n");
    printf("Subtração(-) \n");
    printf("Multiplicação(*) \n");
    printf("Divisão(/) \n");
    scanf(" %c", &opcao);

    printf("Segundo valor: ");
    scanf("%f", &n2);

    switch (opcao) {
        case '+':
            resultado = (n1+n2);
            break;
        case '-':
            resultado = (n1-n2);
            break; 
        case '*':
            resultado = (n1*n2);
            break;
        case '/':
            resultado = (n1/n2);
            break;
    } 

    printf("O resultado é: %.2f \n", resultado);
}
