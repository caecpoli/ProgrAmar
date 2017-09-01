#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "menu.h"
#include "jogo.h"
#define Enter 13

void Instrucoes()
{
    setlocale(LC_ALL,"Portuguese");
    char setinha;
    int contador=0;

    do
    {
        printf("\n\t\tINSTRUCOES:\n\n");
        printf("\t\tO objetivo do jogo é completar linhas com os blocos que estão caindo\n");
        printf("\t\tQuanto mais linhas forem preenchidas mais pontos você ganhará\n");
        printf("\t\tPara rotacionar as peças utilize a tecla 'R'\n");
        printf("\t\tPara deslocar a peça para a esquerda utilize a tecla 'A'\n");
        printf("\t\tPara deslocar a peça para a direita utilize a tecla 'D'\n");
        printf("\t\tCaso deseje que a peça desca mais rápido pressione a tecla 'S'\n");
        printf("\t\tSe precisar pausar o jogo pressione a tecla 'P'\n");
        printf("\t\tSe quiser fechar o jogo aperte a tecla 'Esc'\n");


        contador==0? printf("\n\n\n\n\n\n\n\n\t\t\t\t>>Jogar \n\t\t\t\t  Retornar ao menu \n\t\t\t\t  Sair"):0;
        contador==1? printf("\n\n\n\n\n\n\n\n\t\t\t\t  Jogar \n\t\t\t\t>>Retornar ao menu \n\t\t\t\t  Sair"):0;
        contador==2? printf("\n\n\n\n\n\n\n\n\t\t\t\t  Jogar \n\t\t\t\t  Retornar ao menu \n\t\t\t\t>>Sair"):0;
        setinha=getch();

        switch(setinha)
        {
        case 72:
            contador--;
            break;
        case 80:
            contador++;
            break;
        case Enter:
            if(contador==0)
            {
                system("cls");
                jogar();
            }
            if(contador==1)
            {
                system("cls");
                MENU();
            }
            if(contador==2)
            {
                exit(0);
            }
        }
        if(contador<0)
            contador=2;
        if(contador>2)
            contador=0;

        system("cls");

    }
    while(setinha != Enter);

}
