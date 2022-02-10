#include <stdio.h>
#include <stdlib.h>
#include "../Libs/dados_cidades.h"
typedef struct{
    int *cidades;
    int **arranjos;
    int total_arranjos;
    int arranjos_uteis;
}Arranjos;

//Função que armázena o número das N cidades exceto o deposito, de onde será tirado os
// números para fazer os arranjos
void cria_vetor_cidade(Arranjos *arranjos, int N);
//Vetor onde fica armazenados todos os arranjos gerados, desde que atendão as condições
void cria_vetor_arranjos(Arranjos *arranjos, int total_arranjos, int M);
//Função que verifica se foi gerado um arranjo com repetiçoes
int verifica_repeticoes_arranjos(int *num, int p);
//função que gera todos os os arranjos possiveis 
int gerar_arranjos(Dados_Cidades *dados_cidades ,Arranjos *arranjos, int n, int p);
void free_vetor_cidade(Arranjos *arranjos);
void free_vetor_arranjos(Arranjos *arranjos, int total_arranjos);
// gets e sets:
int set_total_arranjos(Arranjos *arranjos, int N, int p);
int get_total_arranjos(Arranjos *arranjos);
void set_arranjos_uteis(Arranjos *arranjos);
int get_arranjos_uteis(Arranjos *arranjos);
int get_arranjos(Arranjos *arranjos, int i, int j);
