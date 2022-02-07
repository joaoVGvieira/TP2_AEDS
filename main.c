#include <stdio.h>
#include <stdlib.h>
#include "Libs/solucao.h"
//#include "Libs/ler_arquivo.h"
int main(void){
    Dados_Cidades dados_cidades;
    Arranjos arranjos;
    Solucao solucao;
    char nome_arquivo[1000];
    printf("DIGITE O NOME DO ARQUIVO DE ENTRADA: ");
    scanf(" %[^\n]s ",nome_arquivo);
    //Chama a função que vai ler os dados do arquivo
    ler_arquivo(&dados_cidades,&arranjos ,nome_arquivo);
    int N, p;
    N = get_N(&dados_cidades);
    p = N - 1;
    set_total_arranjos(&arranjos, N-1,p);
    int total_arranjos = get_total_arranjos(&arranjos);
    cria_vetor_arranjos(&arranjos, total_arranjos, N+2);
    gerar_arranjos(&dados_cidades, &arranjos, N - 1, p);
    int arranjos_uteis = get_arranjos_uteis(&arranjos);
    cria_vetor_solucao(&solucao, (3*N));
    printf("Total arranjos uteis -> %d\n", get_arranjos_uteis(&arranjos));
    set_menor_distancia(&solucao, 0);
    //Erro aqui
    melhor_solucao(&dados_cidades, &arranjos, &solucao);
    imprime_melhor_solucao(&dados_cidades, &solucao);
    
    system("pause");
    return 0;
}