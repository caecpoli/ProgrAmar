#include <stdio.h>
#include <stdlib.h>
#include "verificaQuadrado.h"
#define BLOCO 6

extern int x,y;

int verifica_quadrado(unsigned char **matrizPrincipal,char **peca,unsigned char pecinha)
{
    int i,j;
    for(i = 3; i >= 0; i--)
    {
        for(j = 3; j >= 0; j--)
        {
            if((peca[i][j] == BLOCO) && (matrizPrincipal[y+i+1][x+j] == BLOCO || matrizPrincipal[y+i+1][x+j] == pecinha))
            {
                return 1;
            }
        }
    }
    return 0;
}

int verifica_quadrado_coluna_direita(unsigned char **matrizPrincipal,unsigned char pecinha)
{
    int i,controlador;
    for(i = 0; i < 4;++i)
    {
        if(matrizPrincipal[y+i][x+4] == BLOCO || matrizPrincipal[y+i][x+4] == pecinha)
        {
            controlador = 1;
        }
        else
            controlador = 0;
    }
     return controlador;
}

int verifica_quadrado_coluna_esquerda(unsigned char **matrizPrincipal,unsigned char pecinha)
{
    int i,controlador;
    for(i = 0; i < 4;i++)
    {
        if(matrizPrincipal[y+i][x-1] == BLOCO || matrizPrincipal[y+i][x-1] == pecinha)
        {
            controlador = 1;
        }
        else
            controlador = 0;
    }
    return controlador;
}
