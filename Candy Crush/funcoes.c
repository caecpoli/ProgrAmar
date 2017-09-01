#include "COMPLEMENTO.h"
#include "funcoes.h"
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ajustar_linha()
{
printf("\n\n\n\n\n\n\n\n\n\n\n");
}

void ajustar_coluna_M()
{
printf("                                            ");
}

void ajustar_coluna_OP()
{
printf("                                ");
}

void bordas_OP_Top()
{
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
        201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
        205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
}

void bordas_OP_Bot()
{
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
       200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
       205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void colorir(char X)
{
switch(X)
    {
        case 0: system("color 0A"); break;
        case 1: system("color 0F"); break;
        case 2: system("color F4"); break;
        case 3: system("color F9"); break;
        default: system("color D0"); break;
    }clear();
}

void MudaCor(int M)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),M);
}
