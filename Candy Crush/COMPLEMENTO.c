#include "funcoes.h"
#include "F_MENU.h"
#include "COMPLEMENTO.h"
#include "F_GAME.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

unsigned char Fim_Letras1[13][30] =
{
201,205,205,187,' ',' ',201,205,205,187,' ',201,205,205,205,205,205,205,205,187,' ',201,205,187,' ',' ',201,205,187,'\0',
186,' ',' ',186,' ',' ',186,' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',186,' ',' ',186,' ',186,'\0',
186,' ',' ',186,' ',' ',186,' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',186,' ',' ',186,' ',186,'\0',
186,' ',' ',186,' ',' ',186,' ',' ',186,' ',186,' ',' ',201,205,187,' ',' ',186,' ',186,' ',186,' ',' ',186,' ',186,'\0',
186,' ',' ',200,205,205,188,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',186,' ',' ',186,' ',186,'\0',
186,' ',' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',186,' ',' ',186,' ',186,'\0',
186,' ',' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',186,' ',' ',186,' ',186,'\0',
200,205,205,187,' ',' ',201,205,205,188,' ',186,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',186,' ',' ',186,' ',186,'\0',
' ',' ',' ',186,' ',' ',186,' ',' ',' ',' ',186,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',186,' ',' ',186,' ',186,'\0',
' ',' ',' ',186,' ',' ',186,' ',' ',' ',' ',186,' ',' ',200,205,188,' ',' ',186,' ',186,' ',200,205,205,188,' ',186,'\0',
' ',' ',' ',186,' ',' ',186,' ',' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,'\0',
' ',' ',201,188,' ',' ',200,187,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',200,187,' ',' ',' ',' ',201,188,'\0',
' ',' ',200,205,205,205,205,188,' ',' ',' ',200,205,205,205,205,205,205,205,188,' ',' ',200,205,205,205,205,188,' ','\0',
};

unsigned char Fim_Letras2[13][43] =
{
201,205,205,205,187,' ',' ',' ',' ',' ',201,205,205,205,205,205,205,205,187,' ',201,205,205,205,205,205,205,187,' ',201,205,205,205,205,205,205,187,' ',201,205,187,' ','\0',
186,' ',' ',' ',186,' ',' ',' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',186,' ','\0',
186,' ',' ',' ',186,' ',' ',' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',186,' ','\0',
186,' ',' ',' ',186,' ',' ',' ',' ',' ',186,' ',' ',201,205,187,' ',' ',186,' ',186,' ',201,205,205,205,205,188,' ',186,' ',' ',201,205,205,205,188,' ',186,' ',186,' ','\0',
186,' ',' ',' ',186,' ',' ',' ',' ',' ',186,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',' ',186,' ',' ',' ',' ',' ',186,' ',186,' ','\0',
186,' ',' ',' ',186,' ',' ',' ',' ',' ',186,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',200,205,205,205,205,187,' ',186,' ',' ',200,205,205,205,187,' ',186,' ',186,' ','\0',
186,' ',' ',' ',186,' ',' ',' ',' ',' ',186,' ',' ',186,' ',186,' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',186,' ','\0',
186,' ',' ',' ',186,' ',' ',' ',' ',' ',186,' ',' ',186,' ',186,' ',' ',186,' ',200,205,205,205,205,187,' ',186,' ',186,' ',' ',201,205,205,205,188,' ',186,' ',186,' ','\0',
186,' ',' ',' ',186,' ',' ',' ',' ',' ',186,' ',' ',186,' ',186,' ',' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',186,' ',' ',186,' ',' ',' ',' ',' ',186,' ',186,' ','\0',
186,' ',' ',' ',200,205,205,205,187,' ',186,' ',' ',200,205,188,' ',' ',186,' ',201,205,205,205,205,188,' ',186,' ',186,' ',' ',200,205,205,205,187,' ',200,205,188,' ','\0',
186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',' ',' ',' ',' ','\0',
186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',186,' ',' ',' ',' ',' ',' ',186,' ',201,205,187,' ','\0',
200,205,205,205,205,205,205,205,188,' ',200,205,205,205,205,205,205,205,188,' ',200,205,205,205,205,205,205,188,' ',200,205,205,205,205,205,205,188,' ',200,205,188,' ','\0',
};

void clear()
{
    system("cls || clear");
}

void instrucoes()
{
    char texto[400];
    FILE *ler;
    ler = fopen("instrucoes.txt","r");

    if(ler == NULL)
    {
        printf("ERRO!!! FALTA DE ARQUIVO\n\n");
        getch();
        exit(1);
    }
    else
    {
        while(fgets(texto,400,ler) != NULL)
        {
            printf("%s",texto);
        }
        fclose(ler);
    }
    getch();
    clear();
    OPCOES();
}

void OPCOES()
{
    char tecla[4]= {Seta,Seta,Seta,Seta};
    int Y=0;

    while(tecla[Y]!= Enter)
    {
        clear();
        outdoor_M();
        ajustar_linha();
        ajustar_coluna_OP();
        bordas_OP_Top();
        ajustar_coluna_OP();
        printf("%c         %c CUSTOMIZAR               %c\n",186,((Y==0)? tecla[Y]: 32),186);
        ajustar_coluna_OP();
        printf("%c         %c INSTRUCOES               %c\n",186,((Y==1)? tecla[Y]: 32),186);
        ajustar_coluna_OP();
        printf("%c         %c CREDITOS                 %c\n",186,((Y==2)? tecla[Y]: 32),186);
        ajustar_coluna_OP();
        printf("%c         %c SAIR                     %c\n",186,((Y==3)? tecla[Y]: 32),186);
        ajustar_coluna_OP();
        bordas_OP_Bot();

        tecla[Y]=getch();

        switch(tecla[Y])
        {
        case 'w':
        case 'W':
            tecla[Y]=Seta;
            Y--;
            break;
        case 's':
        case 'S':
            tecla[Y]=Seta;
            Y++;
            break;
        default:
        {
            if(tecla[Y]!= Enter)
            {
                if(tecla[Y]==ESC) return 0;
                else
                {
                    tecla[Y]=Seta;
                    Y--;
                }
            }
        }
        }
        if (Y<0) Y=3;
        else if (Y>3) Y=0;
    }

    clear();

    switch(Y)
    {
    case 0:
        colorir(customizar());
        break;
    case 1:
        instrucoes();
        break;
    case 2:
        creditos();
        break;
    }
}

void creditos()
{
    char texto[400];
    FILE *ler;
    ler = fopen("Creditos.txt","r");

    if(ler == NULL)
    {
        printf("ERRO!!! FALTA DE ARQUIVO\n\n");
        getch();
        exit(1);
    }
    else
    {
        while(fgets(texto,400,ler) != NULL)
        {
            printf("%s",texto);
        }
        fclose(ler);
    }
    getch();
    clear();
    OPCOES();
}

void SAIR()
{
    clear();
    char key[2]= { Seta,Seta };
    int i=0;

    while(key[i]!= Enter)
    {
        clear();
        outdoor_M();
        ajustar_linha();
        ajustar_coluna_OP();
        bordas_OP_Top();
        ajustar_coluna_OP();
        printf("%c     VOCE DESEJA REALMENTE SAIR?    %c\n",186,186);
        ajustar_coluna_OP();
        printf("%c                                    %c\n",186,186);
        ajustar_coluna_OP();
        printf("%c              %c YES                 %c\n",186,((i==0)? key[i]: 32),186);
        ajustar_coluna_OP();
        printf("%c              %c NO                  %c\n",186,((i==1)? key[i]: 32),186);
        ajustar_coluna_OP();
        bordas_OP_Bot();

        key[i]=getch();

        switch(key[i])
        {

        case 'w':
        case 'W':
            key[i]=Seta;
            i--;
            break;
        case 's':
        case 'S':
            key[i]=Seta;
            i++;
            break;
        default:
        {
            if(key[i]!= Enter)
            {
                if(key[i]==ESC) return 0;
                else
                {
                    key[i]=Seta;
                    i--;
                }
            }
        }
        }
        if (i<0) i=1;
        else if (i>1) i=0;
    }
    clear();
    if(i==0) exit(1);
}

/*int RANK1(char nk[20],unsigned int pontos)
{
jogador jtemp,game1,jtemp2,jovem[100];
int jogadores,i,local,local2;

FILE *ptr_rank;
ptr_rank=fopen("RANK.txt","r");

if(ptr_rank==NULL)//AINDA NÃO EXISTE
    {
    jogadores=0;//NINGUEM JOGOU AINDA
    fclose(ptr_rank);
    }
else
    {
    jogadores=fread(jovem,sizeof(jogador),10,ptr_rank);//ME DEVOLVE A QUANTIDADE DE JOGADORES
    fclose(ptr_rank);
    }

//PASSANDO OS DADOS DO JOGADOR "I"
    strcpy(jovem[jogadores-1].nick,nk);
    jovem[jogadores-1].pontos=pontos;

if(jogadores==0)
    {
    printf("NADANADANADA"); getch();
    }
else
    {
for(i=0;i<(jogadores-1);i++)
    {
    if(jovem[i].pontos<jovem[i+1].pontos)
            {
            ptr_rank=fopen("RANK.txt","r");
            local2=fread(&jtemp,sizeof(jogador),i+1,ptr_rank);
            fseek(ptr_rank,sizeof(jogador)*(i+1),SEEK_SET);
            local=fread(&jtemp2,sizeof(jogador),i,ptr_rank);
            fclose(ptr_rank);

            ptr_rank=fopen("RANK.txt","w");
            fwrite(&jtemp,sizeof(jogador),local,ptr_rank);
            fwrite(&jtemp2,sizeof(jogador),local2,ptr_rank);
            fclose(ptr_rank);
            }
        }
    }

if(jogadores==0)
    {
    ptr_rank=fopen("RANK.txt","r");
    fwrite(&game1,sizeof(jogador),sizeof(jogador),ptr_rank);
    printf("VAZIO");
    getch();
    }
else{
    ptr_rank=fopen("RANK.txt","r");
    for(i=0;i<10;i++)
        {
        fprintf(ptr_rank,"nome: %s ---------- pontos: %d\n",jovem[i].nick,jovem[i].pontos);
        }
fclose(ptr_rank);}
}

void RANK()
{
unsigned char text[400];
FILE *rankeamento;
rankeamento = fopen("RANK.txt","r");

if(rankeamento == NULL)
    {
    printf("ERRO!!! FALTA DE ARQUIVO\n\n");
    getch();
    exit(1);
    }
else
    {
    while(fgets(text,400,rankeamento) != NULL)
        {
        printf("%s",text);
        }
    fclose(rankeamento);
    }
    printf("\nAperte qualquer tecla para voltar ao menu...");
    getch();
}*/

int customizar()
{
    clear();
    char key[5]= { Seta,Seta,Seta,Seta,Seta };
    int X=0;

    while(key[X]!= Enter)
    {
        clear();
        outdoor_M();
        printf("\n\n\n\n\n\n\n\n");
        ajustar_coluna_OP();
        bordas_OP_Top();
        ajustar_coluna_OP();
        printf("%c   ESCOLHA UMA COR PARA SEU GAME:   %c\n",186,186);
        ajustar_coluna_OP();
        printf("%c                                    %c\n",186,186);
        ajustar_coluna_OP();
        printf("%c  %c FUNDO PRETO E LETRA VERDE       %c\n",186,((X==0)? key[X]: 32),186);
        ajustar_coluna_OP();
        printf("%c  %c FUNDO PRETO E LETRA BRANCA      %c\n",186,((X==1)? key[X]: 32),186);
        ajustar_coluna_OP();
        printf("%c  %c FUNDO BRANCO E LETRA VERMELHA   %c\n",186,((X==2)? key[X]: 32),186);
        ajustar_coluna_OP();
        printf("%c  %c FUNDO BRANCO E LETRA AZUIS      %c\n",186,((X==3)? key[X]: 32),186);
        ajustar_coluna_OP();
        printf("%c  %c FUNDO ROXO E LETRA PRETA        %c\n",186,((X==4)? key[X]: 32),186);
        ajustar_coluna_OP();
        printf("%c                                    %c\n",186,186);
        ajustar_coluna_OP();
        bordas_OP_Bot();

        key[X]=getch();

        switch(key[X])
        {

        case 'w':
        case 'W':
            key[X]=Seta;
            X--;
            break;
        case 's':
        case 'S':
            key[X]=Seta;
            X++;
            break;
        default:
        {
            if(key[X]!= Enter)
            {
                if(key[X]==ESC) return 0;
                else
                {
                    key[X]=Seta;
                    X--;
                }
            }
        }
        }
        if(X<0) X=4;
        else if(X>4) X=0;
    }
    return X;
}

void Fim()
{
    int i;
    clear();
    ajustar_linha();
    for(i=0;i<13;i++)
    {
        printf("                               ");
        puts(Fim_Letras1[i]);
    }

    for(i=0;i<13;i++)
    {
        printf("                          ");
        puts(Fim_Letras2[i]);
    }
    ajustar_coluna_OP();
    printf("\tNAO CHORA!\n");
    ajustar_coluna_OP();
    printf("\tTENTA NOVAMENTE!\n\n\n\n\n\n\n\n\n\n");
}

void congratulations()
{
    printf("PARABENS");
}
