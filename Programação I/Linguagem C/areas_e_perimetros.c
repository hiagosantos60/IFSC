#include <stdio.h>
#include <math.h>

float PI = 3.1415;

float AreaDoRetangulo(float a,float b);
float AreaDoTrianguloQualquer (float base, float altura);
float AreaDoTrianguloRetangulo (float a, float b);
float AreaDoCirculo (float raio);
float PerimetroDoCirculo (float raio);
float MediaDosTresNumeros (float n1,float n2,float n3);
float CalcularHipotenusa (float a, float b);

int main() {

    int opcao;

    printf("Área de um retângulo (1)  \n");
    printf("Área de triâgulo qualquer (2) \n");
    printf("Área do triângulo retângulo (3) \n");
    printf("Área do círculo (4) \n");
    printf("Perímetro do círculo (5) \n");
    printf("Média de três números float (6) \n");
    printf("Hipotenusa de um triângulo retângulo (7) \n");
    printf("O que você deseja fazer: \n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        float a, b, resultado;
        printf("Valor de 'a' (cm): \n");
        scanf("%f", &a);
        printf("Valor de 'b' (cm): \n");
        scanf("%f", &b);
        resultado = AreaDoRetangulo(a,b);
        printf("A área do retângulo é: %.2f (cm) \n", resultado);
    } else if (opcao == 2)
    {
        float base, altura, resultado;
        printf("Valor da base do triângulo (cm) : \n");
        scanf("%f", &base);
        printf("Valor da altura do triângulo (cm): \n");
        scanf("%f", &altura);
        resultado = AreaDoTrianguloQualquer(base, altura);
        printf("A área do triângulo é: %.2f (cm) \n ", resultado);
    } else if (opcao == 3) {
        float a,b,resultado;
        printf("Digite o valor do lado 'a' (cm): \n");
        scanf("%f", &a);
        printf("Digite o valor do lado 'b' (cm): \n");
        scanf("%f", &b);
        resultado = AreaDoTrianguloRetangulo(a,b);
        printf("A área do triângulo retângulo é: %.2f (cm)\n", resultado);
    } else if (opcao == 4) {
        float raio, resultado;
        printf("Qual o valor do raio do círculo (cm): \n");
        scanf("%f", &raio);
        resultado = AreaDoCirculo(raio);
        printf("A área do circulo é %.2f (cm) \n", resultado);
    } else if (opcao == 5) {
        float raio, resultado;
        printf("Qual o valor do raio do círculo (cm): \n");
        scanf("%f", &raio);
        resultado = PerimetroDoCirculo(raio);
        printf("O Perimetro é: %.2f (cm) \n", resultado);
    } else if (opcao == 6) {
        float n1,n2,n3,resultado;
        printf("Qual o valor do primeiro número : \n");
        scanf("%f", &n1);
        printf("Qual o valor do segundo número : \n");
        scanf("%f", &n2);
        printf("Qual o valor do terceiro número : \n");
        scanf("%f", &n3);
        resultado = MediaDosTresNumeros(n1,n2,n3);
        printf("A média dos três números é: %.2f (cm) \n", resultado);
    } else if (opcao == 7) {
        float a, b, hipotenusa;
        printf ("Qual o primeiro cateto (cm): \n");
        scanf("%f", &a);
        printf ("Qual o segundo cateto (cm): \n");
        scanf("%f", &b);
        hipotenusa = CalcularHipotenusa(a,b);
        printf("O valor da hipotenusa é: %.2f (cm)\n", hipotenusa);
    } else {
        printf("OPÇÃO INVÁLIDA!!!");
    }
    

    return 0;
}

float AreaDoRetangulo(float a,float b) {
    return (a*b);
}

float AreaDoTrianguloQualquer (float base, float altura) {
    return (base*altura)/2;
}

float AreaDoTrianguloRetangulo (float a, float b) {
    return (a*b)/2;
}

float AreaDoCirculo (float raio) {
    return (PI*raio*raio);
}

float PerimetroDoCirculo (float raio) {
    return 2*PI*raio;
}

float MediaDosTresNumeros (float n1,float n2,float n3) {
    return (n1+n2+n3)/3;
}

float CalcularHipotenusa (float a, float b) {
    return sqrt((a*a + b*b));
}

