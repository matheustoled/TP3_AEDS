#include <stdio.h>
#include <stdlib.h>

#include "headers/compartimento.h"
#include "headers/rocha_mineral.h"

void FListaRochaM(Compartimento *LRM){
    LRM->pPrimeiro = (CelulaC*)malloc(sizeof(CelulaC));
    LRM->pUltimo = LRM->pPrimeiro;
    LRM->pPrimeiro->pProx = NULL;
}

int LEhVaziaRochaM(Compartimento *LRM){
    return(LRM->pPrimeiro == LRM->pUltimo);
}

double PesoAtual(Compartimento *LRM){
    double peso = 0;
    if (LEhVaziaRochaM(LRM))
    {
        return 0;
    }

    CelulaC *pAux;
    
    for(pAux = LRM->pPrimeiro->pProx; pAux != NULL; pAux = pAux->pProx)
    {
        peso += (pAux->rocha.peso);
    }
    return peso;
}

int InsereRochaM(Compartimento *LRM, RochaMineral *rocha_validas) {
    // Insere a rocha no compartimento
    LRM->pUltimo->pProx = (CelulaC*) malloc(sizeof(CelulaC));
    LRM->pUltimo = LRM->pUltimo->pProx;
    LRM->pUltimo->rocha = *rocha_validas;
    LRM->pUltimo->pProx = NULL;

    return 1;
}

void ImprimeListaRochaM(Compartimento *LRM){
    CelulaC *pAuxI;
    pAuxI = LRM->pPrimeiro->pProx;
    while (pAuxI != NULL)
    {
        char categoria_imprimir[255];

    switch (pAuxI->rocha.categoria)
    {
    case Ferrom:
        strcpy(categoria_imprimir, "Ferrom");
        break;
    case Solaris:
        strcpy(categoria_imprimir, "Solaris");
        break;
    case Aquaferro:
        strcpy(categoria_imprimir, "Aquaferro");
        break;
    case Terrolis:
        strcpy(categoria_imprimir, "Terrolis");
        break;
    case Terrasol:
        strcpy(categoria_imprimir, "Terrasol");
        break;
    case Aquaterra:
        strcpy(categoria_imprimir, "Aquaterra");
        break;
    case Calquer:
        strcpy(categoria_imprimir, "Calquer");
        break;
    case Solarisfer:
        strcpy(categoria_imprimir, "Solarisfer");
        break;
    case Terralis:
        strcpy(categoria_imprimir, "Terralis");
        break;
    case Aquacalis:
        strcpy(categoria_imprimir, "Aquacalis");
        break;
    default: strcpy(categoria_imprimir, "Erro");
        break;
    }
    printf("\nCategoria: %s", categoria_imprimir);
    printf("\nPeso: %f", pAuxI->rocha.peso);
        printf("\n");
        pAuxI = pAuxI->pProx;
    }
}

void ImprimePesosListaRochaM(Compartimento *LRM){
    CelulaC *pAuxI;
    pAuxI = LRM->pPrimeiro->pProx;
    printf("Lista de pesos inseridos:\n");
    while (pAuxI != NULL)
    {
        printf("%.2f ", pAuxI->rocha.peso);
        pAuxI = pAuxI->pProx;
    }
    printf("\n");
}

int vetor_aux(Compartimento *rochas, RochaMineral *novo_vetor, int qnt_rochas){
    CelulaC *pAux = rochas->pPrimeiro->pProx;
    for(int i = 0; i < qnt_rochas; i++){
        novo_vetor[i] = pAux->rocha;
        pAux = pAux->pProx;
    }
    return 0;
}

void selecao(RochaMineral *v, int n){
    int i, j, min;
    float aux;
    for (i = 0; i < n - 1; i++){
        min = i;
        for (j = i + 1; j < n; j++){
            if (v[j].peso < v[min].peso){
                min = j;
            }
        }
        aux = v[min].peso;
        v[min].peso = v[i].peso;
        v[i].peso = aux;
    }
}

void shellsort(RochaMineral *v, int n){
    int i, j;
    int h = 1;
    float aux;
    do h = h * 3 + 1; 
    while (h < n);
    do{
        h = h/3;
        for (i = h; i < n; i++){
            aux = v[i].peso;
            j = i;
            while (v[j - h].peso > aux){
                v[j].peso = v[j - h].peso;
                j -= h;
                if (j < h){
                    break;
                }
            }
            v[j].peso = aux;
        }
    } while (h != 1);
}
