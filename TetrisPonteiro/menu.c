#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "instrucoes.h"
#include "jogo.h"
#include "ranking.h"
#include "menu.h"
#define Enter 13


void MENU()
{
    hideCursor();

    int contador = 0;
    char setinha;

    do
    {
        printf("\t\t  _______ ______ _______ _____   _____  ____ \n");
        printf("\t\t |__   __|  ____|__   __|  __ \\ |_   _|/____| \n");
        printf("\t\t    | |  | |__     | |  | |__| |  | |  |___   \n");
        printf("\t\t    | |  |  __|    | |  |  _  /   | |  \\___\\ \n");
        printf("\t\t    | |  | |____   | |  | | \\ \\  _| |_ ____ | \n");
        printf("\t\t    |_|  |______|  |_|  |_|  \\_\\|_____|____/ \n\n\n\n\n\n\n\n\n\n");

        contador == 0? printf("\n\n\n\n\t\t\t\t>>Jogar \n\t\t\t\t  Instrucoes \n\t\t\t\t  Ranking \n\t\t\t\t  Sair"):0;
        contador == 1? printf("\n\n\n\n\t\t\t\t  Jogar \n\t\t\t\t>>Instrucoes \n\t\t\t\t  Ranking \n\t\t\t\t  Sair"):0;
        contador == 2? printf("\n\n\n\n\t\t\t\t  Jogar \n\t\t\t\t  Instrucoes \n\t\t\t\t>>Ranking \n\t\t\t\t  Sair"):0;
        contador == 3? printf("\n\n\n\n\t\t\t\t  Jogar \n\t\t\t\t  Instrucoes \n\t\t\t\t  Ranking \n\t\t\t\t>>Sair"):0;

        setinha = getch();
        switch(setinha)
        {
        case 72:
            contador--;
            break;
        case 80:
            contador++;
            break;
        case Enter:
            if(contador==0)
            {
                system("cls");
                jogar();
            }
            else if(contador == 1)
            {
                system("cls");
                Instrucoes();
            }
            else if(contador == 2)
            {
                system("cls");
                readScores();
            }

            else if(contador == 3)
            {
                exit(0);
            }
            break;
        }
        if(contador<0)
            contador=3;
        else if(contador>3)
            contador=0;

        system("cls");


    }
    while(setinha != Enter);
}

void hideCursor()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO i;
    i.dwSize = 100;
    i.bVisible = FALSE;
    SetConsoleCursorInfo(console, &i);
}


