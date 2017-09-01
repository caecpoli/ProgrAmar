#include <stdio.h>
#include <stdlib.h>
#include "movimentoPeca.h"
#include "tabuleiro.h"
#include "localPeca.h"

extern int x,y;

void descer_peca(unsigned char **matrizPrincipal,char **peca,unsigned char pecinha)
{
    limpar_tela(peca);
    y++;
    peca_na_tela(peca);
}

void mover_esquerda(unsigned char **matrizPrincipal,char **peca,unsigned char pecinha)
{
    limpar_tela(peca);
    x--;
    peca_na_tela(peca);
}

void mover_direita(unsigned char **matrizPrincipal,char **peca,unsigned char pecinha)
{
   limpar_tela(peca);
   x++;
   peca_na_tela(peca);
}

