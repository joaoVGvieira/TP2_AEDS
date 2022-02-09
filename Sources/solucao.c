#include "../Libs/solucao.h"

void cria_vetor_solucao(Solucao *solucao, int M){
    solucao->melhor_solucao = (int*)calloc(M, sizeof(int));
}
void set_menor_distancia(Solucao *solucao, int num){
    solucao->menor_distancia = num;
}
int get_menor_distancia(Solucao *solucao){
    return solucao->menor_distancia;
}

void melhor_solucao(Dados_Cidades *dados_cidades, Arranjos *arranjos, Solucao *solucao){
    int arranjos_uteis = get_arranjos_uteis(arranjos);
    int N = get_N(dados_cidades);
    int *vetor_solucao;
    vetor_solucao = (int*)malloc((3*N) * sizeof(int));
    int *vetor_aux;
    vetor_aux = (int*)calloc((N+2),sizeof(int));
    int l,c,i,j, distancia, aux1, aux2, posi;
    for(i = 0; i < arranjos_uteis; i++){
        for(j = 0; j < N; j++){
            set_vetor_Q_marcador(dados_cidades, j, 0);
        }
        posi = 0;
        distancia = 0;
        for(j = 0; j <= (N + 2); j++){
            aux1 = get_arranjos(arranjos, i, j);
            aux2 = get_arranjos(arranjos, i, j+1);
            vetor_solucao[posi] = aux1;
            posi++;
            if(aux2 == -1){
                break;
            }
            distancia += get_vetor_M(dados_cidades, aux1, aux2);
            set_vetor_Q_marcador(dados_cidades, aux1, 1);
        }
        vetor_solucao[posi] = -1;
        for(c = 0; c < arranjos_uteis; c++){
            int posi1 = posi;
            int dist1 = distancia;
            int qual = 0;
            int recomeca;
            int sair = 0;
            l = 0;
            while(1){
                if(l >= arranjos_uteis){
                    break;
                }
                recomeca = 0;
                if(qual == 0){
                    qual = 1;
                    for(j = 0; j <= (N + 2); j++){
                        aux1 = get_arranjos(arranjos, c, j);
                        vetor_aux[j] = aux1;
                        if(aux1 == -1){
                            break;
                        }
                    }
                }
                else{
                    for(j = 0; j <= (N + 2); j++){
                        aux1 = get_arranjos(arranjos, l, j);
                        vetor_aux[j] = aux1;
                        if(aux1 == -1){
                            break;
                        }
                    }
                    l++;
                }
                int a;
                for(j = 0; j <= (N + 2); j++){
                    aux1 = vetor_aux[j];
                    if(aux1 == -1){
                        break;
                    }
                    a = get_vetor_Q_marcador(dados_cidades, aux1);
                    if(aux1 != 0 && a == 1){
                        recomeca = 1;
                        break;
                    }
                }    
                if(recomeca == 0){
                    l = 0;
                    for(j = 0; j <= (N + 2); j++){
                        aux1 = vetor_aux[j];
                        aux2 = vetor_aux[j+1];
                        vetor_solucao[posi1] = aux1;
                        posi1++;
                        if(aux2 == -1){
                            break;
                        }
                        dist1 += get_vetor_M(dados_cidades, aux1, aux2);
                        set_vetor_Q_marcador(dados_cidades, aux1, 1);
                    }
                    vetor_solucao[posi1] = -1;
                    if(verifica_marcadores(dados_cidades) == 1){
                        sair = 1;
                        if(get_menor_distancia(solucao) == 0){
                            set_menor_distancia(solucao, dist1);
                            for(j = 0; j < (3*N); j++){
                                aux1 = vetor_solucao[j];
                                solucao->melhor_solucao[j] = aux1;
                                if(aux1 == -1){
                                    break;
                                }
                            }
                        }
                        else if(dist1 < (get_menor_distancia(solucao))){
                            set_menor_distancia(solucao, 0);
                            set_menor_distancia(solucao, dist1);
                            for(j = 0; j < (3*N); j++){
                                aux1 = vetor_solucao[j];
                                solucao->melhor_solucao[j] = aux1;
                                if(aux1 == -1){
                                    break;
                                }
                            }
                        }
                    }
                }
                if(sair == 1){
                    break;
                }
            }
        }
    }
    free(vetor_solucao);
    free(vetor_aux);
}
int verifica_marcadores(Dados_Cidades *dados_cidades){
    int N = get_N(dados_cidades);
    for(int i = 1; i < N; i++){
        if(get_vetor_Q_marcador(dados_cidades, i) == 0){
            return 0;
        }
    }
    return 1;
}

void imprime_melhor_solucao(Dados_Cidades *dados_cidades, Solucao *solucao){
    printf("\nS=[ ");
    int N = get_N(dados_cidades);
    int aux1, aux2, i;
    aux1 = solucao->melhor_solucao[i];
    printf("\nS=[ ");
    for(i = 0; i < (3*N); i++){
        aux1 = solucao->melhor_solucao[i];
        if(aux1 == -1){
            break;
        }
        aux2 = solucao->melhor_solucao[i+1];
        if(aux1 == 0 && aux2 == 0){
            printf("");
        }
        else{
            printf("%d ", aux1);
        }
    }
    printf("]\n");
}
/*
void melhor_solucao(Dados_Cidades *dados_cidades, Arranjos *arranjos, Solucao *solucao){
    int N = get_N(dados_cidades);
    int arranjos_uteis = get_arranjos_uteis(arranjos);
    int qtd_caminhoes, soma_demanda, capacidade_caminhao;
    soma_demanda = get_soma_demanda(dados_cidades);
    capacidade_caminhao = get_capacidade_caminhao(dados_cidades);
    
    if(soma_demanda % capacidade_caminhao != 0){
    qtd_caminhoes = soma_demanda / capacidade_caminhao + 1;
    }
    else{
    qtd_caminhoes = soma_demanda / capacidade_caminhao;
    }
    int i, j;
    int *indice;
    indice = (int*)malloc(arranjos_uteis * sizeof(int));
    int *possivel_solucao;
    possivel_solucao = (int*)malloc((qtd_caminhoes*(N+2)) * sizeof(int));
    int *numeracao_arranjos;
    numeracao_arranjos = (int*)malloc(arranjos_uteis * sizeof(int));
    for(i = 0; i < arranjos_uteis; i++){
        numeracao_arranjos[i] = i;
    }
    int aux1, aux2,l,c;
    int *num ;
    num = (int *)calloc(qtd_caminhoes+1, sizeof(int));
    while ( num[qtd_caminhoes] == 0 ) {
        for(i=0; i < arranjos_uteis; i++) { 
            if (verifica_repeticoes_arranjos(num, qtd_caminhoes) ) {
                for(j=0; j < qtd_caminhoes; j++) {
                    indice[j] = numeracao_arranjos[num[j]];
                }
                //------------------------------------------------------------------//
                
                int count = 0;
                int distancia = 0;
                int continuar = 1;
                for(l = 0; l < N; l++){
                    set_vetor_Q_marcador(dados_cidades, l, 0);
                }
                possivel_solucao[count] = 0;
                count++;
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
                
                if((continuar == 1) && (verifica_marcadores(dados_cidades) == 1)){
                    if(get_menor_distancia(solucao) == 0){
                        set_menor_distancia(solucao, distancia);
                        for(l = 0; l <= count; l++){
                            solucao->melhor_solucao[l] = possivel_solucao[l];
                        }
                    }
                    if(distancia < get_menor_distancia(solucao)){
                        set_menor_distancia(solucao, distancia);
                        for(l = 0; l <= count; l++){
                            solucao->melhor_solucao[l] = possivel_solucao[l];
                        }
                    }
                }
                
                //------------------------------------------------------------------//
                //printf("\n") ;
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
}
void imprime_melhor_solucao(Dados_Cidades *dados_cidades, Solucao *solucao){
    printf("S=[ ");
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
*/