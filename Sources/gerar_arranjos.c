#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char eh_sem_repeticao(int *num, int r) {
    int i, j ;
    for(i=0; i < r; i++) {
        for(j=0; j < r && i != j; j++) {
            if(num[i] == num[j]) {
                return 0;
            }
        }
    }
    return 1 ;
}
int main(){
    char *vetor[] = {"1",  "2", "3", "4", NULL};
    char *v[24][4] ;
    int *num ;
    int n ;
    int r ;
    int a = 0;
    int i, j ;
    n = 4;
    printf("Digite um numero para r: ");
    scanf("%d", &r);
    num = (int *)calloc(r+1, sizeof(int));
    while ( num[r] == 0 ) {
        for(i=0; i < n; i++) {
            if ( eh_sem_repeticao(num, r) ) {
                for(j=0; j < r; j++) {
                    printf("%s ", vetor[num[j]]);
                    v[a][j] = vetor[num[j]];
                }
                a++;
                printf("\n");
            }
            num[0]++ ;
        }
        for(i=0; i < r; i++) {
            if(num[i] == n) {
                num[i] = 0;
                num[i+1]++ ;
            }
        }
    }
    /*
    printf("\n");
    for(i = 0; i < 24; i++){
        for(j = 0; j < n; j++){
            printf("%s ", v[i][j]);
        }
        printf("\n");
    }
    */
    free(num) ;
    return 0;
}