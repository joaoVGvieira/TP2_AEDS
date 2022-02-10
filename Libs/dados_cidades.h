#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int **M;
    int **Q;
    int soma_demanda;
    int capacidade_caminhao;
    int N;
}Dados_Cidades;
//Cria o vetor M que armazena a distancia entre as N cidades
void cria_vetor_M(Dados_Cidades *dados_cidades, int N);

//Cria o vetor Q que armazena as demandas das N cidades, e um marcador que indica
// se a cidade já foi atendida
void cria_vetor_Q(Dados_Cidades *dados_cidades, int N);

//Função que tem como objetivo liberar a memória alocada dinamicamente para os vetores M e Q
void free_vetor_M(Dados_Cidades *dados_cidades, int N);
void free_vetor_Q(Dados_Cidades *dados_cidades, int N);

//Função que verifica se todas as cidades foram atendidas
int verifica_marcadores(Dados_Cidades *dados_cidades);

// gets e sets:
void set_vetor_M(Dados_Cidades *dados_cidades, int i, int j, int dist);
int get_vetor_M(Dados_Cidades *dados_cidades, int i, int j);

void set_vetor_Q_Qi(Dados_Cidades *dados_cidades, int i, int Qi);
int get_vetor_Q_Qi(Dados_Cidades *dados_cidades, int i);
void set_vetor_Q_marcador(Dados_Cidades *dados_cidades, int i, int marcador);
int get_vetor_Q_marcador(Dados_Cidades *dados_cidades, int i);

void set_capacidade_caminhao(Dados_Cidades *dados_cidades, int Qv);
int get_capacidade_caminhao(Dados_Cidades *dados_cidades);

void set_soma_demanda(Dados_Cidades *dados_cidades, int Qi);
int get_soma_demanda(Dados_Cidades *dados_cidades);

void set_N(Dados_Cidades *dados_cidades, int N);
int get_N(Dados_Cidades *dados_cidades);