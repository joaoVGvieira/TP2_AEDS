#include "../Libs/dados_cidades.h"
//Função que cria um vetor de tamanho NxN para armazenar a distancia entre as N cidades
void cria_vetor_M(Dados_Cidades *dados_cidades, int N){
    dados_cidades->M = (int**)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
        dados_cidades->M[i] = (int*)malloc(N * sizeof(int));
    }
}
//Função que cria um vetor de tamanho Nx2 para armazenar a demanda das N cidades e
// um marcador que indica se a mesma já foi atendida
void cria_vetor_Q(Dados_Cidades *dados_cidades, int N){
    dados_cidades->Q = (int**)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
        dados_cidades->Q[i] = (int*)malloc(2 * sizeof(int));
    }
}
void libera_vetor_M(Dados_Cidades *dados_cidades, int N){
    for(int i = 0; i < N; i++){
        free(dados_cidades->M[i]);
    }
    free(dados_cidades->M);
}
void libera_vetor_Q(Dados_Cidades *dados_cidades, int N){
    for(int i = 0; i < N; i++){
        free(dados_cidades->Q[i]);
    }
    free(dados_cidades->Q);
}
