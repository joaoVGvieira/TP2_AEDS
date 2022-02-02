/*
Precisa ainda ageitar direito
*/
#include <stdio.h>
#include <stdlib.h>
#include "Libs/ler_arquivo.h"
// Vai ler o arquivo de teste
void ler_arquivo(char nome_arquivo[1000]){
    FILE *file = fopen(nome_arquivo,"r");
    if(file==NULL){
        printf("Erro para abrir o arquivo de leitura!!!!");
        exit(1);
    }
    int N;
    // Quantidade de cidades
    int Qv;
    //Capacidade suportada pelos caminhões
    if (file){
        fscanf(file,"%d\n",&N);
        fscanf(file,"%d\n",&Qv);
    }
    printf("N= %d\n", N);
    printf("Qv= %d\n", Qv);
    int dista[N];
    for (int i = 0; i < N; i++){
        fscanf(file,"%d\n",&dista[i]);
        printf("%d ", dista[i]);
    }
    printf("\n");
    
    //A matriz m vai ser feita em outro lugar
    int m[N][N];
    int j, p, d, i = 0;
    while (!feof(file)){
        printf("i=%d\n", i);
        fscanf(file,"%d %d %d",&j,&p, &d);
        m[j][p] = d;
        m[p][j] = d;
        m[i][i] = 0;
        i++;
    }
    for (int i = 0; i < N; i++){
        printf("[ ");
        for(int j = 0; j <N; j++){
            printf("%d ", m[i][j]);
        }
        printf("]\n");
    }
    fclose(file);
}