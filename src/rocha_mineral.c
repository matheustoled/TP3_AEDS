#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/rocha_mineral.h"

// Inicializar nova rocha
void inicializar_rocha_mineral(RochaMineral *nova_rocha, float novo_peso){
    set_peso(nova_rocha, novo_peso);
}

//gets
float get_peso(RochaMineral *nova_rocha){
    return(nova_rocha->peso);
}

//sets
void set_peso(RochaMineral *nova_rocha, float novo_peso){
    nova_rocha->peso = novo_peso;
}

void preencher_rocha_mineral(FILE *arquivo, int i, RochaMineral *nova_rocha) {
    char entrada[255]; //buffer
    if (fgets(entrada, sizeof(entrada), arquivo) == NULL) {
        printf("Erro ao ler linha do arquivo.\n");
        return;
    }

    char *token = strtok(entrada, " \n");
    nova_rocha[i].localizacao.latitude = atof(token);

    token = strtok(NULL, " \n");
    nova_rocha[i].localizacao.longitude = atof(token);

    token = strtok(NULL, " \n");
    nova_rocha[i].peso = atof(token);

    int j = 0;
    while ((token = strtok(NULL, " \n")) != NULL) {
        if (j < 3) {
            strncpy(nova_rocha[i].minerais[j], token, sizeof(nova_rocha[i].minerais[j]) - 1);
            nova_rocha[i].minerais[j][sizeof(nova_rocha[i].minerais[j]) - 1] = '\0';
        }
        j++;
    }
}

void imprimir_rocha_mineral(RochaMineral *nova_rocha){

    char categoria_imprimir[255];
    int i = 0;

    printf("Peso: %.2f", nova_rocha->localizacao.latitude);
    printf("\nPeso: %.2f", nova_rocha->localizacao.longitude);
    printf("\nPeso: %.2f", nova_rocha->peso);
    while(nova_rocha->minerais != NULL){
        printf("\nPeso: %.2s", nova_rocha->minerais[i]);
        i++;
    }
}