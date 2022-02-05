#include "../Libs/gerar_arranjos.h"
#include <stdio.h>
#include <stdlib.h>
//Função que cria o vetor de onde será pego 
void vetor_cidade(Cidades *cidade, int N){
    cidade->cidades = (int*)malloc((N-1) * sizeof(int));
    for(int i = 0; i < N - 1; i++){
        cidade->cidades[i] = i+1;
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
void gerar_arranjos(Cidades *cidade, int N, int p){
    // ser p for igual a 0 retorna
    if (p == 0){
        return 0;
    }
    // *num vai ser receber um array de tamanhao r+1 para armazenar 
    int *num ;
    // sao os contadores
    int i, j ;
    // criacao do array r+1
    // calloc faz todas posiçoes do array ficar 0
    num = (int *)calloc(p+1, sizeof(int));
    //esse while enquanto num[r] for igual a 0 vai percorrendo o array
    while ( num[p] == 0 ) {
        for(i=0; i < N; i++) {
            // aqui vai conferir se tem alguma repetição e caso tenha vai ignorar
            // caso nao seja a repetida a rota ira imprimir no terminal
            if ( verifica_repeticoes_arranjos(num, p) ) {
                for(j=0; j < p; j++) {
                    printf("%d ", cidade->cidades[num[j]]);

                }
                printf("\n");
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
    free(num);
    return (gerar_arranjos(cidade, N, (p-1)));
}
void liber_vetor_cidade(Cidades *cidade){
    free(cidade->cidades);
}
// essa main foi feita para testar o codigo encontrado

int main(){
    Cidades cidade;
    int N , p;
    // esse p é o numero ultilizado na formula de arranjo vai ser tipo n!/(n-r)!
    printf("Digite um numero para N: ");
    scanf("%d", &N);
    p = N - 1;
    // Ao lêr o valor de N, simula como se estivesse lendo o N do arquivo. O programa
    // vai gerar arranjos de 1 até (N-1). Ex: N= 5, vai gerrar o arranjo entre 1,2,3,4
    vetor_cidade(&cidade, N);
    gerar_arranjos(&cidade, N - 1, p);
    liber_vetor_cidade(&cidade);
    system("pause");
    return 0;
}
