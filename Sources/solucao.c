#include "../Libs/solucao.h"

void cria_vetor_solucao(Solucao *solucao, int M){
    solucao->melhor_solucao = (int*)malloc(M * sizeof(int));
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
    vetor_aux = (int*)malloc((N+2)*sizeof(int));
    int l,c,i,j, distancia, aux1, aux2, posi;
    for(i = 0; i < arranjos_uteis; i++){
        posi = 0;
        distancia = 0;
        for(j = 0; j <= (N + 2); j++){
            aux1 = get_arranjos(arranjos, i, j);
            aux2 = get_arranjos(arranjos, i, j+1);
            vetor_solucao[posi] = aux1;
            //printf("%d ", aux1);
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
                if(l == arranjos_uteis){
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
                        if(get_vetor_Q_marcador(dados_cidades, aux1) == 1){
                            l++;
                            recomeca = 1;
                            break;
                        }
                    }
                }
                else{
                    for(j = 0; j <= (N + 2); j++){
                        aux1 = get_arranjos(arranjos, i, j);
                        vetor_aux[j] = aux1;
                        if(aux1 == -1){
                            break;
                        }
                        if(get_vetor_Q_marcador(dados_cidades, aux1) == 1){
                            l++;
                            recomeca = 1;
                            break;
                        }
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
                                aux2 = vetor_solucao[j+1];
                                solucao->melhor_solucao[j] = aux1;
                                if(aux1 == -1){
                                    break;
                                }
                            }
                        }
                        else if(dist1 < (get_menor_distancia(solucao))){
                            set_menor_distancia(solucao, dist1);
                            for(j = 0; j < (3*N); j++){
                                aux1 = vetor_solucao[j];
                                aux2 = vetor_solucao[j+1];
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
        printf("\n");
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
    //printf("------->return1\n");
    return 1;
}

void imprime_melhor_solucao(Solucao *solucao){
    printf("S=[ ");
    int cid, i = 0;
    while(1){
        cid = solucao->melhor_solucao[i];
        printf("%d ", cid);
        if(cid == -1){
            break;
        } 
    }
    printf("]\n");
}