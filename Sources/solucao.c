#include "../Libs/solucao.h"

void cria_vetor_melhor_solucao(Solucao *solucao, int M){
    solucao->melhor_solucao = (int*)calloc(M, sizeof(int));
}
void free_vetor_melhor_solucao(Solucao *solucao){
    free(solucao->melhor_solucao);
}
void set_menor_distancia(Solucao *solucao, int num){
    solucao->menor_distancia = num;
}
int get_menor_distancia(Solucao *solucao){
    return solucao->menor_distancia;
}
//Função que escolhe a melhor solucao
void melhor_solucao(Dados_Cidades *dados_cidades, Arranjos *arranjos, Solucao *solucao){
    int N = get_N(dados_cidades);
    //Quantidade de arranjos uteis se refere a quantidade de arranjos que são elegiveis
    //para estar na solução
    int arranjos_uteis = get_arranjos_uteis(arranjos);
    int qtd_caminhoes, soma_demanda, capacidade_caminhao;
    soma_demanda = get_soma_demanda(dados_cidades);
    //Quantidade de caminhoes também é a quantidade de petalas presente na solução
    capacidade_caminhao = get_capacidade_caminhao(dados_cidades);
    if(soma_demanda % capacidade_caminhao != 0){
    qtd_caminhoes = soma_demanda / capacidade_caminhao + 1;
    }
    else{
    qtd_caminhoes = soma_demanda / capacidade_caminhao;
    }
    int i, j;
    //Vetor que garda o arranjo gerado com as posiçoes dos arranjos uteis do vetor arranjos
    //pois para escolher a melhor solução, o algoritimo gera todos as possiveis soluçoes 
    int *indice;
    indice = (int*)malloc(qtd_caminhoes * sizeof(int));
    //Guarda a possivel solução até ser verificada
    int *possivel_solucao;
    possivel_solucao = (int*)malloc((qtd_caminhoes*(N+2)) * sizeof(int));
    //O vetor numeracao_arranjos e um vetor preenchido de 0 até arranjos_uteis - 1, que 
    // é a possição do arranjo util no vetor arranjos
    int *numeracao_arranjos;
    numeracao_arranjos = (int*)malloc(arranjos_uteis * sizeof(int));
    for(i = 0; i < arranjos_uteis; i++){
        numeracao_arranjos[i] = i;
    }
    int aux1, aux2,l,c;
    int *num ;
    num = (int *)calloc(qtd_caminhoes+1, sizeof(int));
    //Aqui gera o arranjos (n!/(n-p)!) onde n = arranjos_uteis e p = qtd_caminhos
    //Onde o arranjo gerado são as posiçoes dos possiveis arranjos(cidades) no vetor arranjos
    while ( num[qtd_caminhoes] == 0 ) {
        for(i=0; i < arranjos_uteis; i++) { 
            if (verifica_repeticoes_arranjos(num, qtd_caminhoes) ) {
                for(j=0; j < qtd_caminhoes; j++) {
                    indice[j] = numeracao_arranjos[num[j]];
                }
                int count = 0;
                int distancia = 0;
                int continuar = 1;
                for(l = 0; l < N; l++){
                    set_vetor_Q_marcador(dados_cidades, l, 0);
                }
                possivel_solucao[count] = 0;
                count++;
                //Faz a possivel solução atravez do arranjo gerado, que é a possição dos arranjos(cidades) no vetor arranjos
                for(l = 0; l < qtd_caminhoes; l++){
                    for(c = 0; c <= (N+2); c++){
                        aux1 = get_arranjos(arranjos, indice[l], c);
                        aux2 = get_arranjos(arranjos, indice[l], c+1);
                        if(c == 0 ){
                            possivel_solucao[count] = aux1;
                        }
                        else{
                            possivel_solucao[count] = aux1;
                            count++;
                        }
                        if(aux1 != 0 && get_vetor_Q_marcador(dados_cidades, aux1) == 1){
                                continuar = 0;
                        }
                        set_vetor_Q_marcador(dados_cidades, aux1, 1);
                        if(aux2 == -1){
                            break;
                        }
                        distancia += get_vetor_M(dados_cidades, aux1, aux2);
                    }
                }

                possivel_solucao[count] = -1;
                //Verifica se a possivel solução e realmente uma solução valida, já que o algoritimo pode fazer se 
                //uma possivel sólução que não contemple todas as cidades, ou faz um possivel solução com arranjos que repetem cidades
                if((continuar == 1) && (verifica_marcadores(dados_cidades) == 1)){
                    //Quando e gerada a 1ª solução entra neste if, é coloca a possivel solução como melhor solução
                    if(get_menor_distancia(solucao) == 0){
                        set_menor_distancia(solucao, distancia);
                        for(l = 0; l <= count; l++){
                            solucao->melhor_solucao[l] = possivel_solucao[l];
                        }
                    }
                    //Nas demais soluçoes e verificado se a distancia desta solução é menor
                    // que a da melhor solução, se for ela se torna a melho solução
                    if(distancia < get_menor_distancia(solucao)){
                        set_menor_distancia(solucao, distancia);
                        for(l = 0; l <= count; l++){
                            solucao->melhor_solucao[l] = possivel_solucao[l];
                        }
                    }
                }
            }
            num[0]++ ;
        }
        for(i=0; i < qtd_caminhoes; i++) {
            if(num[i] == arranjos_uteis) {
                num[i] = 0;
                num[i+1]++ ;
            }
        }
    }
    free(num);
    free(indice);
    free(possivel_solucao);
    free(numeracao_arranjos);
}

// Função que imprime a melhor solução
void imprime_melhor_solucao(Dados_Cidades *dados_cidades, Solucao *solucao){
    printf("\nS=[ ");
    int i = 0;
    int aux;
    while (1){
        aux = solucao->melhor_solucao[i];
        if(aux == -1){
            break;
        }
        printf("%d ", aux);
        i++;
    }
    printf("]\n");
}
