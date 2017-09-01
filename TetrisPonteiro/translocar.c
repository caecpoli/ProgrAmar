#include <stdio.h>
#include <stdlib.h>
#include "translocar.h"
#include "limpa.h"
#include "localPeca.h"
#define BLOCO 6

void translocar_peca_coluna_esquerda(char **peca)
{
    int i,j;
    char **nova_peca;
    nova_peca = malloc(4*sizeof(char*));
    for(i=0;i<4;i++)
    {
        nova_peca[i] = malloc(4*sizeof(char));
    }
    limpar_tela(peca);
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(peca[0][0] == BLOCO || peca[1][0] == BLOCO || peca[2][0] == BLOCO || peca[3][0] == BLOCO)
            {
                nova_peca[i][j] = peca[i][j];
            }
            else if (peca[i][j] == BLOCO)
            {
                nova_peca [i][j-1] = BLOCO;
            }
        }
    }
    for(i = 0; i<4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            peca[i][j] = nova_peca[i][j];
        }
    }
    limpa_peca(nova_peca);
    peca_na_tela(peca);
}

void translocar_peca_coluna_direita(char **peca)
{
    int i,j;
    char **nova_peca;
    nova_peca = malloc(4*sizeof(char*));
    for(i=0;i<4;i++)
    {
        nova_peca[i] = malloc(4*sizeof(char));
    }
    limpar_tela(peca);
    for(i = 0; i<4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(peca[0][3] == BLOCO || peca[1][3] == BLOCO || peca[2][3] == BLOCO || peca[3][3] == BLOCO)
            {
                nova_peca[i][j] = peca[i][j];
            }
            else if (peca[i][j] == BLOCO)
            {
                nova_peca[i][j+1] = BLOCO;
            }
        }
    }
    for(i = 0; i<4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            peca[i][j] = nova_peca[i][j];
        }
    }
    limpa_peca(nova_peca);
    peca_na_tela(peca);
}
