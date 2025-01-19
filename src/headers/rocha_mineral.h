#ifndef ROCHA_MINERAL_H
#define ROCHA_MINERAL_H

typedef struct loc {
    float latitude;
    float longitude;
} loc;

typedef struct RochaMineral {
    loc localizacao;
    float peso;
    char minerais[3][255];
} RochaMineral;

//inicializa rocha
void inicializar_rocha_mineral(RochaMineral *nova_rocha, float novo_peso);

//get
float get_peso(RochaMineral *nova_rocha);
int get_valor(RochaMineral *nova_rocha);

//set
void set_peso(RochaMineral *nova_rocha, float novo_peso);
void set_valor(RochaMineral *nova_rocha, int novo_valor);

//preenche_dados_rochas
void preencher_rocha_mineral(FILE *arquivo, int i, RochaMineral *nova_rocha);
//imprime rocha mineral
void imprimir_rocha_mineral(RochaMineral *nova_rocha);

#endif