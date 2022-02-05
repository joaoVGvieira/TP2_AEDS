#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int *cidades;
}Cidades;
//Função que armázena o número das N cidades exceto o deposito, de onde será tirado os
// números para fazer os arranjos
void vetor_cidade(Cidades *cidade, int N);
//Função que tem como objetivo liberar a memória alocada dinamicamente para o vetor cidade
void liber_vetor_cidade(Cidades *cidade);
int verifica_repeticoes_arranjos(int *num, int p);
void gerar_arranjos(Cidades *cidade, int n, int p);