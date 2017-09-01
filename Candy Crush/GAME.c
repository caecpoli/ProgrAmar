#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

unsigned char MAPA1[11][11] = {
		' ',' ','1','2','3','4','5','6','7',' ','\0',
   		' ',201,205,205,205,205,205,205,205,187,'\0',
   		'1',186,' ',' ',' ',' ',' ',' ',' ',186,'\0',
   		'2',186,' ',' ',' ',' ',' ',' ',' ',186,'\0',
   		'3',186,' ',' ',' ',' ',' ',' ',' ',186,'\0',
   		'4',186,' ',' ',' ',' ',' ',' ',' ',186,'\0',
   		'5',186,' ',' ',' ',' ',' ',' ',' ',186,'\0',
   		'6',186,' ',' ',' ',' ',' ',' ',' ',186,'\0',
   		'7',186,' ',' ',' ',' ',' ',' ',' ',186,'\0',
   		' ',200,205,205,205,205,205,205,205,188,'\0',
   };
int aux_1, score=0;
int i, j, valor,jogadas=0;
int x1, x2, y1, y2, aux_2;
char m, n;

    srand((unsigned)time(NULL)); // Parâmetro de aleatoriedade.

 	for (i=2; i<=8; i++){ // 2 à 8 para alinhar a numeração com a matriz.
  		for (j=2; j<=8; j++){ // Construindo uma matriz 7x7 aleatória.
  			valor = 1 + (rand() % 100);
  			if ((1<=valor) && (valor<=20)) // Subdivindo o intervalo de 1-49 em intervalos menores (5 partes).
  				MAPA1 [i][j] = 208;  // O símbolo será "A" se o valor aleatório gerado ficar entre 1-10.
			else if ((20<valor) && (valor<=40))
				MAPA1 [i][j] = 244;
			else if ((40<valor) && (valor<=60))
				MAPA1 [i][j] = 245;
			else if ((60<valor) && (valor<=80))
				MAPA1 [i][j] = 190;
			else
				MAPA1 [i][j] = 64;
		}
	} // Fim da construção da matriz aleatória.

// Até aqui, a matriz aleatória pode gerar sequências prontas, o bloco da rotina a seguir corrige este bug.
// Rotina para corrigir e substituir sequências prontas na matriz aleatória.


while(jogadas<6){  // Esse DO/WHILE é provisório e faz o bloco se repetir durante 5x.

do { // Rotina para corrigir os bugs gerados na matriz aleatória.
	aux_1 = 0;
    for (i=2; i<=8; i++){ // Verifica se não existem 3 peças iguais na HORIZONTAL.
    	for (j=2; j<=6; j++){
    		if (((MAPA1[i][j])==(MAPA1[i][j+1])) && ((MAPA1[i][j])==(MAPA1[i][j+2])))
                { // Se entra aqui, significa que existem 3 iguais.
    			// Corrigindo a disposição das peças na HORIZONTAL:
				if (MAPA1[i][j] ==208) { MAPA1[i][j] =244; aux_1 += 1; }  // Substituição das peças na HORIZONTAL.
    			else if (MAPA1[i][j] ==244) { MAPA1[i][j] =245; aux_1 += 1; }
    			else if (MAPA1[i][j] ==245) { MAPA1[i][j] =190; aux_1 += 1; }
    			else if (MAPA1[i][j] ==190) { MAPA1[i][j] =64; aux_1 += 1; }
    			else if (MAPA1[i][j] ==64) { MAPA1[i][j] =208; aux_1 += 1; }
    			else {MAPA1[i][j]==208; aux_1+=1;}
			    }
		}
	} // Fim da verificação horizontal.

	// O parâmetro "aux_1" está sendo usado para checar a não ocorrência anteriormente descritos na reanálise da matriz já construída,
	// para certificar se a mesma é válida para se iniciar o jogo.
	for (i=2; i<=6; i++)
	{ // Verifica se não existem 3 peças iguais na VERTICAL.
    	for (j=2; j<=8; j++)
            {
    		if (((MAPA1[i][j])==(MAPA1[i+1][j])) && ((MAPA1[i][j])==(MAPA1[i+2][j])))
                { // Se entra aqui, significa que existem 3 iguais.
                    // Corrigindo a disposição das peças na VERTICAL:
                    if (MAPA1[i][j] ==208) { MAPA1[i][j] =244; aux_1 += 1; } // Substituição das peças na VERTICAL.
                    else if (MAPA1[i][j] ==244) { MAPA1[i][j] =245; aux_1 += 1; }
                    else if (MAPA1[i][j] ==245) { MAPA1[i][j] =190; aux_1 += 1; }
                    else if (MAPA1[i][j] ==190) { MAPA1[i][j] =64; aux_1 += 1; }
                    else if (MAPA1[i][j] ==64) { MAPA1[i][j] =208; aux_1 += 1; }
                    else {MAPA1[i][j] == 64; aux_1 +=1;}
                }
            }
	} // Fim da verificação vertical.
} while (aux_1>0);
// Fim do bloco para checar a validade da matriz aleatória anteriormente formada. O programa só emite a matriz se a matriz estiver isenta
// dos bugs anteriormente descritos.

/* JOGADAS DO USUÁRIO */

	//system ("cls");
	aux_1 = 0;

	// Manipulação de caracteres para imprimir no tabuleiro.
	printf ("\n\n\n");
	for (m=0; m<10; m++){ // Impressão da matriz na tela:
    	printf("                          ");
    	for (n=0; n<10; n++){
        	printf("%c ", MAPA1[m][n]);
    	}
    	putchar('\n');
    }
    printf ("\n\n");
    printf ("\t- SCORE: %d\t\t\t JOGADA %d\n\n", score, jogadas);
    printf ("\t- Escolha uma peca: \n");
    printf ("\tDigite o numero correspondente a linha: ");
    scanf ("%d", &x1);
    printf ("\tDigite o numero correspondente a coluna: ");
    scanf ("%d", &y1);
    printf ("\n\t- Escolha para onde sera movida: \n");
    printf ("\tDigite o numero correspondente a linha: ");
    scanf ("%d", &x2);
    printf ("\tDigite o numero correspondente a coluna: ");
    scanf ("%d", &y2);

    jogadas++;//jogadas depois do print pq se não DA BUG

    // Bloco de troca de posição das peças:
    aux_2 = MAPA1[x1+1][y1+1];
    MAPA1[x1+1][y1+1] = MAPA1[x2+1][y2+1];
    MAPA1[x2+1][y2+1] = aux_2;
	// Fim do bloco de troca de posição das peças.

	 for (i=2; i<=8; i++){ // Checagem da sequencia na horizontal;
    	for (j=2; j<=6; j++){
    		if (((MAPA1[i][j])==(MAPA1[i][j+1])) && ((MAPA1[i][j])==(MAPA1[i][j+2])))
                {
				if (MAPA1[i][j] ==208)
                    {
					MAPA1[i][j]   = 244;
					MAPA1[i][j+1] = 245;
					MAPA1[i][j+2] = 190;
				    aux_1 += 1;
				    }
    			else if (MAPA1[i][j] ==244)
                    {
					MAPA1[i][j]   = 208;
					MAPA1[i][j+1] = 245;
					MAPA1[i][j+2] = 190;
					aux_1 += 1;
				    }
    			else if (MAPA1[i][j] ==245)
                    {
					MAPA1[i][j]   = 208;
					MAPA1[i][j+1] = 244;
					MAPA1[i][j+2] = 190;
					aux_1 += 1;
				    }
    			else if (MAPA1[i][j] ==190)
                    {
					MAPA1[i][j]   = 208;
					MAPA1[i][j+1] = 244;
					MAPA1[i][j+2] = 245;
					aux_1 += 1;
				    }
    			else
                    {
					MAPA1[i][j]   = 245;
					MAPA1[i][j+1] = 244;
					MAPA1[i][j+2] = 208;
					//MAPA1[i][j+3] = 190;
					aux_1 += 1;
				    }
			}
		}
	} // Fim da checagem da sequencia na horizontal;

	for (i=2; i<=6; i++)
        { // Checagem da sequencia na vertical.
    	for (j=2; j<=8; j++)
            {
                if (((MAPA1[i][j])==(MAPA1[i+1][j])) || ((MAPA1[i][j])==(MAPA1[i+2][j])))
                   {
                    if (MAPA1[i][j] ==208)
                        {
                        MAPA1[i][j]   = 190;
                        MAPA1[i+1][j] = 245;
                        MAPA1[i+2][j] = 244;
                      //  MAPA1[i+3][j] = 64;
                        aux_1 += 1;
                        }
                    else if (MAPA1[i][j] ==244)
                        {
                        MAPA1[i][j]   = 208;
                        MAPA1[i+1][j] = 245;
                        MAPA1[i+2][j] = 190;
                        //MAPA1[i+3][j] = 64;
                        aux_1 += 1;
                        }
                    else if (MAPA1[i][j] ==245)
                       {
                        MAPA1[i][j]   = 208;
                        MAPA1[i+1][j] = 244;
                        MAPA1[i+2][j] = 190;
                        //MAPA1[i+3][j] = 64;
                        aux_1 += 1;
                       }
                    else if (MAPA1[i][j] ==190)
                       {
                        MAPA1[i][j]   = 245;
                        MAPA1[i+1][j] = 244;
                        MAPA1[i+2][j] = 208;
                        //MAPA1[i+3][j] = 64;
                        aux_1 += 1;
                       }
                    else
                       {
                        MAPA1[i][j]   = 190;
                        MAPA1[i+1][j] = 208;
                        MAPA1[i+2][j] = 245;
                        //MAPA1[i+3][j] = 64;
                        aux_1 += 1;
                       }
                }

            }
	} // Fim da checagem da sequência na vertical.
	score += aux_1;
} // FIM DO BLOCO PARA JOGADAS DO USUÁRIO.
	system ("cls");
	printf ("\n\n\t\t**** JOGADAS ESGOTADAS. FIM DE JOGO. ****");
	printf ("\t\tPontuacao obtida: %d", score);
    system ("pause");
}
