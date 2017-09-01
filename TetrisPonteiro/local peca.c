#include <stdio.h>
#include <stdlib.h>
#include "localPeca.h"
#include "gotoxy.h"
#define BLOCO 6

extern int x,y,contador,pontos,cor;

void peca_na_matriz(unsigned char **matrizPrincipal,char **peca)
{
    int i,j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(peca[i][j] == BLOCO)
            {
                matrizPrincipal[y+i][x+j] = BLOCO;
            }
        }
    }
    pontos+=10;
    contador+=10;
}

void peca_na_tela(char **peca)
{
    int i,j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(peca[i][j] == BLOCO)
            {
                gotoxy(x+j,y+i);
                textcolor(cor);
                printf("%c",peca[i][j]);
            }
        }
    }
}
void limpar_tela(char **peca)
{
    int i,j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(peca[i][j] == BLOCO)
            {
                gotoxy(x+j,y+i);
                putchar(0);
            }
        }
    }
}
