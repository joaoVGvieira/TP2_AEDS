#include "../Libs/ler_arquivo.h"

typedef struct{
    int *melhor_solucao;
    int menor_distancia;
}Solucao;

//Função que cria o vetor melhor_solucao
void cria_vetor_melhor_solucao(Solucao *solucao, int M);

//Função que libera memória do vetor alocado dinamicamente
void free_vetor_melhor_solucao(Solucao *solucao);

//Função que escolhe a melhor solução
void melhor_solucao(Dados_Cidades *dados_cidades, Arranjos *arranjos, Solucao *solucao);

//Função que imprime no terminal a melhor solução
void imprime_melhor_solucao(Dados_Cidades *dados_cidades, Solucao *solucao);

//gets e sets
void set_menor_distancia(Solucao *solucao, int num);
int get_menor_distancia(Solucao *solucao);
