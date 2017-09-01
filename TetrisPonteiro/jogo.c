#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "pecas.h"
#include "verificaQuadrado.h"
#include "jogo.h"
#include "rotacao.h"
#include "pecas.h"
#include "limpa.h"
#include "gotoxy.h"
#include "translocar.h"
#include "tabuleiro.h"
#include "localPeca.h"
#include "apagarLinha.h"
#include "localPeca.h"
#include "movimentoPeca.h"
#include "menu.h"
#include "ranking.h"
#define BLOCO 6

int x = 6,y = 0,pontos = 0,contador = 0,cor;
void jogar()
{
    unsigned char **matrizPrincipal,pecinha = 219;
    char **peca;
    char botao_rot_andar;
    int i, gameover = 0,level = 1,tempo = 500;

    peca = malloc(4*sizeof(char*));
    for(i = 0; i < 4; i++)
    {
        peca[i] = malloc(4*sizeof(char));
    }

    matrizPrincipal = (unsigned char**) malloc(21*sizeof(unsigned char*));
    for(i = 0;i < 21;i++)
    {
        matrizPrincipal[i] = malloc(17*sizeof(unsigned char));
    }

    limpa_peca(peca);
    pecas_random(peca);
    limpa_matriz(matrizPrincipal);
    tabuleiro(matrizPrincipal,pecinha);
    peca_na_tela(peca);
    pontos = 0;
    contador = 0;

    while(gameover == 0)
    {
        gotoxy(18,1);
        textcolor(6);
        printf("Score: %d",pontos);
        gotoxy(18,3);
        textcolor(6);
        printf("Level: %d",level);

        for(i = 0;i<44;i++)
        {
            gotoxy(i,21);
            putchar(0);
        }
        if(!kbhit() && verifica_quadrado(matrizPrincipal,peca,pecinha) == 0)
        {
            Sleep(tempo);
            descer_peca(matrizPrincipal,peca,pecinha);
        }else
        {
            botao_rot_andar = getch();

            if ((botao_rot_andar == 'a' || botao_rot_andar == 'A') && verifica_quadrado(matrizPrincipal,peca,pecinha) == 0)
            {
                if(verifica_quadrado_coluna_esquerda(matrizPrincipal,pecinha) == 1)
                {
                    translocar_peca_coluna_esquerda(peca);
                }
                else
                {
                    mover_esquerda(matrizPrincipal,peca,pecinha);
                }
            }
            else if ((botao_rot_andar == 'd' || botao_rot_andar == 'D') && verifica_quadrado(matrizPrincipal,peca,pecinha) == 0)
            {
                if(verifica_quadrado_coluna_direita(matrizPrincipal,pecinha) == 1)
                {
                    translocar_peca_coluna_direita(peca);
                }
                else
                {
                    mover_direita(matrizPrincipal,peca,pecinha);
                }
            }
            else if ((botao_rot_andar == 's' || botao_rot_andar == 'S') && (verifica_quadrado(matrizPrincipal,peca,pecinha) == 0))
            {
                descer_peca(matrizPrincipal,peca,pecinha);
            }
            else if ((botao_rot_andar == 'r' || botao_rot_andar == 'R') && (verifica_quadrado(matrizPrincipal,peca,pecinha) == 0))
            {
                rotacao_direita(peca);
            }
            else if (botao_rot_andar == 27)
            {
                gotoxy(0,21);
                exit(0);
            }
            else if (botao_rot_andar == 'p'|| botao_rot_andar == 'P')
            {
                gotoxy(0,21);
                system("pause");
            }
        }
        if (verifica_quadrado(matrizPrincipal,peca,pecinha) == 1)
        {
            peca_na_matriz(matrizPrincipal,peca);
            apagar_linha(matrizPrincipal,pecinha);
            x = 6;
            y = 0;
            limpa_peca(peca);
            pecas_random(peca);
            peca_na_tela(peca);
        }
        if(matrizPrincipal[2][6] == BLOCO || matrizPrincipal[2][7] == BLOCO|| matrizPrincipal[2][8]== BLOCO || matrizPrincipal[2][9]== BLOCO)
        {
            pontos-=10;
            system("cls");
            gameover = 1;
        }
        if(contador >= 1000)
        {
            level+=1;
            tempo-=50;
            contador-=1000;
        }
        if(tempo <= 200)
        {
            tempo = 200;
        }
    }
    fim_de_jogo(pontos);
}

void fim_de_jogo(int pontos)
{
    int contador = 0;
    char setinha;
do{
printf("   _____           __  __ ______     ____ __      __  ______ _____  \n");
printf("  / ____|   /\\    |  \\/  |  ____|   / __ \\\\ \\    / / |  ____|  __ \\ \n");
printf(" | |  __   /  \\   | \\  / | |__     | |  | |\\ \\  / /  | |__  | |__) |\n");
printf(" | | |_ | / /\\ \\  | |\\/| |  __|    | |  | | \\\ \\\/ /   |  __| |  _  / \n");
printf(" | |__| |/ ____ \\ | |  | | |____   | |__| |  \\  /    | |____| | \\ \\ \n");
printf("  \\_____/_/    \\_\\| |  |_|______|   \\____/    \\/     |______|_|  \\_\\\n");

printf("\t\tVOCE CONSEGUIU %i PONTOS!\n", pontos);
printf("DESEJA ADICIONAR AO RANKING?");

    if(contador == 0){
        printf("\t\t\t>>SIM\n\t\t\t  NAO\n");
    }else if(contador == 1){
        printf("\t\t\t  SIM\n\t\t\t>>NAO");
    }


    setinha = getch();
    switch(setinha){
        case 72:
            contador--;
            break;
        case 80:
            contador++;
            break;
        case 13:
            if(contador == 0){
                system("cls");
                addScore(pontos);
            }else if(contador == 1){
                system("cls");
                restart();
            }

    }
    if(contador<0){
        contador=1;
    }else if(contador>1){
        contador=0;
    }

    system("cls");

}while(setinha != 13);
}

void restart(){
    int contador1 = 0;
    char setinha1;

    do{
    printf("DESEJA REINICIAR O JOGO?\n");

    if(contador1 == 0){
        printf("\t\t\t>>REINICIAR\n\t\t\t  MENU");
    }else if(contador1 == 1){
        printf("\t\t\t  REINICIAR\n\t\t\t>>MENU");
    }


    setinha1 = getch();
    switch(setinha1){
        case 72:
            contador1--;
            break;
        case 80:
            contador1++;
            break;
        case 13:
            if(contador1 == 0){
                system("cls");
                jogar();
            }else if(contador1 == 1){
                system("cls");
                MENU();
            }

    }
    if(contador1<0){
        contador1=1;
    }else if(contador1>1){
        contador1=0;
    }
    system("cls");
    }while(setinha1!=13);
}
