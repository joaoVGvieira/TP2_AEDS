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
void gerar_arranjos(char *vetor[], int n, int r){
    if (r == 0){
        return 0;
    }
    char *v[24][4] ;
    int *num ;
    int a = 0;
    int i, j ;
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
    free(num);
    return (gerar_arranjos(vetor, n, (r-1)));
}
int main(){
    char *vetor[] = {"1",  "2", "3", "4", NULL};
    int k[24] = {0,1,0,2,0,3,0,4,0,5,0,6,0,7,0,8,0,9,0};
    int n , r;
    n = 4;
    printf("Digite um numero para r: ");
    scanf("%d", &r);
    gerar_arranjos(&vetor, n, r);
    system("pause");
    return 0;
}