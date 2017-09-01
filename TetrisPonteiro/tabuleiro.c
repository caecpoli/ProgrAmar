#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "gotoxy.h"

void tabuleiro(unsigned char **matrizPrincipal,unsigned char pecinha)
{
    int i,j;
    for(i = 0; i < 21; i++)
    {
        for(j = 0; j < 17; j++)
        {
            if(i == 20 || j == 0 || j == 16)
            {
                matrizPrincipal[i][j] = pecinha;
            }
            textcolor(3);
            printf("%c",matrizPrincipal[i][j]);
        }
        putchar('\n');
    }
}
