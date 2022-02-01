#include <stdio.h>
#include <stdlib.h>
int main(void){
    int operacao_sistema; 
    char nome[1000];
    char arquivo_saida[1000];
    do
    {
    printf("\n\n");    
    printf(
          " _________________(MENU PRINCIPAL)___________________ \n"
          "|                                                    |\n"
          "| ESCOLHA UMA DAS SEGUINTES FORMAS DE INICIALIZACAO: |\n"
          "|                                                    |\n"
          "| INTERATIVO = 1                                     |\n"
          "| POR ARQUIVO = 2                                    |\n"
          "| ENCERRAR OPERACOES = 0                             |\n"
          "|____________________________________________________|\n");
    printf("DIGITE A OPERACAO DESEJADA: ");
    scanf("%d",&operacao_sistema);
    switch (operacao_sistema) {
        case 0:
            break;
        case 1:
            //criar um menu para o interativo
            break;
        case 2:
             printf("DIGITE O NOME DO ARQUIVO DE ENTRADA: ");
             scanf(" %[^\n]s ",nome);
            break;  
        default:
            printf("\n\n-----Opção inválida!!!!-----\n\n");
        }
    }while (operacao_sistema!=0);   
    printf("\n\n-----VOLTE SEMPRE!!!-----\n\n"); 
    system("pause");
    return 0;
}