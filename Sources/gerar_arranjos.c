//#include "Libs/gerar_arranjos.h"
#include <stdio.h>
#include <stdlib.h>
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
void gerar_arranjos(int *vetor, int n, int p){
    // ser r for igual a 0 retorna
    if (p == 0){
        return 0;
    }
    char *v[24][4] ;
    // *num vai ser receber um array de tamanhao r+1 para armazenar 
    int *num ;
    // a vai ser um contador para matriz
    int a = 0;
    // sao os contadores
    int i, j ;
    // criacao do array r+1
    // calloc faz todas posiçoes do array ficar 0
    num = (int *)calloc(p+1, sizeof(int));
    //esse while enquanto num[r] for igual a 0 vai percorrendo o array
    while ( num[p] == 0 ) {
        for(i=0; i < n; i++) {
            // aqui vai conferir se tem alguma repetição e caso tenha vai ignorar
            // caso nao seja a repetida a rota ira imprimir no terminal
            if ( verifica_repeticoes_arranjos(num, p) ) {
                for(j=0; j < p; j++) {
                    printf("%d ", vetor[num[j]]);
                    //nao entendi
                    v[a][j] = vetor[num[j]];
                }
                //nao entendi
                a++;
                printf("\n");
            }
            //nao entendi
            num[0]++ ;
        }
        //nao entendi
        for(i=0; i < p; i++) {
            if(num[i] == n) {
                num[i] = 0;
                num[i+1]++ ;
            }
        }
    }
    free(num);
    return (gerar_arranjos(vetor, n, (p-1)));
}
// essa main foi feita para testar o codigo encontrado

int main(){
    //char *vetor[] = {"1",  "2", "3", "4", NULL};
    int *vetor[] = {1, 2, 3, 4, NULL};
    int n , r;
    n = 4;
    // esse r é o numero ultilizado na formula de arranjo vai ser tipo n!/(n-r)!
    printf("Digite um numero para r: ");
    scanf("%d", &r);
    gerar_arranjos(&vetor, n, r);
    system("pause");
    return 0;
}
