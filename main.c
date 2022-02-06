#include <stdio.h>
#include <stdlib.h>
#include "Libs/ler_arquivo.h"
int main(void){
    Dados_Cidades dados_cidades;
    Arranjos arranjos;
    char nome_arquivo[1000];
    printf("DIGITE O NOME DO ARQUIVO DE ENTRADA: ");
    scanf(" %[^\n]s ",nome_arquivo);
    //Chama a função que vai ler os dados do arquivo
    ler_arquivo(&dados_cidades,&arranjos ,nome_arquivo);
    int N, p;
    N = get_N(&dados_cidades);
    p = N - 1;
    set_total_arranjos(&arranjos, N-1,p);
    printf("Total-> %d\n", get_total_arranjos(&arranjos));
    int total_arranjos = get_total_arranjos(&arranjos);
    cria_vetor_arranjos(&arranjos, total_arranjos, N+1);
    gerar_arranjos(&dados_cidades, &arranjos, N - 1, p);
    printf("Total-> %d\n", get_arranjos_uteis(&arranjos));
    int arranjos_uteis = get_arranjos_uteis(&arranjos);

    //Print só nós arranjos possiveis
    int i;
    int j;
    int a;
    for(i = 0; i< arranjos_uteis; i++){
        printf("%.2d->", i);
        for(j = 0; j <= N; j++){
            a = get_arranjos(&arranjos, i, j);
            //printf("%d ", get_arranjos(&arranjos, i, j));
            printf("%d ", a);
            if(j != 0 && a == 0){
                break;
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}