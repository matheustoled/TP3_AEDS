#include <stdio.h>
#include <stdlib.h>

#include "headers/central_controle.h"

//funcao para ler arquivo
int LerArquivo(char *nome_arquivo, Compartimento *rochas) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
        return 0;
    }

    int quantidade;
    fscanf(arquivo, "%d\n", &quantidade); // Lê a quantidade de rochas

    for (int i = 0; i < quantidade; i++) {
        RochaMineral nova_rocha;
        preencher_rocha_mineral(arquivo, i, &nova_rocha); // Lê os dados da rocha
        
        // Adiciona a rocha à lista
        InsereRochaM(rochas, &nova_rocha);
        
    }

    fclose(arquivo);
    return quantidade;
}