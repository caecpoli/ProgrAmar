#include <stdio.h>
#include <stdlib.h>
#include "apagarLinha.h"
#include "gotoxy.h"
#define BLOCO 6

extern int pontos,contador;

void apagar_linha(unsigned char **matrizPrincipal,unsigned char pecinha)
{
    int a, b, i, j, contaQuadrado = 0;

    for(i = 19; i >= 0; i--)
    {
        for(j = 1; j < 16; j++)
        {
            if(matrizPrincipal[i][j] == BLOCO)
            {
                contaQuadrado++;
            }
        }
        if(contaQuadrado == 15)
        {
            contador+=100;
            pontos+=100;
            for(b = 1; b < 16; b++)
            {
                matrizPrincipal[i][b] = 0;
                gotoxy(b,i);
                putchar(0);
            }

            for(a = i; a >= 1; a--)
            {
                for(b = 1; b < 16; b++)
                {
                    if(matrizPrincipal[a-1][b] == BLOCO)
                    {
                        gotoxy(b,a);
                        putchar(BLOCO);
                        gotoxy(b,a-1);
                        putchar(0);
                    }
                    matrizPrincipal[a][b] = matrizPrincipal[a-1][b];
                }
            }
            i++;
        }
        contaQuadrado = 0;
    }
}
