#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **M;
    int **Q;
    int soma_demanda;
}Dados_Cidades;
//Cria o vetor M que armazena a distancia entre as N cidades
void cria_vetor_M(Dados_Cidades *dados_cidades, int N);
//Cria o vetor Q que armazena as demandas das N cidades, e um marcador que indica
// se a cidade já foi atendida
void cria_vetor_Q(Dados_Cidades *dados_cidades, int N);
//Função que tem como objetivo liberar a memória alocada dinamicamente para os vetores M e Q
void libera_vetor_M(Dados_Cidades *dados_cidades, int N);
void libera_vetor_Q(Dados_Cidades *dados_cidades, int N);