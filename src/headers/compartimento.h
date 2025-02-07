#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H
#include "rocha_mineral.h"

typedef struct CelulaC
{
    RochaMineral rocha;
    struct CelulaC *pProx;
}CelulaC;

typedef struct Compartimento
{
    CelulaC *pPrimeiro;
    CelulaC *pUltimo;
}Compartimento;

void FListaRochaM(Compartimento *LRM);
int LEhVaziaRochaM(Compartimento *LRM);
double PesoAtual(Compartimento *LRM);
int InsereRochaM(Compartimento *LRM, RochaMineral *rocha_validas);
void ImprimeListaRochaM(Compartimento *LRM);
void ImprimePesosListaRochaM(Compartimento *LRM);

// Ordenação

int vetor_aux(Compartimento *rochas, RochaMineral *novo_vetor, int qnt_rochas);
void selecao(RochaMineral *v, int n);
void shellsort(RochaMineral *v, int n);
 
#endif //COMPARTIMENTO_H