
#include <stdio.h>
#include <stdlib.h>
#include "../Libs/arquivo.h"
// Vai ler o arquivo de teste
void ler(char nome[1000]){
    FILE *file = fopen(nome,"r");
    if(file==NULL){
        printf("Erro para abrir o arquivo de leitura!!!!");
        exit(1);
    }


    if (file)
    {
       
    }
    fclose(file);
}
// vai escrever o arquivo de saida
void escreve_arquivo_tempo(char num[20]){
    char arq_sai[] = ("Arquivo_saida.txt");
    char tempo[20];
    FILE *saida = fopen(arq_sai, "a");
    if(saida) {
        
        printf("\nARQUIVO DE SAIDA FOI ATUALIZADO!!!\n");
    } else
        printf("\nERRO ao abrir arquivo de saida!\n");
}