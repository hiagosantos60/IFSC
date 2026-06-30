// Faça um programa que percorra o vetor e imprima o tamanho que o usuário deseja

#include <stdio.h>

int main()
{
    int n = 0; 

    printf("Quantos termos da sequencia você deseja verificar: ");
    scanf("%d", &n);

    int sequencia[n];
    sequencia[0] = 1; //fixa o primeiro termo do array 
    sequencia[1] = 1; //fixa o segundo termo do array

    printf("A sequencia desejada é: \n");

    for (int i = 2; i < n; i++) {
        sequencia[i] = sequencia[i - 1] + sequencia[i - 2];
        //O valor i da sequencia agora vai ser o valor dos dois últimos somados
    }

    printf("A sequência desejada é:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", sequencia[i]);
        //lógica para fazer a impressão certa dos arrays
    }
    printf("\n");

    return 0;
}