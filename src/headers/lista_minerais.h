#ifndef LISTA_MINERAIS_H_
#define LISTA_MINERAIS_H_

#include "mineral.h"

#define PMAX 300000

typedef struct {
    Mineral Lminerais[255];
    int primeiro, ultimo;
} Lista_de_minerais;

//cria a lista vazia
void inicializa_lista(Lista_de_minerais* lista);
//retira um mineral pelo nome
int retira_mineral(Lista_de_minerais* lista, char* Tnome);
//insere um mineral no final da lista
void insere_mineral(Lista_de_minerais* lista, char* name);
//imprime todos os componentes da lista
void imprime_lista(Lista_de_minerais* lista);
//esvazia a lista
void limpeza(Lista_de_minerais* lista);

#endif