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
void set_vetor_M(Dados_Cidades *dados_cidades, int i, int j, int dist){
    dados_cidades->M[i][j] = dist;
    dados_cidades->M[j][i] = dist;
    dados_cidades->M[j][j] = 0;
    dados_cidades->M[0][0] = 0;
}
int get_vetor_M(Dados_Cidades *dados_cidades, int i, int j){
    return dados_cidades->M[i][j];
}

void set_vetor_Q_Qi(Dados_Cidades *dados_cidades, int i, int Qi){
    dados_cidades->Q[i][0] = Qi;
}
int get_vetor_Q_Qi(Dados_Cidades *dados_cidades, int i){
    return dados_cidades->Q[i][0];
}
void set_vetor_Q_marcador(Dados_Cidades *dados_cidades, int i, int marcador){
    dados_cidades->Q[i][1] = marcador;
}
int get_vetor_Q_marcador(Dados_Cidades *dados_cidades, int i){
    return dados_cidades->Q[i][1];
}
void set_capacidade_caminhao(Dados_Cidades *dados_cidades, int Qv){
    dados_cidades->capacidade_caminhao = Qv;
}
int get_capacidade_caminhao(Dados_Cidades *dados_cidades){
    return dados_cidades->capacidade_caminhao;
}

void set_soma_demanda(Dados_Cidades *dados_cidades, int Qi){
    dados_cidades->soma_demanda += Qi;
}
int get_soma_demanda(Dados_Cidades *dados_cidades){
    return dados_cidades->soma_demanda;
}

void set_N(Dados_Cidades *dados_cidades, int N){
    dados_cidades->N = N;
}
int get_N(Dados_Cidades *dados_cidades){
    return dados_cidades->N;
}
