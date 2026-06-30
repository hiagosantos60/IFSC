// Defina dois vetores com 5 elementos cada. Faça um algoritmo que 
// calcule e imprima a soma deles. Ou seja, a soma de cada elemento 
// de um vetor pelo elemento correspondente do outro vetor.

#include <stdio.h>

int main() {
    int soma=0;
    int vetor_um[5] = {8,4,2,5,7};
    int vetor_dois[5] = {1,3,6,9,10};
    int vetor_soma[5]= {0,0,0,0,0};

    for (int i=0; i<5; i++) {
        vetor_soma[i] = vetor_um[i] + vetor_dois[i];
    }

    printf("O valor do array resultado da soma entre os dois é: ");
    for (int i=0; i<5; i++) {
        printf("%d ", vetor_soma[i]);
    }
}