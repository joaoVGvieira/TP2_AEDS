#include "../Libs/gerar_arranjos.h"
#include <stdio.h>
#include <stdlib.h>
//Função que cria o vetor de onde será pego 
void cria_vetor_cidade(Arranjos *arranjos, int N){
    arranjos->cidades = (int*)malloc((N-1) * sizeof(int));
    for(int i = 0; i < N - 1; i++){
        arranjos->cidades[i] = i+1;
    }
}

void free_vetor_cidade(Arranjos *arranjos){
    free(arranjos->cidades);
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
    // *num vai ser receber um array de tamanhao p+1 para armazenar 
    int *num ;
    // sao os contadores
    int i, j;
    // criacao do array p+1
    // calloc faz todas posiçoes do array ficar 0
    num = (int *)calloc(p+1, sizeof(int));
    //esse while enquanto num[r] for igual a 0 vai percorrendo o array
    int *aux;
    int soma_aux;
    int capacidade_caminhao = get_capacidade_caminhao(dados_cidades);
    aux = (int*)malloc((p+3)*sizeof(int));
    while ( num[p] == 0 ){
        for(i=0; i < N; i++){
            // aqui vai conferir se tem alguma repetição e caso tenha vai ignorar
            // caso nao seja a repetida a rota ira ser gardada
            int soma_aux = 0;
            int count = 0;
            if ( verifica_repeticoes_arranjos(num, p) ){
                // coloca 0 no começo
                aux[count] = 0;
                count++;
                for(j=0; j < p; j++) {
                    // guarda o arranjo gerado das cidades
                    aux[count] = arranjos->cidades[num[j]];
                    //soma a demanda das cidades presente no arranjo
                    soma_aux += get_vetor_Q_Qi(dados_cidades, arranjos->cidades[num[j]]);
                    count++;
                }
                // coloca 0 no final
                aux[count] = 0;
                count++;
                aux[count] = -1;
                // quando a soma da demanda for maior que a capacidade da demanda nao passa pelo if;
                if(soma_aux <= capacidade_caminhao){
                    // retorna o numero de arranjos uteis
                    int m = get_arranjos_uteis(arranjos);
                    for(int a = 0; a <= count; a++){
                        arranjos->arranjos[m][a] = aux[a];
                    }
                    //incremeta +um arranjo
                    set_arranjos_uteis(arranjos);
                }
            }
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
    // faz ficar recursivo
    return (gerar_arranjos(dados_cidades, arranjos, N, (p-1)));
}
// Cria o vetor arranjo
void cria_vetor_arranjos(Arranjos *arranjos, int total_arranjos, int M){
    arranjos->arranjos = (int**)malloc(total_arranjos * sizeof(int*));
    for(int i = 0; i < total_arranjos; i++){
        arranjos->arranjos[i] = (int*)malloc(M * sizeof(int));
    }
}
//Libera a memória alocada dinamicamente para vetor_arranjos
void free_vetor_arranjos(Arranjos *arranjos, int total_arranjos){
    for(int i = 0; i < total_arranjos; i++){
        free(arranjos->arranjos[i]);
    }
    free(arranjos->arranjos);
}

//Função que calcula o total de arranjos possiveis
int set_total_arranjos(Arranjos *arranjos, int N, int P){
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
