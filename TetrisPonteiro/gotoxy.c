#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "gotoxy.h"

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x,y
    });
}
void textcolor(int cor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),cor);
}
