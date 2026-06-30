#include <stdio.h>
#include <stdbool.h>
#include "libprg/libprg.h"
#include "headers/lab_6.h"
#include <stdlib.h>

void menu () {
    int opcao = -1;
    lista_t *ptr_lista = NULL;

    while (opcao != 0) {
        system("clear");

        printf("==== Crie sua lista: ==== \n");
        printf(" Criar lista [1] \n");
        printf(" Inserir item [2] \n");
        printf(" Remover item [3] \n");
        printf(" Buscar Item [4] \n");
        printf(" Mostrar lista [5]\n");
        printf(" Destruir lista [6] \n");
        printf(" Encerrar [0]\n");
        printf("Qual operação deseja fazer: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 0:
                printf("Encerrando...\n");
                if (ptr_lista != NULL) {
                    destruir_lista(ptr_lista);
                }
                break;
            case 1:
                if (ptr_lista != NULL) {
                    destruir_lista(ptr_lista);
                }
                int tamanho_da_lista;
                int ordenada_ou_nao;
                printf("Qual o tamanho da lista: ");
                scanf("%d", &tamanho_da_lista);
                printf("Será ordenada? [1] p/sim | [0] p/não : ");
                scanf("%d", &ordenada_ou_nao);
                ptr_lista = criar_lista(tamanho_da_lista, (bool)ordenada_ou_nao);
                break;
            case 2:
                if (ptr_lista == NULL) {
                    printf("A lista precisa ser criada...\n");
                } else {
                    int valor_a_adicionar;
                    printf("Qual o valor que você deseja adicionar: ");
                    scanf("%d", &valor_a_adicionar);
                    inserir_lista(ptr_lista, valor_a_adicionar);
                }
                break;
            case 3:
                if (ptr_lista == NULL) {
                    printf("A lista precisa ser criada...\n");
                } else {
                    int valor_a_remover;
                    printf("Qual valor que você deseja remover: ");
                    scanf("%d", &valor_a_remover);
                    remover_elemento_lista(ptr_lista, valor_a_remover);
                }
                break;
            case 4:
                if (ptr_lista == NULL) {
                    printf("A lista precisa ser criada...\n");
                } else {
                    int valor_a_buscar;
                    printf("Qual valor a buscar: ");
                    scanf("%d", &valor_a_buscar);
                    int indice = buscar_elementos_lista(ptr_lista, valor_a_buscar);
                    if (indice != -1) {
                        printf("Valor encontrado no índice: %d\n", indice);
                    } else {
                        printf("Valor não encontrado na lista.\n");
                    }
                }
                break;
            case 5:
                if (ptr_lista == NULL) {
                    printf("A lista precisa ser criada...\n");
                } else {
                    printf("Sua lista é: ");
                    imprimir_lista_completa(ptr_lista);
                }
                // CORREÇÃO FINAL: Adicionando o break que faltava.
                break;
            case 6:
                if (ptr_lista == NULL) {
                    printf("Aviso: Nenhuma lista para destruir.\n");
                } else {
                    destruir_lista(ptr_lista);
                    ptr_lista = NULL;
                    printf("Lista destruída com sucesso!\n");
                }
                // CORREÇÃO FINAL: Adicionando o break que faltava.
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
}

void lab_6() {
    printf("\n --- Lab 6 --- \n");
    menu();
    printf("\n --- Fim Lab 6 --- \n");
}