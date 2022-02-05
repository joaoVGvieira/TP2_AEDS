#include "../Libs/ler_arquivo.h"
// Vai ler o arquivo de teste
void ler_arquivo(char nome_arquivo[1000]){
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
    //Os printf são so para eu texta ens uns arquivos e saber que está sendo lido direito
    //Vai apagar os printf depois
    printf("N= %d\n", N);
    printf("Qv= %d\n", Qv);
    int Q[N];
    //Lê a demanda das N cidades que estão na 3ª linha do arquivo e guarda em um vetor Q
    for (int i = 0; i < N; i++){
        fscanf(file,"%d\n",&Q[i]);
        printf("%d ", Q[i]);
    }
    printf("\n");
    
    //A matriz m vai ser feita em outro lugar
    int m[N][N];
    int i, j, dist, aux = 0;
    //Lê as proximas linhas do arquivo, que contém a distância entre a cidade i e a cidade j
    //Em cada uma dessas linhas lê a cidade i, a cidade j, e a distância entre elas, respectivamente
    while (!feof(file)){
        fscanf(file,"%d %d %d",&i,&j, &dist);
        //printf("i=%d\n", i);
        m[i][j] = dist;
        m[j][i] = dist;
        m[aux][aux] = 0;
        aux++;
    }
    //Outro printf que e só para testar
    for (int i = 0; i < N; i++){
        printf("[ ");
        for(int j = 0; j <N; j++){
            printf("%d ", m[i][j]);
        }
        printf("]\n");
    }
    fclose(file);
}
//main para testar o arquivo
int main()
{
    ler_arquivo("teste.txt");
    return 0;
}
