#ifndef DESENHO_H
    #define DESENHO_H

#include <stdio.h>
#include <stdlib.h>

char A[20][20];
int i,j;
void inicio(void)
{


    for(i=0; i<20; i++)
        for(j=0; j<20; j++)
        {
            A[i][j]=' ';
        }
    for(i=0; i<20-3; i++)
        for(j=0; j<20-3; j++)
        {
            if(i==0)
                A[i][j]=196;
            else
                A[i][0]=179;
        }
    for(j=13; j<20; j++)
        A[1][j]=196;
    A[0][0]=218;
    A[0][16]=191;
    A[1][16]=193;
    A[17][0]=193;

    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void cabeca(void)
{
    for(i=2; i<7; i++)
        for(j=13; j<20; j++)
        {
            if(i==2 || i==6)
                A[i][j]=196;
            if(j==13 || j==20-1)
                A[i][j]=179;
        }

    A[2][13]=218;
    A[2][19]=191;
    A[3][15]='X';
    A[3][17]='X';
    A[5][16]='O';
    A[6][13]=192;
    A[6][19]=217;

    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void corpo(void)
{

    for(i=7; i<12; i++)
        A[i][16]=179;
    A[6][16]=194;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void bracod(void)
{
    A[8][17]=92;
    A[9][18]=92;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void bracoe(void)
{
    A[8][15]=47;
    A[9][14]=47;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void pernad(void)
{
    A[12][17]=92;
    A[13][18]=92;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void pernae(void)
{
    A[12][15]=47;
    A[13][14]=47;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}



#endif
