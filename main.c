#include <stdio.h>
#include <stdlib.h>
#include "Libs/ler_arquivo.h"
int main(void){
    char nome_arquivo[1000];
    printf("DIGITE O NOME DO ARQUIVO DE ENTRADA: ");
    scanf(" %[^\n]s ",nome_arquivo);
    ler_arquivo(nome_arquivo);
    system("pause");
    return 0;
}