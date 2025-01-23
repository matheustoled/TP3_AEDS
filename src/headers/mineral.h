#ifndef MINERAL_H
#define MINERAL_H
#define TMAX 100

//cores dos minerais
typedef enum CORM{
    ACINZENTADO = 1,
    AMARELO = 2,
    AZULADO = 3,
    MARROM = 4,
    VERMELHO = 5
} CORM;
//TAD Mineral
typedef struct{
    char Nome[TMAX];
    float Dureza;
    float Reatividade;
    CORM Cor;
} Mineral;

void inicializar_mineral(Mineral* mine, char* Nome, double Dureza, double Reatividade, CORM Cor);

//uso do switch aqui para preencher por completo o TAD Mineral com o input apenas do valor para nome.

void set_mineral(Mineral* mine, char* nome1);

//função para  pedir ao usuário o número que corresponde ao mineral encontrado.
void set_nome(Mineral *mine, char *nome);

//função para imprimir o nome.
char* get_nome(Mineral* mine);

//função para imprimir dados numéricos.
double get_num_data(Mineral* mine);

//função para imprimir a cor do mineral.

void get_cor(Mineral* mine);
//agora imprimir os valores do TAD através do uso de múltiplas funções.

void imprimir_mineral(Mineral* mine);

#endif