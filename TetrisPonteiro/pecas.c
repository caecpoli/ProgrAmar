#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pecas.h"
#include "gotoxy.h"
#define BLOCO 6

extern int cor;

void pecas_random(char **peca)
{
    int numero;

    srand(time(NULL));  //Função que randomiza um valor de 0 a 6, cada valor corresponde a uma peça diferente.
    numero = rand()%7;

    switch(numero)
    {
    case 0 :
        cor = 10;
        textcolor(cor);
        peca[1][1] = BLOCO;
        peca[1][2] = BLOCO;     //a peca criada nessa matriz tem formato de "Z"
        peca[2][0] = BLOCO;
        peca[2][1] = BLOCO;
        break;
    case 1 :
        cor = 11;
        textcolor(cor);
        peca[1][1] = BLOCO;
        peca[1][2] = BLOCO;      //a peca criada nessa matriz tem formato de quadrado
        peca[2][1] = BLOCO;
        peca[2][2] = BLOCO;
        break;
    case 2 :
        cor = 12;
        textcolor(cor);
        peca[1][0] = BLOCO;
        peca[1][1] = BLOCO;     //a peca criada nessa matriz tem formato de barra
        peca[1][2] = BLOCO;
        peca[1][3] = BLOCO;
        break;
    case 3 :
        cor = 13;
        textcolor(cor);
        peca[1][0] = BLOCO;
        peca[2][0] = BLOCO;     //a peca criada nessa matriz tem formato de "L"
        peca[2][1] = BLOCO;
        peca[2][2] = BLOCO;
        break;
    case 4 :
        cor = 14;
        textcolor(cor);
        peca[1][1] = BLOCO;
        peca[2][0] = BLOCO;     //a peca criada nessa matriz tem formato de "T"
        peca[2][1] = BLOCO;
        peca[2][2] = BLOCO;
        break;
    case 5 :
        cor = 7;
        textcolor(cor);
        peca[1][0] = BLOCO;
        peca[1][1] = BLOCO;     //a peca criada nessa matriz tem formato de "Z"
        peca[2][1] = BLOCO;
        peca[2][2] = BLOCO;
        break;
    case 6 :
        cor = 8;
        textcolor(cor);
        peca[1][2] = BLOCO;
        peca[2][0] = BLOCO;     //a peca criada nessa matriz tem formato de "L"
        peca[2][1] = BLOCO;
        peca[2][2] = BLOCO;
        break;
    }
}
