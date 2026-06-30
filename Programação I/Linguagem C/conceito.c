/*
Escreva um programa que leia o código de um determinado produto e
mostre a sua classificação.
*/

#include <stdio.h>

int main() {

    char conceito;
    printf("Digite o conceito: ");
    scanf("%c", &conceito);

    if (conceito == 'a') {
        printf("Execelente! \n");
    } else if (conceito == 'b') {
        printf ("Ótimo! \n");
    } else if (conceito == 'c') {
        printf("Bom \n");
    } else if (conceito == 'd') {
        printf("Regular \n");
    } else if (conceito == 'e') {
        printf("Ruim \n");
    } else if (conceito == 'f') {
        printf("Burro dms mano! \n");
    } else {
        printf("Entre com o conceito corretamente...\n");
    }    

    return 0;
}