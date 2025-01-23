#ifndef ROCHA_MINERAL_H
#define ROCHA_MINERAL_H

#include "Lista_minerais.h"

typedef struct loc {
    float latitude;
    float longitude;
} loc;

typedef enum Categoria {
    Ferrom = 0,
    Solaris = 1,
    Aquaferro = 2,
    Terrolis = 3,
    Terrasol = 4,
    Aquaterra = 5,
    Calquer = 6,
    Solarisfer = 7,
    Terralis = 8,
    Aquacalis = 9,
    Indefinida = 10
} Categoria;

typedef struct RochaMineral {
    loc localizacao;
    Categoria categoria;
    float peso;
    Lista_de_minerais lista;
} RochaMineral;

//inicializa rocha
void inicializar_rocha_mineral(RochaMineral *nova_rocha, float novo_peso);

//get
float get_peso(RochaMineral *nova_rocha);

//set
void set_peso(RochaMineral *nova_rocha, float novo_peso);

//preenche_dados_rochas
void preencher_rocha_mineral(FILE *arquivo, int i, RochaMineral *nova_rocha);
//imprime rocha mineral
void imprimir_rocha_mineral(RochaMineral *nova_rocha);

void classificar_rocha(RochaMineral *nova_rocha, Lista_de_minerais *nova_lista, int tamanho);

#endif