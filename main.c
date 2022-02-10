#include <stdio.h>
#include <stdlib.h>
#include "Libs/solucao.h"
#include <time.h>

int main(void){
    clock_t tempo_execu;
    Dados_Cidades dados_cidades;
    Arranjos arranjos;
    Solucao solucao;
    char nome_arquivo[1000];
    printf("DIGITE O NOME DO ARQUIVO DE ENTRADA: ");
    scanf(" %[^\n]s ",nome_arquivo);
    tempo_execu = clock();
    ler_arquivo(&dados_cidades,&arranjos ,nome_arquivo);
    int N, p;
    N = get_N(&dados_cidades);
    p = N - 1;
    set_total_arranjos(&arranjos, N-1,p);
    int total_arranjos = get_total_arranjos(&arranjos);
    cria_vetor_arranjos(&arranjos, total_arranjos, N+2);
    gerar_arranjos(&dados_cidades, &arranjos, N - 1, p);
    cria_vetor_melhor_solucao(&solucao, (3*N));
    set_menor_distancia(&solucao, 0);
    melhor_solucao(&dados_cidades, &arranjos, &solucao);
    imprime_melhor_solucao(&dados_cidades, &solucao);
    free_vetor_M(&dados_cidades, N);
    free_vetor_Q(&dados_cidades, N);
    free_vetor_arranjos(&arranjos, total_arranjos);
    free_vetor_cidade(&arranjos);
    free_vetor_melhor_solucao(&solucao);
    tempo_execu =  clock()- tempo_execu;
    printf("\nTempo De Execucao: %f segundos\n\n",(((float)tempo_execu)/(float)CLOCKS_PER_SEC));
    system("pause");
    return 0;
}