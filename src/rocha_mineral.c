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
    int tamanho = 0;
    Lista_de_minerais nova_lista;
    inicializa_lista(&nova_lista);
    char entrada[255]; //buffer
    if (fgets(entrada, 255, arquivo) == NULL) {
        printf("Erro ao ler linha do arquivo.\n");
    }
    
    size_t len = strlen(entrada);
    if (len > 0 && entrada[len - 1] == '\n') {
        entrada[len - 1] = '\0';
    }

    char *token = strtok(entrada, " ");
    nova_rocha->localizacao.latitude = atof(token);

    token = strtok(NULL, " ");
    nova_rocha->localizacao.longitude = atof(token);

    token = strtok(NULL, " ");
    nova_rocha->peso = atof(token);

    // Lê os minerais (assumindo até 3 minerais)
    char *mineral1 = strtok(NULL, " ");
    char *mineral2 = strtok(NULL, " ");
    char *mineral3 = strtok(NULL, " ");

    // Verifica se os minerais foram lidos corretamente
    if (mineral1 != NULL) {
        insere_mineral(&nova_lista, mineral1);
        tamanho++;
    }
    if (mineral2 != NULL) {
        insere_mineral(&nova_lista, mineral2);
        tamanho++;
    }
    if (mineral3 != NULL) {
        insere_mineral(&nova_lista, mineral3);
        tamanho++;
    }

    nova_rocha->lista = nova_lista;

    classificar_rocha(nova_rocha, &nova_lista, tamanho);
}
void classificar_rocha(RochaMineral *nova_rocha, Lista_de_minerais *nova_lista, int tamanho){
    
    int Ferrolita = 0, Solarium = 0, Aquavitae = 0, Terranita = 0, Calaris = 0;
    
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(nova_lista->Lminerais[i].Nome, "Ferrolita") == 0){
            Ferrolita += 1;
        }
        else if (strcmp(nova_lista->Lminerais[i].Nome, "Solarium") == 0) {
            Solarium += 1;
        }
        else if (strcmp(nova_lista->Lminerais[i].Nome, "Aquavitae") == 0) {
            Aquavitae += 1;
        }
        else if (strcmp(nova_lista->Lminerais[i].Nome, "Terranita") == 0) {
            Terranita += 1;
        }
        else if (strcmp(nova_lista->Lminerais[i].Nome, "Calaris") == 0) {
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
    case Indefinida:
        strcpy(categoria_imprimir, "Indefinida");
        break;
    default: strcpy(categoria_imprimir, "Erro");
        break;
    }
    printf("\nCategoria: %s", categoria_imprimir);
    printf("\nPeso: %f", nova_rocha->peso);
    printf("\nLocalizacao: %f %f", nova_rocha->localizacao.latitude, nova_rocha->localizacao.longitude);
}
