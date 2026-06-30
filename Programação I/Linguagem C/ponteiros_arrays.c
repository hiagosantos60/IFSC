#include <stdio.h>

int divide_inteiro(int a, int b)
{
    int res = (int)a / b;
    return res;
}

float maior_de_2(float a, float b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int divide_2_par_ou_impar(int *parametro)
{
    if (*parametro % 2 == 0)
    {
        *parametro = (int)*parametro / 2;
        return 0;
    }
    else
    {
        *parametro = (int)*parametro / 2;
        return 1;
    }
}

int divide_n_inteiro(int *dividendo, int divisor)
{
    if (divisor == 0)
    {
        printf("Erro: divisão por zero!\n");
        return -1; // Pode usar um valor que indique erro
    }

    int resto = *dividendo % divisor;
    *dividendo = *dividendo / divisor; // divisão inteira arredondada para baixo
    return resto;
}

void multiplica_array(int array[], int a)
{
    int soma_todos = 0;
    for (int i = 0; i < 5; i++)
    {
        soma_todos += array[i];
        array[i] *= a;
    }

    printf("A soma de todos os números é: %d\n", soma_todos);
    printf("O array resultante das operações é: {");
    for (int j = 0; j < 5; j++)
    {
        printf("%d", array[j]);
        if (j < 4)
            printf(", ");
    }
    printf("}\n");
}

void soma_matrizes(int array_um[], int array_dois[])
{
    for (int i = 0; i < 5; i++)
    {
        array_um[i] = array_um[i] + array_dois[i];
    }
}

int ordena_array_3(int array_tres[], int n)
{
    if (n != 3)
    {
        return -1;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (array_tres[i] > array_tres[j])
            {
                int temp = array_tres[i];
                array_tres[i] = array_tres[j];
                array_tres[j] = temp;
            }
        }
    }

    return 0;
}

int procura_valores(int array_primeiro[], int tam_um, int array_segundo[], int tam_dois) {
    int cont=0;
    
    for(int i=0; i<tam_um; i++) {
        for(int j=0; j<tam_dois; j++) {
            if(array_primeiro[i]==array_segundo[j]) {
                cont = cont+1;
            } 
        }
    }

    return cont;
}

int main()
{

    int opcao;

    printf("\n01 divide_inteiro");
    printf("\n02 maior_de_2");
    printf("\n03 divide_2_par_ou_impar");
    printf("\n04 divide_n_inteiro");
    printf("\n05 multiplica_array");
    printf("\n06 soma_matrizes");
    printf("\n07 ordena_array_3");
    printf("\n08 procura_valor");
    printf("\n09 procura_valores");
    printf("\n10 ordena_2_matrizes_3");
    printf("\n11 ordena_2_matrizes_n");
    printf("\n12 ordena_matriz\n");

    printf("Entre com o número de uma função: ");
    scanf("%d", &opcao);

    int array[] = {1, 2, 3, 4, 5};
    int array_dois[] = {6, 7, 8, 9, 10};
    switch (opcao)
    {
        int a, b;
        float num1, num2;
    case 1:
        printf("Entre com os valores: ");
        scanf("%d %d", &a, &b);
        printf("%d/%d = %d\n", a, b, divide_inteiro(a, b));
        break;
    case 2:
        printf("Entre com o primeiro valor a ser comparado: ");
        scanf("%f", &num1);
        printf("\nEntre com o segundo valor a ser comparado: ");
        scanf("%f", &num2);
        printf("O maior valor é: %.2f\n", maior_de_2(num1, num2));
        break;
    case 3:
        int paramentro, *ptr;
        ptr = &paramentro;
        printf("Entre com o valor do parâmetro: ");
        scanf("%d", &paramentro);
        printf("O valor do retorno é: %d\n", divide_2_par_ou_impar(ptr));
        printf("O valor do parâmetro agora é: %d\n", paramentro);
        break;
    case 4:
        printf("Entre com o valor do dividendo: ");
        scanf("%d", &a);
        printf("Entre com o valor do divisor: ");
        scanf("%d", &b);
        if (b == 0)
        {
            printf("Erro: divisão por zero!\n");
        }
        else
        {
            int resto = divide_n_inteiro(&a, b);
            // podemos observar que o valor do dividendo muda de fato e não é somente uma cópia
            printf("O resultado da divisão inteira (dividendo modificado) é: %d\n", a);
            printf("O resto da divisão é: %d\n", resto);
        }
        break;
    case 5:
        printf("Array antes de ser modificado: {");
        for (int i = 0; i < 5; i++)
        {
            printf("%d", array[i]);
            if (i < 4)
                printf(", ");
        }
        printf("}\n");

        printf("Entre com o valor que deseja multiplicar o Array: ");
        scanf("%d", &a);

        multiplica_array(array, a);

        printf("Array depois de multiplicado pelo parâmetro: {");
        for (int i = 0; i < 5; i++)
        {
            printf("%d", array[i]);
            if (i < 4)
                printf(", ");
        }
        printf("}\n");
        break;
    case 6:
        printf("Os valores dos arrays são: \n");
        printf("Array um: ");
        for (int i = 0; i < 5; i++)
        {
            printf("%d, ", array[i]);
        }

        printf("Array doi: ");
        for (int i = 0; i < 5; i++)
        {
            printf("%d, ", array_dois[i]);
        }

        soma_matrizes(array, array_dois);

        printf("Array somados: ");
        for (int i = 0; i < 5; i++)
        {
            printf("%d, ", array[i]);
        }

        break;
    case 7:
    {
        int n;

        printf("Entre com o tamanho do array: ");
        scanf("%d", &n);

        int array_tres[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &array_tres[i]);
        }

        if (ordena_array_3(array_tres, n) == 0)
        {
            printf("O array ordenado é: ");
            for (int i = 0; i < n; i++)
            {
                printf("%d, ", array_tres[i]);
            }
        }else {
            printf("O array não tem tamanho 3...");
        }
        break;
    }
    case 8:
        printf("Função ainda não implementada\n");
        break;
    case 9:
    {
        int tam_um=0,tam_dois=0;
        
        printf("Qual o tamanho do primeiro array: ");
        scanf("%d", &tam_um);

        int array_primeirio[tam_um];
        
        for (int i = 0; i < tam_um; i++)
        {
            scanf("%d", &array_primeirio[i]);
        }
        
        printf("Qual o tamanho do segundo array: ");
        scanf("%d", &tam_dois);

        int array_segundo[tam_dois];
        
        for (int i = 0; i < tam_dois; i++)
        {
            scanf("%d", &array_segundo[i]);
        }

        printf("Foram encontrados %d numeros iguais entre os arrays.", procura_valores(array_primeirio, tam_um, array_segundo, tam_dois));
    
    }
        break;
    case 10:
        printf("Função ainda não implementada\n");
        break;
    case 11:
    {
        int tam_um=0,tam_dois=0;
        
        printf("Qual o tamanho do primeiro array: ");
        scanf("%d", &tam_um);

        int array_primeirio[tam_um];
        
        for (int i = 0; i < tam_um; i++)
        {
            scanf("%d", &array_primeirio[i]);
        }
        
        printf("Qual o tamanho do segundo array: ");
        scanf("%d", &tam_dois);

        int array_segundo[tam_dois];
        
        for (int i = 0; i < tam_dois; i++)
        {
            scanf("%d", &array_segundo[i]);
        }

        printf("Foram encontrados %d numeros iguais entre os arrays.", procura_valores(array_primeirio, tam_um, array_segundo, tam_dois));
    
    }
        break;
    case 12:
        printf("Função ainda não implementada\n");
        break;
    default:
        printf("Opção inválida\n");
        break;
    }

    return 0;
}
