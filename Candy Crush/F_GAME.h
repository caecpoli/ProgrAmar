#ifndef F_GAME_H_INCLUDED
#define F_GAME_H_INCLUDED
#define Enter 13
#define Seta 16
#define ESC 27
#define MAX 65
#define Lim_Jogadas1 5
#define Lim_Jogadas2 10
#define Lim_Jogadas3 15

typedef struct j
{
char nick[20];
unsigned int pontos;
}jogador;

void GAME();
    void Impressao_All_Map(char x, char y, char z, char Qual_Map);
    int Verifica_Horizontal(char m, char n, char x, char y, char k);
    int Verifica_Vertical(char m, char n, char x, char y, char k);
    void randomizar(char m, char n, char x, char y);
    void Correcao_do_rand(char m, char n, char x, char y);

        int Dificuldade();

            void D_Easy();
            void D_Easy2();
            void D_Easy3();

            void D_Medium();
            void D_Medium2();
            void D_Medium3();

            void D_Hard();
            void D_Hard2();
            void D_Hard3();

            void Trocar_Pecas();
            void Passar_nvl_Facil(unsigned int ptr_score);
            void Passar_nvl_Med(unsigned int ptr_score);
            void Passar_nvl_Hard(unsigned int ptr_score);
            int Desistir(int Qual_nvl);

#endif // F_GAME_H_INCLUDED

