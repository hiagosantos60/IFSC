// Faça um programa que percorra o vetor e imprima o maior elemento 

#include <stdio.h>

int main()
{
    int numeros[10] = {7, -30, 0, 150, -8, 2, 1, -11, 9, 4};
    int comp;

    for (int i = 0; i < 10; i++)
    {
        if (numeros[i] > comp)
        {
            comp = numeros[i];
        }
    }

    printf("O maior valor é %d \n", comp);

    return 0;
}