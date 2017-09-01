#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define TAM 8
#include "funcoes.h"




void main()
{
    char tabuleiro [TAM][TAM] = { 0 };
    int jogada[TAM][TAM] = { 0 };
    int linha = 0;
    int coluna = 0;
    int num_jogos = 0;
    int num_jogadas = 0;
    int jog_invalidas = 0;
    int placar_j1 = 0;
    int placar_j2 = 0;
    char y = 0;
    int x = 0;
    char denovo = 0;
    int jogador = 0;
    int continuar;
    char nome_j1[50], nome_j2[50];

    system("color 17");




    do
    {
        system("cls");
        printf("\tJOGO\n\tREVERSI\n\n\n");
        vez=1;
        continuar = menu();
        if(continuar == 1)
        {
            system("cls");
            printf("\nInsira o nome do jogador 1 < O > :  ");
            scanf("%s", &nome_j1);
            fflush(stdin);
            printf("\nInsira o nome do jogador 2 < X > :  ");
            scanf("%s", &nome_j2);
            fflush(stdin);

            /* o jogo */
            do
            {
                /* jogos pares j1 começa */
                /* jogos impares j2 começa */

                jogador = ++num_jogos % 2;
                num_jogadas = 4;


                for(linha = 0; linha < TAM; linha++)
                    for(coluna = 0; coluna < TAM; coluna++)
                        tabuleiro[linha][coluna] = ' ';

                /* coloca as peças iniciais no centro*/
                tabuleiro[TAM/2 - 1][TAM/2 - 1] = tabuleiro[TAM/2][TAM/2] = 'O';
                tabuleiro[TAM/2 - 1][TAM/2] = tabuleiro[TAM/2][TAM/2 - 1] = 'X';


                do
                {
                    mostrar(tabuleiro);
                    if(jogador++ % 2)
                    {

                        if(jog_validas(tabuleiro, jogada, 'O'))
                        {

                            for(;;)
                            {
                                fflush(stdin);
                                printf("Faca sua jogada, %s (linha coluna [ O ]): ", nome_j1);
                                scanf("%d%c", &x, &y);
                                y = tolower(y) - 'a';
                                x--;
                                if( x>=0 && y>=0 && x<TAM && y<TAM && jogada[x][y])
                                {
                                    faz_jogada(tabuleiro, x, y,'O');
                                    num_jogadas++;
                                    break;
                                }
                                else
                                    printf("Movimento invalido, tente novamente.\n");
                            }
                        }
                        else if(++jog_invalidas<2)
                        {
                            fflush(stdin);
                            printf("\Voce tera de passar a vez");
                            scanf("%c", &denovo);
                        }
                        else
                            printf("\nNao ha jogadas validas. Fim de jogo\n");
                    }
                    else
                    {

                        if(jog_validas(tabuleiro, jogada, 'X'))
                        {

                            for(;;)
                            {
                                fflush(stdin);
                                printf("Faca sua jogada, %s (linha coluna [ X ]): ", nome_j2);
                                scanf("%d%c", &x, &y);
                                y = tolower(y) - 'a';
                                x--;
                                if( x>=0 && y>=0 && x<TAM && y<TAM && jogada[x][y])
                                {
                                    faz_jogada(tabuleiro, x, y, 'X');
                                    num_jogadas++;
                                    break;
                                }
                                else
                                    printf("Movimento invalido, tente novamente.\n");
                            }
                        }
                        else if(++jog_invalidas<2)
                        {
                            fflush(stdin);
                            printf("\Voce tera de passar a vez");
                            scanf("%c", &denovo);
                        }
                        else
                            printf("\nNao ha jogadas validas. Fim de jogo\n");
                    }

                }

                while(num_jogadas < TAM*TAM && jog_invalidas<2);

                mostrar(tabuleiro);

                placar_j1 = placar_j2 = 0;
                for(linha = 0; linha < TAM; linha++)
                    for(coluna = 0; coluna < TAM; coluna++)
                    {
                        placar_j1 += tabuleiro[linha][coluna] == 'X';
                        placar_j2 += tabuleiro[linha][coluna] == 'O';
                    }
                printf("O placar final eh:\n");
                printf("%s %d\n    %s %d\n\n",nome_j1, placar_j1, nome_j2, placar_j2);
                if(placar_j1>placar_j2)
                    printf("%s venceu!\n", nome_j1);
                else if(placar_j1=placar_j2)
                         printf("Houve empate!\n");
                     else printf("%s venceu!\n",nome_j2);

                save_pontos(nome_j1, nome_j2,placar_j1, placar_j2);

                fflush(stdin);
                printf("\nGostaria de jogar novamente? (s/n): ");
                scanf("%c", &denovo);
            }
            while(tolower(denovo) == 's');
            printf("\nAte mais!\n");
        }
        else if(continuar == 2)
            get_historico();


    }
    while(continuar);
}


