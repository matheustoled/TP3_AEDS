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
void classificar_rocha(RochaMineral *nova_rocha){

    int Ferrolita = 0, Solarium = 0, Aquavitae = 0, Terranita = 0, Calaris = 0;

    for (int i = 0; i < 3; i++) {
        if (strcmp(nova_rocha.minerais[i], "Ferrolita") == 0){
            Ferrolita += 1;
        }
        else if (strcmp(nova_rocha.minerais[i], "Solarium") == 0) {
            Solarium += 1;
        }
        else if (strcmp(nova_rocha.minerais[i], "Aquavitae") == 0) {
            Aquavitae += 1;
        }
        else if (strcmp(nova_rocha.minerais[i], "Terranita") == 0) {
            Terranita += 1;
        }
        else if (strcmp(nova_rocha.minerais[i], "Calaris") == 0) {
            Calaris += 1;
        }
    }

    if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 0 && Terranita == 0 && Calaris == 0) {
    nova_rocha->categoria = Ferrom;
    }
    else if (Ferrolita == 0 && Solarium == 1 && Aquavitae == 0 && Terranita == 0 && Calaris == 0) {
        nova_rocha->categoria = Solaris;
    }
    else if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 0) {
        nova_rocha->categoria = Aquaferro;
    }
    else if (Ferrolita == 0 && Solarium == 0 && Aquavitae == 0 && Terranita == 1 && Calaris == 1) {
        nova_rocha->categoria = Terrolis;
    }
    else if (Ferrolita == 0 && Solarium == 1 && Aquavitae == 0 && Terranita == 1 && Calaris == 0) {
        nova_rocha->categoria = Terrasol;
    }
    else if (Ferrolita == 0 && Solarium == 0 && Aquavitae == 1 && Terranita == 1 && Calaris == 0) {
        nova_rocha->categoria = Aquaterra;
    }
    else if (Ferrolita == 0 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 1) {
        nova_rocha->categoria = Calquer;
    }
    else if (Ferrolita == 1 && Solarium == 1 && Aquavitae == 0 && Terranita == 0 && Calaris == 0) {
        nova_rocha->categoria = Solarisfer;
    }
    else if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 0 && Terranita == 1 && Calaris == 0) {
        nova_rocha->categoria = Terralis;
    }
    else if (Ferrolita == 1 && Solarium == 0 && Aquavitae == 1 && Terranita == 0 && Calaris == 1) {
        nova_rocha->categoria = Aquacalis;
    }
}
void imprimir_rocha_mineral(RochaMineral *nova_rocha){

    char categoria_imprimir[255];

    switch (nova_rocha->categoria)
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
    printf("\nPeso: %f", nova_rocha->peso);
    printf("\nLocalizacao: %f %f", nova_rocha->localizacao.Latitude, nova_rocha->localizacao.Longitude);
}
