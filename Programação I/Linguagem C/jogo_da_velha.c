#include <stdio.h>

void inicializar_tabuleiro(char tabuleiro[3][3]);
void mostra_tabuleiro(char tabuleiro[3][3]);
int validar_jogada(char tabuleiro[3][3], int linha, int coluna);
int validar_vitoria(char tabuleiro[3][3], char simbolo);
int validar_empate(char tabuleiro[3][3]);


int main () {

    char tabuleiro[3][3];
    int jogo_ativo = 1;
    int linha, coluna;
    int jogador = 1;
    char simbolo;
    
    inicializar_tabuleiro(tabuleiro);

    while (jogo_ativo)
    {
        mostra_tabuleiro(tabuleiro);
     
        if (jogador == 1) 
        {
            simbolo = 'x';
        } else {
            simbolo = 'o';
        }
        
        printf("Jogador %d, simbolo %c entre com a jogada [linha e coluna] de 1 a 3): ", jogador, simbolo);
        scanf("%d %d", &linha, &coluna);

        linha = linha - 1;
        coluna = coluna - 1;
        
        if (validar_jogada(tabuleiro, linha, coluna))
        {
            tabuleiro[linha][coluna] = simbolo;

            if (validar_vitoria(tabuleiro, simbolo))
            {
                mostra_tabuleiro(tabuleiro);

                printf("Jogador %d venceu!", jogador);
                jogo_ativo = 0;
            } else if (validar_empate(tabuleiro)) {
                mostra_tabuleiro(tabuleiro);
                printf("Empate...");
                jogo_ativo = 0;
            } else {
                if (jogador == 1) {
                    jogador = 2;
                } else {
                    jogador = 1;
                } 
            } 
        } else {
            printf("Jogada inválida...");
        }
    }

    return 0;
}

void inicializar_tabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void mostra_tabuleiro(char tabuleiro[3][3])
{
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i<3) 
        {
            printf("---+---+--- \n");
        }
    }
    printf("\n");
}

int validar_jogada(char tabuleiro[3][3], int linha, int coluna)
{
    if (linha >= 0 && linha <= 2 && coluna >= 0 && coluna <= 2 && tabuleiro[linha][coluna] == ' ') //é necessário verificar se o tabulerio ainda está com espaços vazios
    {
        return 1;
    } else {
        return 0;
    }
}


int validar_vitoria(char tabuleiro[3][3], char simbolo) 
{
    for (char i=0; i < 3; i++)
    {
        if (tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo) //verifica linhas
        {
            return 1;
        }
        if (tabuleiro[0][i] == simbolo && tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo) //verifica colunas
        {
            return 0;
        }
    }

    if (tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo) //verrifica primeria diagonal
    {
        return 1;
    }
    if (tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo) //verifica segunda diagonal
    {
        return 1;
    }

    return 0;
}

int validar_empate(char tabuleiro[3][3]) 
{
    for (int  i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(tabuleiro[i][j] == ' ')
            return 0;
        }
    }
    return 1;
}