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

    srand((unsigned)time(NULL)); // Par�metro de aleatoriedade.

 	for (i=2; i<=8; i++){ // 2 � 8 para alinhar a numera��o com a matriz.
  		for (j=2; j<=8; j++){ // Construindo uma matriz 7x7 aleat�ria.
  			valor = 1 + (rand() % 100);
  			if ((1<=valor) && (valor<=20)) // Subdivindo o intervalo de 1-49 em intervalos menores (5 partes).
  				MAPA1 [i][j] = 208;  // O s�mbolo ser� "A" se o valor aleat�rio gerado ficar entre 1-10.
			else if ((20<valor) && (valor<=40))
				MAPA1 [i][j] = 244;
			else if ((40<valor) && (valor<=60))
				MAPA1 [i][j] = 245;
			else if ((60<valor) && (valor<=80))
				MAPA1 [i][j] = 190;
			else
				MAPA1 [i][j] = 64;
		}
	} // Fim da constru��o da matriz aleat�ria.

// At� aqui, a matriz aleat�ria pode gerar sequ�ncias prontas, o bloco da rotina a seguir corrige este bug.
// Rotina para corrigir e substituir sequ�ncias prontas na matriz aleat�ria.


while(jogadas<6){  // Esse DO/WHILE � provis�rio e faz o bloco se repetir durante 5x.

do { // Rotina para corrigir os bugs gerados na matriz aleat�ria.
	aux_1 = 0;
    for (i=2; i<=8; i++){ // Verifica se n�o existem 3 pe�as iguais na HORIZONTAL.
    	for (j=2; j<=6; j++){
    		if (((MAPA1[i][j])==(MAPA1[i][j+1])) && ((MAPA1[i][j])==(MAPA1[i][j+2])))
                { // Se entra aqui, significa que existem 3 iguais.
    			// Corrigindo a disposi��o das pe�as na HORIZONTAL:
				if (MAPA1[i][j] ==208) { MAPA1[i][j] =244; aux_1 += 1; }  // Substitui��o das pe�as na HORIZONTAL.
    			else if (MAPA1[i][j] ==244) { MAPA1[i][j] =245; aux_1 += 1; }
    			else if (MAPA1[i][j] ==245) { MAPA1[i][j] =190; aux_1 += 1; }
    			else if (MAPA1[i][j] ==190) { MAPA1[i][j] =64; aux_1 += 1; }
    			else if (MAPA1[i][j] ==64) { MAPA1[i][j] =208; aux_1 += 1; }
    			else {MAPA1[i][j]==208; aux_1+=1;}
			    }
		}
	} // Fim da verifica��o horizontal.

	// O par�metro "aux_1" est� sendo usado para checar a n�o ocorr�ncia anteriormente descritos na rean�lise da matriz j� constru�da,
	// para certificar se a mesma � v�lida para se iniciar o jogo.
	for (i=2; i<=6; i++)
	{ // Verifica se n�o existem 3 pe�as iguais na VERTICAL.
    	for (j=2; j<=8; j++)
            {
    		if (((MAPA1[i][j])==(MAPA1[i+1][j])) && ((MAPA1[i][j])==(MAPA1[i+2][j])))
                { // Se entra aqui, significa que existem 3 iguais.
                    // Corrigindo a disposi��o das pe�as na VERTICAL:
                    if (MAPA1[i][j] ==208) { MAPA1[i][j] =244; aux_1 += 1; } // Substitui��o das pe�as na VERTICAL.
                    else if (MAPA1[i][j] ==244) { MAPA1[i][j] =245; aux_1 += 1; }
                    else if (MAPA1[i][j] ==245) { MAPA1[i][j] =190; aux_1 += 1; }
                    else if (MAPA1[i][j] ==190) { MAPA1[i][j] =64; aux_1 += 1; }
                    else if (MAPA1[i][j] ==64) { MAPA1[i][j] =208; aux_1 += 1; }
                    else {MAPA1[i][j] == 64; aux_1 +=1;}
                }
            }
	} // Fim da verifica��o vertical.
} while (aux_1>0);
// Fim do bloco para checar a validade da matriz aleat�ria anteriormente formada. O programa s� emite a matriz se a matriz estiver isenta
// dos bugs anteriormente descritos.

/* JOGADAS DO USU�RIO */

	//system ("cls");
	aux_1 = 0;

	// Manipula��o de caracteres para imprimir no tabuleiro.
	printf ("\n\n\n");
	for (m=0; m<10; m++){ // Impress�o da matriz na tela:
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

    jogadas++;//jogadas depois do print pq se n�o DA BUG

    // Bloco de troca de posi��o das pe�as:
    aux_2 = MAPA1[x1+1][y1+1];
    MAPA1[x1+1][y1+1] = MAPA1[x2+1][y2+1];
    MAPA1[x2+1][y2+1] = aux_2;
	// Fim do bloco de troca de posi��o das pe�as.

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
	} // Fim da checagem da sequ�ncia na vertical.
	score += aux_1;
} // FIM DO BLOCO PARA JOGADAS DO USU�RIO.
	system ("cls");
	printf ("\n\n\t\t**** JOGADAS ESGOTADAS. FIM DE JOGO. ****");
	printf ("\t\tPontuacao obtida: %d", score);
    system ("pause");
}
