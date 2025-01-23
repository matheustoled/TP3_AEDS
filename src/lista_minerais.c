#include <stdio.h>
#include <string.h>

#include "headers/lista_minerais.h"

void inicializa_lista(Lista_de_minerais* lista){
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}

void insere_mineral(Lista_de_minerais *lista, char *name){
    Mineral newmine;
    set_mineral(&newmine, name);
    lista->Lminerais[lista->ultimo] = newmine;
    lista->ultimo++;
}

void imprime_lista(Lista_de_minerais* lista){
    //uso de ponteiro para permitir impressão mais fácil dos valores, sem necessidade de switch case
    for (int i = 0; i < lista->ultimo; i++)
    {
        printf("Nome: %s\n", lista->Lminerais[i].Nome);
        printf("Dureza: %.1f\n", lista->Lminerais[i].Dureza);
        printf("Reatividade: %.1f\n", lista->Lminerais[i].Reatividade);
        get_cor(&lista->Lminerais[i]);
        printf("--------------\n");
    }
}

//Tnome é o nome usado para identificar qual Mineral remover. T vem de "target", e homenagem ao Zivianni.
int retira_mineral(Lista_de_minerais* lista, char* Tnome){

    if (lista->ultimo == lista->primeiro)
    {
        printf("A lista não pode conter menos de um elemento. Se quer esvaziá-la, use a operação 'esvaziar_lista'.");
        return 0;
    }
    //for para percorrer a lista linear e remover o mineral
    int found = 0;
    for (int i = 0; i < lista->ultimo; i++)
    {
        if (strcmp(lista->Lminerais[i].Nome, Tnome) == 0)
        {   //for para ajustar os itens à frente do mineral retirado para a posição anterior
            for (int j = i; j < lista->ultimo; j++)
            {
                lista->Lminerais[j] = lista->Lminerais[j+1];
            }
        lista->ultimo--;
        found = 1;
        break;
        }
    if (found == 0)
        {
            printf("O mineral procurado não se encotra na lista.");
        }

    }


}

void limpeza(Lista_de_minerais* lista){
    lista->primeiro = 0;
    lista->ultimo = lista->primeiro;
}