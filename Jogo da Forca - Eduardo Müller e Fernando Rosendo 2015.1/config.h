#ifndef CONFIG_H
    #define CONFIG_H

#include "temasconfig.h"
#include <stdio.h>
#include <stdlib.h>


config(comando)
{
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

    /* menu*/
    printf("\n\n\n");
    puts("\t\t\t1 - Plano de Fundo Preto >\n");
    puts("\t\t\t2 - Plano de Fundo Azul > \n");
    puts("\t\t\t3 - Plano de Fundo Verde >\n");
    puts("\t\t\t4 - Plano de Fundo Vermelho >\n");
    puts("\t\t\t5 - Plano de Fundo Branco > \n");
    puts("\t\t\t6 - Retornar para o menu.\n");



    /*escolha*/
    printf("\n\n\n\n\n\n\n");
    printf("Digite o comando: ");
    comando = getche();
    switch(comando){
        case '1': pp(comando); break;
        case '2': pa(comando); break;
        case '3': pvd(comando); break;
        case '4': pvm(comando); break;
        case '5': pb(comando); break;
        case '6': main(); break;
        default: printf("\nComando Invalido.\n Digite qualquer tecla para retornar ao menu."); getch(); main();
    }

}

#endif
