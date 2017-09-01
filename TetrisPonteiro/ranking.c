#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <strings.h>
#include <windows.h>
#include "ranking.h"
#include "menu.h"
#include "jogo.h"


 struct Score{
    char name[11];
    int score;
};

int countScores(){
    int c = 0, lines=1;
    FILE *arquivo;
    arquivo = fopen("highscore.Scores","r");

    if(arquivo == NULL){
        printf("OCORREU UM ERRO AO ACESSAR ARQUIVO.");
        Sleep(5000);
        exit(0);
    }

    do{
        c = getc(arquivo);
            lines++;
    }while(c != EOF);

    fclose(arquivo);
    return lines;
}

void addScore(int pontos){
    char jogador[11];
    printf("DIGITE SEU NOME, POR FAVOR: ");
    fgets(jogador, 11, stdin);

    saveHighscore(jogador, pontos);
}

void saveHighscore(char name[11], int pontos){
    FILE *arquivo;
    arquivo = fopen("highscore.Scores", "a");

    if(arquivo == NULL){
        printf("OCORREU UM ERRO AO ACESSAR ARQUIVO.");
        Sleep(5000);
        exit(0);
    }

    fprintf(arquivo, "\n%s - %i", name, pontos);

    fclose(arquivo);

    restart();
}

void readScores(){

    struct Score player[20];
    int i;
    int pontos;
    char nome[11];


    for(i=0; i<20; i++){
        strcpy(player[i].name, " ");
        player[i].score = 0;
    }
    FILE *arquivo;
    arquivo = fopen("highscore.Scores", "r");

    if(arquivo == NULL){
        fclose(arquivo);
        arquivo = fopen("highscore.Scores", "w");

        if(arquivo == NULL){
            printf("OCORREU UM ERRO AO ACESSAR ARQUIVO.");
            Sleep(5000);
            exit(0);
        }
        fclose(arquivo);
        arquivo = fopen("highscore.Scores", "r");
    }
    i=0;

    while((fscanf(arquivo, "%s - %i", &nome, &pontos)!=EOF)){
        if(i<15){
            strcpy(player[i].name, nome);
            player[i].score = pontos;
            i++;
        }
    }

    fclose(arquivo);
    displayRanking(player);
}

void displayRanking(struct Score player[20])
{
    int i, j, atualScore;
    char atualNome[11];
    char setinha;

    for(i=0; i<20; i++){
        for(j= i+1; j<20; j++){
            if(player[i].score <= player[j].score){
                strcpy(atualNome, player[i].name);
                atualScore = player[i].score;
                strcpy(player[i].name, player[j].name);
                player[i].score = player[j].score;
                strcpy(player[j].name, atualNome);
                player[j].score = atualScore;
            }
        }
    }

    if(countScores()>10){
        FILE *arquivo;
        arquivo = fopen("highscore.Scores", "w");

    if(arquivo == NULL){
        printf("OCORREU UM ERRO AO ACESSAR ARQUIVO.");
        Sleep(5000);
        exit(0);
    }

        for(i=0; i<9; i++){
            fprintf(arquivo, "%s - %i\n", player[i].name, player[i].score);
        }
        fprintf(arquivo, "%s - %i", player[i].name, player[i].score);
        fclose(arquivo);
    }

    do{
            system("cls");
        for(i=0; i<10; i++){
            if(strlen(player[i].name)<=1){
                printf("\n\t\tº");
            }else{
                printf("\n\t\tº%i-   %s - %i",i+1, player[i].name, player[i].score);
            }
        }

        printf("\n\t\t>>Retornar ao menu\n");
        setinha=getch();
    }while(setinha!= 13);
    system("cls");
    MENU();
}
