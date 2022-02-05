#include <stdio.h>
#include <stdlib.h>
#include "Libs/ler_arquivo.h"
int main(void){
    Dados_Cidades dados_cidades;
    Cidades cidades;
    char nome_arquivo[1000];
    printf("DIGITE O NOME DO ARQUIVO DE ENTRADA: ");
    scanf(" %[^\n]s ",nome_arquivo);
    //Chama a função que vai ler os dados do arquivo
    ler_arquivo(&dados_cidades,&cidades ,nome_arquivo);
    int N, p;
    N = get_N(&dados_cidades);
    p = N - 1;
    gerar_arranjos(&cidades, N - 1, p);
    system("pause");
    return 0;
}