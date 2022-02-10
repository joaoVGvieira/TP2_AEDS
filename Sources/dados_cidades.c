#include "../Libs/dados_cidades.h"
//Função que cria um vetor de tamanho NxN para armazenar a distancia entre as N cidades
void cria_vetor_M(Dados_Cidades *dados_cidades, int N){
    dados_cidades->M = (int**)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
        dados_cidades->M[i] = (int*)malloc(N * sizeof(int));
    }
}

void free_vetor_M(Dados_Cidades *dados_cidades, int N){
    for(int i = 0; i < N; i++){
        free(dados_cidades->M[i]);
    }
    free(dados_cidades->M);
}

//Função que cria um vetor de tamanho Nx2 para armazenar a demanda das N cidades e
// um marcador que indica se a mesma já foi atendida
void cria_vetor_Q(Dados_Cidades *dados_cidades, int N){
    dados_cidades->Q = (int**)malloc(N * sizeof(int*));
    for(int i = 0; i < N; i++){
        dados_cidades->Q[i] = (int*)malloc(2 * sizeof(int));
    }
}

void free_vetor_Q(Dados_Cidades *dados_cidades, int N){
    for(int i = 0; i < N; i++){
        free(dados_cidades->Q[i]);
    }
    free(dados_cidades->Q);
}

// Verifica se todas as cidades foram atendidas. Caso todas as cidades tenhão sido atendidas
// retorna 1, caso contrario retorna 0
int verifica_marcadores(Dados_Cidades *dados_cidades){
    int N = get_N(dados_cidades);
    for(int i = 1; i < N; i++){
        if(get_vetor_Q_marcador(dados_cidades, i) == 0){
            return 0;
        }
    }
    return 1;
}

// Coloca a distancia entre entre as cidades i e j, na posição ixj
// e coloca 0 quando j=j, pois não tem distancia de uma cidade para ela mesmo
void set_vetor_M(Dados_Cidades *dados_cidades, int i, int j, int dist){
    dados_cidades->M[i][j] = dist;
    dados_cidades->M[j][i] = dist;
    dados_cidades->M[j][j] = 0;
    dados_cidades->M[0][0] = 0;
}

// Retorna a distancia entre as cidades ixj
int get_vetor_M(Dados_Cidades *dados_cidades, int i, int j){
    return dados_cidades->M[i][j];
}

// Coloca a demanda da cidade i, na posição ix0
void set_vetor_Q_Qi(Dados_Cidades *dados_cidades, int i, int Qi){
    dados_cidades->Q[i][0] = Qi;
}

// retorna a demanda da cidade i
int get_vetor_Q_Qi(Dados_Cidades *dados_cidades, int i){
    return dados_cidades->Q[i][0];
}

//Coloca o marcador na posição ix1 para saber se a cidade i já foi atendida
// 1 já foi atendida, 0 ainda não foi atendida
void set_vetor_Q_marcador(Dados_Cidades *dados_cidades, int i, int marcador){
    dados_cidades->Q[i][1] = marcador;
}

// Retorna o marcador da cidade i
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
