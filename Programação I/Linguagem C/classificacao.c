#include <stdio.h>

int main() {
    int cod;

    printf("Qual o código do produto? ");
    scanf("%d", &cod);

    switch (cod) {
        case 1:
            printf("Alimento não-perecível\n");
            break;
        case 2:
            printf("Alimento perecível\n");
            break;
        case 3:
            printf("Vestuário\n");
            break;
        case 4:
            printf("Limpeza\n");
            break;
    }

    return 0;
}