#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/mineral.h"

//inicializa o TAD e permite que o usuário insira os dados como quiser.

void inicializar_mineral(Mineral* mine, char* Nome, double Dureza, double Reatividade, CORM Cor){
    if ((strcmp(Nome, "Ferrolita") != 0 && strcmp(Nome, "Calaris") != 0 &&
         strcmp(Nome, "Solarium") != 0 && strcmp(Nome, "Aquavitae") != 0 &&
         strcmp(Nome, "Terranita") != 0) ||
        (Cor < ACINZENTADO || Cor > VERMELHO)) {
        printf("O Nome e cor do mineral devem ser representados de acordo com os dados a seguir:\n");
        printf("Nomes: FERROLITA, SOLARIUM, AQUAVITAE, TERRANITA, CALARIS\n");
        printf("Cores: ACINZENTADO, AMARELO, AZULADO, MARROM, VERMELHO\n");
        return;
    }
    strncpy(mine->Nome, Nome, TMAX - 1);
    mine->Dureza = Dureza;
    mine->Reatividade = Reatividade;
    mine->Cor = Cor;
}

//uso do switch aqui para preencher por completo o TAD Mineral com o input apenas do valor para nome.

void set_mineral(Mineral* mine, char* nome1){
    set_nome(mine,nome1);
    if (strcmp(nome1, "Ferrolita") == 0)
    {
        strcpy(mine->Nome, "Ferrolita");
        mine->Dureza = 0.5;
        mine->Reatividade = 0.7;
        mine->Cor = ACINZENTADO;
    }
    else if (strcmp(nome1, "Solarium") == 0)
    {
        strcpy(mine->Nome, "Solarium");
        mine->Dureza = 0.9;
        mine->Reatividade = 0.2;
        mine->Cor = AMARELO;
    }
    else if (strcmp(nome1, "Aquavitae") == 0)
    {
        strcpy(mine->Nome, "Aquavitae");
        mine->Dureza = 0.5;
        mine->Reatividade = 0.8;
        mine->Cor = AZULADO;
    }
    else if (strcmp(nome1, "Terranita") == 0)
    {
        strcpy(mine->Nome, "Terranita");
        mine->Dureza = 0.7;
        mine->Reatividade = 0.6;
        mine->Cor = MARROM;
    }
    else if (strcmp(nome1, "Calaris") == 0)
    {
        strcpy(mine->Nome, "Calaris");
        mine->Dureza = 0.6;
        mine->Reatividade = 0.5;
        mine->Cor = VERMELHO;
    }
    else
    {
        printf("Esse mineral nao existe na amostra.\n");
    }
}

//função para  pedir ao usuário o número que corresponde ao mineral encontrado.
void set_nome(Mineral *mine, char *nome) 
{
    strncpy(mine->Nome, nome, strlen(mine->Nome));
}

//função para imprimir o nome.
char* get_nome(Mineral* mine){
    printf("%s\n", mine->Nome);
}

//função para imprimir dados numéricos.
double get_num_data(Mineral* mine){
    printf("Dureza:%.1f\n", mine->Dureza);
    printf("Reatividade:%.1f\n", mine->Reatividade);
}

//função para imprimir a cor do mineral.

void get_cor(Mineral* mine){
    switch (mine->Cor) {
        case ACINZENTADO:
            printf("Cor: ACINZENTADO\n");
            break;
        case AMARELO:
            printf("Cor: AMARELO\n");
            break;
        case AZULADO:
            printf("Cor: AZULADO\n");
            break;
        case MARROM:
            printf("Cor: MARROM\n");
            break;
        case VERMELHO:
            printf("Cor: VERMELHO\n");
            break;
        default:
            printf("A cor nao corresponde a nenhum mineral da regiao\n");
            break;
    }
}

//agora imprimir os valores do TAD através do uso de múltiplas funções.

void imprimir_mineral(Mineral* mine){
    get_nome(mine);
    get_num_data(mine);
    get_cor(mine);
}