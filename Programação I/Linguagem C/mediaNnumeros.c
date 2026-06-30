/*Esse desafio consiste em criar um menu de operações e a 6 deve-se oferecer a opção de escolher a quantidade
de números que deseja fazer a média, e apresentar o resultado da média utilizando os conceitos de while loops */

/*

para compilar e testar esse programa:
gcc -Wall mediaNnumeros.c -o teste -lm
./teste

*/

#include <stdio.h>
#include <math.h>

float PI = 3.14;

float area_retangulo(float lado_a, float lado_b);
float area_triangulo(float base, float altura);
float calcular_hipotenusa(float lado_a, float lado_b);
float area_do_circulo(float raio);
float calcular_perimetro(float raio);
float calcular_media(int quantidade);

int main () {
    int i = 0;
    while (i != 9) {
        printf("Digite uma opção: \n");
        printf("1: Área de um retângulo\n");
        printf("2: Área de um triângulo\n");
        printf("3: Hipotenusa:\n");
        printf("4: Área do círculo\n");
        printf("5: Perímetro do círculo\n");
        printf("6: Média de números\n");
        printf("9: Sair \n");
        scanf("%d", &i);

        float lado_a,lado_b,area,raio;
        
        switch (i) {
            case 1:
                printf("Informe os dois lados do retângulo: ");
                scanf("%f %f", &lado_a, &lado_b);
                area = area_retangulo(lado_a,lado_b);
                printf("Área do retângulo: %.2f\n", area);
                break;

            case 2:
                float base,altura;
                printf("Quais são as medidas de base, altura do triângulo: ");
                scanf("%f %f", &base, &altura);
                area = area_retangulo(base, altura); 
                printf("A área do triâgulo é: %.2f\n", area);
                break;

            case 3:
                printf("Entre com os lados do triângulo: ");
                scanf("%f %f", &lado_a, &lado_b);
                float hipotenusa = calcular_hipotenusa(lado_a, lado_b);
                printf("O valor da hipotenusa é: %.2f\n", hipotenusa);
                break;
            
            case 4:
                printf("Entre com o raio do círculo: ");
                scanf("%f", &raio);
                area = area_do_circulo(raio);
                printf("A área do círculo é: %.2f", area);
                break;
            case 5: 
                printf("Entre com o valor do raio");
                scanf("%f", &raio);
                float perimetro = calcular_perimetro(raio);
                printf("O perímetro do círculo é: %.2f", perimetro);
                break;
            case 6:
                int quantidade;
                float media;
                printf("Informe a quantidade de valores que serão utilizados: ");
                scanf("%d", &quantidade);
                media = calcular_media(quantidade);
                printf("A média desses número é: %.2f\n", media);
                break;
        }
    }
}

float area_retangulo(float a, float b) { 
    return a*b;
}

float area_triangulo(float a, float b) {
    return (a*b)/2;
}

float calcular_hipotenusa(float a, float b) {
    return sqrt(a*a + b*b) ;
}

float area_do_circulo(float raio) {
    return PI*raio*raio;
}

float calcular_perimetro(float raio){
    return 2*PI*raio;
}

float calcular_media(int quantidade) {
    float num, total, i=0; 

    while (i < quantidade) {
        printf("Digite o valor a ser calculado: ");
        scanf("%f", &num);
        total = total+num;
        i = i + 1;
    }
    return total/i;
}