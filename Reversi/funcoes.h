#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void mostrar(char tabuleiro[][TAM]);
int jog_validas(char tabuleiro[][TAM], int jogada[][TAM], char jogador);
void faz_jogada(char tabuleiro[][TAM], int linha, int coluna, char jogador);
int get_placar(char tabuleiro[][TAM], char jogador);
int menu();
int vez;
void save_pontos(char *nome_j1, char *nome_j2, int placar_j1, int placar_j2);
void get_historico();

#endif // FUNCOES_H_INCLUDED
