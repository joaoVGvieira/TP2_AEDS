#include "../Libs/ler_arquivo.h"

// Vai ler o arquivo de teste
void ler_arquivo(Dados_Cidades *dados_cidades ,Arranjos *arranjos ,char nome_arquivo[1000]){
    dados_cidades->soma_demanda = 0;
    arranjos->arranjos_uteis = 0;
    arranjos->total_arranjos = 0;
    FILE *file = fopen(nome_arquivo,"r");
    if(file==NULL){
        printf("Erro para abrir o arquivo de leitura!!!!");
        exit(1);
    }
    // Quantidade de cidades
    int N;
    //Capacidade suportada pelos caminhões
    int Qv;
    //Lê a 1ª linha do arquivo
    fscanf(file,"%d\n",&N);
    //Lê a 2ª linha do arquivo
    fscanf(file,"%d\n",&Qv);
    set_capacidade_caminhao(dados_cidades, Qv);
    cria_vetor_M(dados_cidades, N);
    cria_vetor_Q(dados_cidades, N);
    cria_vetor_cidade(arranjos, N);
    set_N(dados_cidades, N);
    //Os printf são so para eu texta ens uns arquivos e saber que está sendo lido direito
    //Vai apagar os printf depois
    int Qi;
    int i, j, dist;
    //Lê a demanda das N cidades que estão na 3ª linha do arquivo e guarda em um vetor Q
    for (i = 0; i < N; i++){
        fscanf(file,"%d\n",&Qi);
        set_vetor_Q_Qi(dados_cidades, i, Qi);
        set_vetor_Q_marcador(dados_cidades, i, 0);
        set_soma_demanda(dados_cidades, Qi);
    }
    //Lê as proximas linhas do arquivo, que contém a distância entre a cidade i e a cidade j
    //Em cada uma dessas linhas lê a cidade i, a cidade j, e a distância entre elas, respectivamente
    while (!feof(file)){
        fscanf(file,"%d %d %d",&i,&j, &dist);
        set_vetor_M(dados_cidades, i, j, dist);
    }
    fclose(file);
}
