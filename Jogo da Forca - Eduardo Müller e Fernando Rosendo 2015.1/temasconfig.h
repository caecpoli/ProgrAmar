#ifndef TEMASCONFIG_H
    #define TEMASCONFIG_H

#include <stdio.h>
#include <stdlib.h>


pp(comando){

    system("cls");
     /*Titulo*/
    printf("\n");
    linhah("Jogo da Forca",'-');
    puts("\t\t\tJogo da Forca");
    linhah("Jogo da Forca",'-');

    /*subtitulo*/
    printf("\n\n");
    linhah("Configuracoes",'-');
    puts("Configuracoes");
    linhah("Configuracoes",'-');

     /*menu*/
    printf("\n\n\n");
    puts("\t\t\t1 - Letras Azuis\n");
    puts("\t\t\t2 - Letras Verdes \n");
    puts("\t\t\t3 - Letras Vermelhas \n");
    puts("\t\t\t4 - Letras Brancas \n");



    /*escolha*/
    printf("\n\n\n\n\n\n\n");
    printf("Digite o comando: ");
    comando = getche();
    switch(comando){
        case '1': system("COLOR 01"); main(); break;
        case '2': system("COLOR 02"); main(); break;
        case '3': system("COLOR 04"); main(); break;
        case '4': system("COLOR 07"); main(); break;
        default: printf("\nComando Invalido.\n Digite qualquer tecla para retornar ao menu."); getch(); main();
    }
}

pa(comando){

    system("cls");
     /*Titulo*/
    printf("\n");
    linhah("Jogo da Forca",'-');
    puts("\t\t\tJogo da Forca");
    linhah("Jogo da Forca",'-');

    /*subtitulo*/
    printf("\n\n");
    linhah("Configuracoes",'-');
    puts("Configuracoes");
    linhah("Configuracoes",'-');

     /*menu*/
    printf("\n\n\n");
    puts("\t\t\t1 - Letras Pretas\n");
    puts("\t\t\t2 - Letras Verdes \n");
    puts("\t\t\t3 - Letras Vermelhas \n");
    puts("\t\t\t4 - Letras Brancas \n");



    /*escolha*/
    printf("\n\n\n\n\n\n\n");
    printf("Digite o comando: ");
    comando = getche();
    switch(comando){
        case '1': system("COLOR 10"); main(); break;
        case '2': system("COLOR 12"); main(); break;
        case '3': system("COLOR 14"); main(); break;
        case '4': system("COLOR 17"); main(); break;
        default: printf("\nComando Invalido.\n Digite qualquer tecla para retornar ao menu."); getch(); main();
    }
}

pvd(comando){

    system("cls");
     /*Titulo*/
    printf("\n");
    linhah("Jogo da Forca",'-');
    puts("\t\t\tJogo da Forca");
    linhah("Jogo da Forca",'-');

    /*subtitulo*/
    printf("\n\n");
    linhah("Configuracoes",'-');
    puts("Configuracoes");
    linhah("Configuracoes",'-');

     /* menu*/
    printf("\n\n\n");
    puts("\t\t\t1 - Letras Pretas\n");
    puts("\t\t\t2 - Letras Azuis \n");
    puts("\t\t\t3 - Letras Vermelhas \n");
    puts("\t\t\t4 - Letras Brancas \n");



    /*escolha*/
    printf("\n\n\n\n\n\n\n");
    printf("Digite o comando: ");
    comando = getche();
    switch(comando){
        case '1': system("COLOR 30"); main(); break;
        case '2': system("COLOR 31"); main(); break;
        case '3': system("COLOR 34"); main(); break;
        case '4': system("COLOR 37"); main(); break;
        default: printf("\nComando Invalido.\n Digite qualquer tecla para retornar ao menu."); getch(); main();
    }
}

pvm(comando){

    system("cls");
     /*Titulo*/
    printf("\n");
    linhah("Jogo da Forca",'-');
    puts("\t\t\tJogo da Forca");
    linhah("Jogo da Forca",'-');

    /*subtitulo*/
    printf("\n\n");
    linhah("Configuracoes",'-');
    puts("Configuracoes");
    linhah("Configuracoes",'-');

     /* menu*/
    printf("\n\n\n");
    puts("\t\t\t1 - Letras Pretas\n");
    puts("\t\t\t2 - Letras Azuis \n");
    puts("\t\t\t3 - Letras Verdes \n");
    puts("\t\t\t4 - Letras Brancas \n");



    /*escolha*/
    printf("\n\n\n\n\n\n\n");
    printf("Digite o comando: ");
    comando = getche();
    switch(comando){
        case '1': system("COLOR 40"); main(); break;
        case '2': system("COLOR 41"); main(); break;
        case '3': system("COLOR 43"); main(); break;
        case '4': system("COLOR 47"); main(); break;
        default: printf("\nComando Invalido.\n Digite qualquer tecla para retornar ao menu."); getch(); main();
    }
}

pb(comando){

    system("cls");
     /* Titulo*/
    printf("\n");
    linhah("Jogo da Forca",'-');
    puts("\t\t\tJogo da Forca");
    linhah("Jogo da Forca",'-');

    /*subtitulo*/
    printf("\n\n");
    linhah("Configuracoes",'-');
    puts("Configuracoes");
    linhah("Configuracoes",'-');

     /*menu*/
    printf("\n\n\n");
    puts("\t\t\t1 - Letras Pretas\n");
    puts("\t\t\t2 - Letras Azuis \n");
    puts("\t\t\t3 - Letras Verdes \n");
    puts("\t\t\t4 - Letras Vermelhas \n");



    /*escolha*/
    printf("\n\n\n\n\n\n\n");
    printf("Digite o comando: ");
    comando = getche();
    switch(comando){
        case '1': system("COLOR 70"); main(); break;
        case '2': system("COLOR 71"); main(); break;
        case '3': system("COLOR 72"); main(); break;
        case '4': system("COLOR 74"); main(); break;
        default: printf("\nComando Invalido.\n Digite qualquer tecla para retornar ao menu."); getch(); main();
    }
}



#endif
