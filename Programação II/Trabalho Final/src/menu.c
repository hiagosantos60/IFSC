#include <stdio.h>
#include "../include/tree.h"
#include "../include/cdr.h"
#include "../include/hash.h"
#include "../include/menu.h"

// tabela hash com os ramais vai ter 10 buckets
#define TAMANHO_HASH 10
#define ARQUIVO_DADOS "cdr_data.txt"


void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void menu() {
    printf("\n=== SISTEMA DE TELEFONIA (IFSC) ===\n");
    printf("1 - Inserir registro de chamada (RF1)\n");
    printf("2 - Buscar chamadas de um ramal (RF2)\n");
    printf("3 - Listar chamadas por intervalo de datas (RF3)\n");
    printf("4 - Remover registros antigos (RF4)\n");
    printf("5 - Carregar arquivo de teste\n");
    printf("0 - Sair e Salvar (RF5)\n");
    printf("Escolha uma opcao: ");
}

void interface() {

    tabela_hash_t *tabela = th_criar(TAMANHO_HASH);

    printf("Carregando dados do arquivo...\n");
    th_carregar_arquivo(tabela, ARQUIVO_DADOS);

    int opcao = -1; 

    while (opcao != 0) {
        menu();
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: {
                int ramal, duracao;
                long long data_hora;
                char destino[32], tipo[16];

                printf("\n--- Novo Registro ---\n");
                printf("Ramal Origem: ");
                scanf("%d", &ramal);
                limpar_buffer();

                printf("Numero Destino: ");
                scanf("%31[^\n]", destino);
                limpar_buffer();

                printf("Data/Hora (AAAAMMDDHHMM): ");
                scanf("%lld", &data_hora);
                limpar_buffer();

                printf("Duracao (segundos): ");
                scanf("%d", &duracao);
                limpar_buffer();

                printf("Tipo da chamada (Local, LDN, LDI...): ");
                scanf("%15[^\n]", tipo);
                limpar_buffer();

                cdr_t *novo_cdr = criar_cdr(ramal, destino, data_hora, duracao, tipo);
                if (th_inserir_cdr(tabela, novo_cdr)) {
                    printf(">> Sucesso: CDR inserido!\n");
                } else {
                    printf(">> Erro: Falha ao inserir CDR.\n");
                }
                break;
            }

            case 2: {
                int ramal;
                printf("\n--- Buscar por Ramal ---\n");
                printf("Informe o ramal de origem: ");
                scanf("%d", &ramal);
                
                th_listar_cdr(tabela, ramal); 
                break;
            }

            case 3: {
                int ramal;
                long long inicio, fim;
                printf("\n--- Buscar por Intervalo ---\n");
                printf("Ramal: ");
                scanf("%d", &ramal);
                printf("Data Inicial (AAAAMMDDHHMM): ");
                scanf("%lld", &inicio);
                printf("Data Final   (AAAAMMDDHHMM): ");
                scanf("%lld", &fim);

                th_listar_intervalo(tabela, ramal, inicio, fim);
                break;
            }

            case 4: {
                long long data_limite;
                printf("\n--- Remover Registros Antigos ---\n");
                printf("Informe a data limite (AAAAMMDDHHMM): ");
                scanf("%lld", &data_limite);
                printf("Aviso: Todos os registros anteriores a esta data serao apagados.\n");
                
                th_remover_antigos(tabela, data_limite);
                break;
            }

            case 5: {
                printf("\n--- Carregando Arquivo de Teste ---\n");
                th_carregar_arquivo(tabela, "../data/cdr_data.txt");

                break;
            }

            case 0: {
                printf("\nSalvando dados e encerrando...\n");
                th_salvar_arquivo(tabela, ARQUIVO_DADOS);
                th_destruir(tabela);
                printf("Sistema finalizado.\n");
                break;
            }

            default:
                printf("Opcao invalida!\n");
        }
    }
}