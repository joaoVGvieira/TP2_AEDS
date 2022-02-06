#include "../Libs/gerar_arranjos.h"
#include <stdio.h>
#include <stdlib.h>
//Função que cria o vetor de onde será pego 
void vetor_cidade(Arranjos *arranjos, int N){
    arranjos->cidades = (int*)malloc((N-1) * sizeof(int));
    for(int i = 0; i < N - 1; i++){
        arranjos->cidades[i] = i+1;
    }
}
// esse vai comparar a repeticao dos numeros no array
int verifica_repeticoes_arranjos(int *num, int p) {
    int i, j ;
    for(i=0; i < p; i++) {
        for(j=0; j < p && i != j; j++) {
            if(num[i] == num[j]) {
                return 0;
            }
        }
    }
    return 1 ;
}
int gerar_arranjos(Dados_Cidades *dados_cidades ,Arranjos *arranjos, int N, int p){
    // ser p for igual a 0 retorna
    if (p == 0){
        return 0;
    }
    // *num vai ser receber um array de tamanhao r+1 para armazenar 
    int *num ;
    // sao os contadores
    int i, j;
    // criacao do array r+1
    // calloc faz todas posiçoes do array ficar 0
    num = (int *)calloc(p+1, sizeof(int));
    //esse while enquanto num[r] for igual a 0 vai percorrendo o array
    int *aux;
    int soma_aux;
    int capacidade_caminhao = get_capacidade_caminhao(dados_cidades);
    aux = (int*)malloc((p+2)*sizeof(int));
    while ( num[p] == 0 ){
        for(i=0; i < N; i++){
            // aqui vai conferir se tem alguma repetição e caso tenha vai ignorar
            // caso nao seja a repetida a rota ira imprimir no terminal
            int soma_aux = 0;
            int count = 0;
            if ( verifica_repeticoes_arranjos(num, p) ){
                aux[count] = 0;
                //printf("-0 ");
                count++;
                for(j=0; j < p; j++) {
                    //printf("%d ", arranjos->cidades[num[j]]);
                    aux[count] = arranjos->cidades[num[j]];
                    soma_aux += get_vetor_Q_Qi(dados_cidades, arranjos->cidades[num[j]]);

                    count++;
                }
                aux[count] = 0;
               // printf("0 %d\n", soma_aux);
                if(soma_aux <= capacidade_caminhao){
                    //copia_arranjos(arranjos, get_arranjos_uteis(arranjos), count);
                    int m = get_arranjos_uteis(arranjos);
                   // printf("+");
                    for(int a = 0; a <= count; a++){
                        arranjos->arranjos[m][a] = aux[a];
                        //printf("%d ", get_arranjos(arranjos, m, a));
                    }
                    //printf("\n");
                    set_arranjos_uteis(arranjos);
                }
            }
            //nao entendi
            num[0]++ ;
        }
        //Essa vai limitar o loop do while 
        for(i=0; i < p; i++) {
            if(num[i] == N) {
                num[i] = 0;
                num[i+1]++ ;
            }
        }
    }
    free(aux);
    free(num);
    return (gerar_arranjos(dados_cidades, arranjos, N, (p-1)));
}
/*void copia_arranjos(Arranjos *arranjos, int i, int j){
    for(int p = 0; p <= j; p++){
        arranjos->arranjos[i][j] = 
    }
}*/
void liber_vetor_cidade(Arranjos *arranjos){
    free(arranjos->cidades);
}

void cria_vetor_arranjos(Arranjos *arranjos, int total_arranjos, int M){
    arranjos->arranjos = (int**)malloc(total_arranjos * sizeof(int*));
    for(int i = 0; i < total_arranjos; i++){
        arranjos->arranjos[i] = (int*)malloc(M * sizeof(int));
    }
}
int set_total_arranjos(Arranjos *arranjos, int N, int P){
    int n = N;
    int p = N - P;
    int fact_N = 1;
    int fact = 1;
    int i;
    for(i = N; i>= 1;i-- ){
        fact_N *= i;
    }
    for(i = p; i>= 1;i-- ){
        fact *= i;
    }
    arranjos->total_arranjos += (fact_N/fact);
    if (P == 1){
        return 0;
    }
    return(set_total_arranjos(arranjos, N, P-1));
}
int get_total_arranjos(Arranjos *arranjos){
    return arranjos->total_arranjos;
}
void set_arranjos_uteis(Arranjos *arranjos){
    arranjos->arranjos_uteis += 1;
}
int get_arranjos_uteis(Arranjos *arranjos){
    return arranjos->arranjos_uteis;
}

int get_arranjos(Arranjos *arranjos, int i, int j){
    return arranjos->arranjos[i][j];
}