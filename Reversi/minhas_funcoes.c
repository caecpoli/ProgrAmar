
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define TAM 8
#include "funcoes.h"

/**MOSTRA O TABULEIRO**/
void mostrar(char tabuleiro[][TAM])
{
    system("cls");
    int linha  = 0;
    int coluna = 0;
    char indice_coluna = 'a';

    printf("\n ");
    for(coluna = 0 ; coluna<TAM ; coluna++)
        printf("   %c", indice_coluna+coluna);
    printf("\n");


    for(linha = 0; linha < TAM; linha++)
    {
        printf("  +");
        for(coluna = 0; coluna<TAM; coluna++)
            printf("---+");
        printf("\n%2d|",linha + 1);

        for(coluna = 0; coluna<TAM; coluna++)
            printf(" %c |", tabuleiro[linha][coluna]);
        printf("\n");
    }

    printf("  +");
    for(coluna = 0 ; coluna<TAM ; coluna++)
        printf("---+");
    printf("\n");
}

/**VERIFICA SE A JOGADA É VALIDA*/
int jog_validas(char tabuleiro[][TAM], int jogada[][TAM], char jogador)
{
    int linha0 = 0;
    int coluna0 = 0;
    int linha = 0;
    int coluna = 0;
    int x = 0;
    int y = 0;
    int num_jogadas = 0;

    char adversario = (jogador == 'O')? 'X' : 'O';

    for(linha = 0; linha < TAM; linha++)
        for(coluna = 0; coluna < TAM; coluna++)
            jogada[linha][coluna] = 0;


    for(linha = 0; linha < TAM; linha++)
        for(coluna = 0; coluna < TAM; coluna++)
        {
            if(tabuleiro[linha][coluna] != ' ')
                continue;


            for(linha0 = -1; linha0 <= 1; linha0++)
                for(coluna0 = -1; coluna0 <= 1; coluna0++)
                {

                    if(linha + linha0 < 0 || linha + linha0 >= TAM ||
                            coluna + coluna0 < 0 || coluna + coluna0 >= TAM ||
                            (linha0==0 && coluna0==0))
                        continue;


                    if(tabuleiro[linha + linha0][coluna + coluna0] == adversario)
                    {

                        x = linha + linha0;
                        y = coluna + coluna0;


                        for(;;)
                        {
                            x += linha0;
                            y += coluna0;


                            if(x < 0 || x >= TAM || y < 0 || y >= TAM)
                                break;


                            if(tabuleiro[x][y] == ' ')
                                break;

                            if(tabuleiro[x][y] == jogador)
                            {
                                jogada[linha][coluna] = 1;
                                num_jogadas++;
                                break;
                            }
                        }
                    }
                }
        }
    return num_jogadas;
}

/**CALCULA O PLACAR*/
int get_placar(char tabuleiro[][TAM], char jogador)
{
    int placar = 0;
    int linha = 0;
    int coluna = 0;
    char adversario = jogador == 'O' ? 'X' : 'O';

    for(linha = 0; linha < TAM; linha++)
        for(coluna = 0; coluna < TAM; coluna++)
        {
            placar -= tabuleiro[linha][coluna] == adversario;
            placar += tabuleiro[linha][coluna] == jogador;
        }
    return placar;

}


/**FAZ A JOGADA NO TABULEIRO*/
void faz_jogada(char tabuleiro[][TAM], int linha, int coluna, char jogador)
{
    int linha0 = 0;
    int coluna0 = 0;
    int x = 0;
    int y = 0;
    char adversario = (jogador == 'O')? 'X' : 'O';

    tabuleiro[linha][coluna] = jogador;


    for(linha0 = -1; linha0 <= 1; linha0++)
        for(coluna0 = -1; coluna0 <= 1; coluna0++)
        {

            if(linha + linha0 < 0 || linha + linha0 >= TAM ||
                    coluna + coluna0 < 0 || coluna + coluna0 >= TAM ||
                    (linha0==0 && coluna0== 0))
                continue;


            if(tabuleiro[linha + linha0][coluna + coluna0] == adversario)
            {

                x = linha + linha0;
                y = coluna + coluna0;

                for(;;)
                {
                    x += linha0;
                    y += coluna0;


                    if(x < 0 || x >= TAM || y < 0 || y >= TAM)
                        break;


                    if(tabuleiro[x][y] == ' ')
                        break;

                    if(tabuleiro[x][y] == jogador)
                    {
                        while(tabuleiro[x-=linha0][y-=coluna0]==adversario)
                            tabuleiro[x][y] = jogador;
                        break;
                    }
                }
            }
        }
}
/**MENU*/
int menu()
{
    int opcao;
    printf("1. Jogar\n");
    printf("2. Pontuacao\n");
    printf("0. Sair\n");
    do
    {
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
    }
    while(opcao < 0 || opcao > 2);
    return opcao;

}

/**SALVA OS PONTOS DA PARTIDA*/
void save_pontos(char *nome_j1, char *nome_j2, int placar_j1, int placar_j2)
{
    FILE* pontos;
    if(pontos = fopen("pontos_reversi.txt", "r"))
    {
        fclose(pontos);

        pontos = fopen("pontos_reversi.txt", "a");

        fprintf(pontos, " Jogador %s\tPontos  %d\n", nome_j1, placar_j1);
        fprintf(pontos, " Jogador %s\tPontos  %d\n\n", nome_j2, placar_j2);

        fclose(pontos);
    }
    else
    {
        pontos = fopen("pontos_reversi.txt", "a");

        fprintf(pontos, " Jogador %s\tPontos  %d\n", nome_j1, placar_j1);
        fprintf(pontos, " Jogador %s\tPontos  %d\n\n", nome_j2, placar_j2);

        fclose(pontos);
    }
}

/**ABRE O REGISTRO DE PONTOS*/
void get_historico()
{
    system("cls");
    FILE* pontos;
    char aux;
    if(pontos = fopen("pontos_reversi.txt", "r"))
    {
        while((aux = fgetc(pontos)) != EOF)
            putchar(aux);

        fclose(pontos);
    }
    else
        printf("\n\nNao ha historico\n");

    printf("\n\n");
    system("PAUSE");
}
