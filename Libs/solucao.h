#include "../Libs/ler_arquivo.h"

typedef struct{
    int *melhor_solucao;
    int menor_distancia;
}Solucao;

void cria_vetor_melhor_solucao(Solucao *solucao, int M);
void free_vetor_melhor_solucao(Solucao *solucao);
void melhor_solucao(Dados_Cidades *dados_cidades, Arranjos *arranjos, Solucao *solucao);
void imprime_melhor_solucao(Dados_Cidades *dados_cidades, Solucao *solucao);
int verifica_marcadores(Dados_Cidades *dados_cidades);
//gets e sets
void set_menor_distancia(Solucao *solucao, int num);
int get_menor_distancia(Solucao *solucao);
