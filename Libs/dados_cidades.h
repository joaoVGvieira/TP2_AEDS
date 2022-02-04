#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **M;
    int **Q;
    int soma_demanda;
}Dados_Cidades;

void cria_vetor_M(Dados_Cidades *dados_cidades, int N);
void cria_vetor_Q(Dados_Cidades *dados_cidades, int N);
