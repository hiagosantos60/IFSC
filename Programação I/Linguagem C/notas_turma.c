/*
Leia a nota de 38 alunos de uma turma e calcule a média das notas, a maior e a menor nota.
*/

#include <stdio.h>

int main()
{
    float notas[38] = {
        6.8, 7.5, 9.2, 5.4, 8.1, 4.3, 7.9, 6.0, 3.6, 2.4,
        8.9, 5.7, 7.1, 9.0, 6.3, 7.6, 4.8, 3.2, 9.5, 5.1,
        8.3, 6.6, 7.2, 4.0, 2.9, 6.5, 5.8, 3.9, 9.8, 7.7,
        8.4, 6.9, 5.6, 4.6, 3.7, 7.3, 6.2, 5.0
    };
    float maior_nota = notas[0], menor_nota = notas[0], media = 0, media_turma;
    //nessa lógica, coloquei a maior nota e a menor nota como a primeira nota do vetor, assim o for loop fará todas as comparações das notas e irá entrar a menor e a maior.

    for (int i = 0; i < 38; i++) {
        if (notas[i] > maior_nota) {
            maior_nota = notas[i];
        }
        if (notas[i] < menor_nota) {
            menor_nota = notas[i];
        }

        media = media + notas[i];
    }

    media_turma = media / 38;

    printf("A média da turma é %.2f\n", media_turma);
    printf("A maior nota é: %.2f\n", maior_nota);
    printf("A menor nota é %.2f\n", menor_nota);

    return 0;
}
