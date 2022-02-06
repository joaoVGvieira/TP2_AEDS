#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include "../Libs/dados_cidades.h"
typedef struct{
    int *cidades;
    int **arranjos;
    int total_arranjos;
    int arranjos_uteis;
}Arranjos;
//Função que armázena o número das N cidades exceto o deposito, de onde será tirado os
// números para fazer os arranjos
void vetor_cidade(Arranjos *arranjos, int N);
void cria_vetor_arranjos(Arranjos *arranjos, int total_arranjos, int M);
int set_total_arranjos(Arranjos *arranjos, int N, int p);
int get_total_arranjos(Arranjos *arranjos);
void set_arranjos_uteis(Arranjos *arranjos);
int get_arranjos_uteis(Arranjos *arranjos);
//void copia_arranjos(Arranjos *arranjos, int i, int j);
int get_arranjos(Arranjos *arranjos, int i, int j);
//Função que tem como objetivo liberar a memória alocada dinamicamente para o vetor cidade
void liber_vetor_cidade(Arranjos *arranjos);
int verifica_repeticoes_arranjos(int *num, int p);
int gerar_arranjos(Dados_Cidades *dados_cidades ,Arranjos *arranjos, int n, int p);