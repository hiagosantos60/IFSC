/*
Escreva um programa que indique o número de dias existentes em um mês
*/

#include <stdio.h>

int main () {
    int n;
    printf("Qual o número do mês: ");
    scanf("%d", &n);

    switch (n) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("O mês escolhido tem 31 dias. \n");
            break;
        case 4: case 6: case 9: case 11:
            printf("O mês tem 30 dias \n");
            break;
        case 2:
            printf("O mês tem 28 dias. \n");
            break;
        default:
            printf("Inválido.\n");
            break;
    }
    return 0;
}