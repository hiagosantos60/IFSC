#include <stdlib.h>
#include "libprg/libprg.h"

//selection_sort
// preciso saber onde está o array e o tamanho dele
void selection_sort(int* arr, int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {

        // encontra o índice do menor elemento (não o valor)
        int min_idx = i; // assume que 'i' é o menor
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // encontramos um menor, atualiza o *índice*
            }
        }

        // faz a troca no final
        if (min_idx != i) {
            int aux = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = aux;
        }
    }
}

//insertion_sort()
void insertion_sort(int* arr, int tamanho) {
    int key = 0;
    int j = 0;

    for (int i=1; i<tamanho; i++) {
        key = arr[i];
        j = i - 1; // vai se o primeiro elemento e o loop começa no segundo elemento

        while (j >= 0 && arr[j] > key) { // enquanto j positivo e ter elementos para ordenar
            arr[j+1] = arr[j]; // vai jogando o elemento para frente até estar ordenado
            j = j - 1; // para o indice mudar
        }

        arr[j+1] = key; // a ultima posição vai receber o key
    }
}

//bubble_sort()
void bubble_sort(int* arr, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho-1; j++) {
            if (arr[j] > arr[j+1]) {
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
}

//merge_sort()
//conquistar
void merge(int* arr, int esquerda, int direita, int meio) {
    int tamanho_esquerda = meio - esquerda + 1;
    int tamanho_direita = direita - meio;
    int tamanho_total = tamanho_direita + tamanho_esquerda;
    int* aux = (int*) malloc(tamanho_total * sizeof(int));

    int i = esquerda; // indicador para parte da esquerda
    int j = meio+1; // indicador para parte da direira
    int k = 0; // indicador para o array aux

    //enquanto o da esquerda for menor que o do meio
    //e enquanto o da indicardor da direita não chega no final do array
    while (i <= meio && j <= direita) {
        if (arr[i] <= arr[j]) { // faz a comparação entre os dois valores indicados
            aux[k] = arr[i];
            i = i + 1;
        } else { // caso contrário
            aux[k] = arr[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= meio) { // se o subarray da parte da direita acabou
        aux[k] = arr[i];
        k = k + 1;
        i = i + 1;
    }

    while (j <= direita) { // se o subarray da parte da esquerda acabou
        aux[k] = arr[j];
        k = k + 1;
        j = j + 1;
    }

    for (int m = esquerda; m <= direita; m++) {
        arr[m] = aux[m - esquerda];
    }

    free(aux);
}

//separar

//esquerda e direita não são valores em si, mas os indicadores de posição
int* merge_sort(int* arr, int esquerda, int direita) {
    if (esquerda < direita) { // ainda estou dentro do array
        int meio = esquerda + (direita - esquerda)/2; //divisão

        // esse codigo irá rodar recusivamente até que tudo esteja dividido
        // essa parte do código se faz possível por conta do call stack
        // o que faz que o compilador saiba onde deve retornar para continuar a operação

        merge_sort(arr, esquerda, meio); // dividir a parte da esquerda
        merge_sort(arr, meio+1, direita); // dividir a parte da direita

        merge(arr, esquerda, direita, meio);
    }
    return arr;
}


//quicksort()
int particiona(int* arr, int inicio, int fim) {
    int pivo = arr[inicio]; // fixa pivo na primeira posição
    int i = inicio; // indice que vamos usar para trocar a posição

    for (int j = inicio + 1; j <= fim; j++) { //loop de comparação que começa no segundo elemento
        if (arr[j] <= pivo) { // no caso do elemento em j for menor ou igual que o pivo
            i++;
            //trocar_posicao
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }

    int aux = arr[inicio];
    arr[inicio] = arr[i];
    arr[i] = aux;

    return i;
}

int* quicksort(int* arr, int inicio, int fim) {
    if (inicio < fim) {
        int p = particiona(arr, inicio, fim);
        quicksort(arr, inicio, p-1);
        quicksort(arr, p+1, fim);
    }
    return arr;
}