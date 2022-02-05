#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int *cidades;
}Cidades;
void vetor_cidade(Cidades *cidade, int N);
int verifica_repeticoes_arranjos(int *num, int p);
void gerar_arranjos(Cidades *cidade, int n, int p);