#include <stdio.h>
#include <stdlib.h>
#include "limpa.h"

void limpa_peca(char **peca)
{
    int i, j;

    for(i = 0; i<4; i++)
    {
        for(j = 0; j<4; j++)
        {
            peca[i][j] = 0;
        }
    }
}

void limpa_matriz(unsigned char **matrizPrincipal)
{
    int i, j;
    for(i = 0; i<21; i++)
    {
        for(j = 0; j<17; j++)
        {
            matrizPrincipal[i][j] = 0;
        }
    }
}
