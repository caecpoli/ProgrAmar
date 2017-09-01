#include <stdio.h>
#include <stdlib.h>
#include "rotacao.h"
#include "localPeca.h"

void rotacao_direita(char **peca)
{
    int i,j;
    char **peca_rotacionada;
    peca_rotacionada = malloc(4*sizeof(char*));
    for(i = 0;i<4;i++)
    {
        peca_rotacionada[i] = malloc(4*sizeof(char));
    }
    limpar_tela(peca);
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            peca_rotacionada[i][j] = peca[i][j];
        }
    }

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            peca[i][j] = peca_rotacionada[3-j][i];
        }
    }
    peca_na_tela(peca);

}

