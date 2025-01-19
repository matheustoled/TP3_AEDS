#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "headers/central_controle.h"

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock(); //início da medição

    //lista encadeada para armazenar as rochas
    Compartimento rochas;
    FListaRochaM(&rochas);

    int quantidade_rochas;

    //carrega as rochas a partir do arquivo
    quantidade_rochas = LerArquivo("entrada_teste.txt", &rochas);
    
    RochaMineral *vetor_auxiliar = malloc(quantidade_rochas * sizeof(RochaMineral));

    vetor_aux(&rochas, vetor_auxiliar, quantidade_rochas);

    ImprimePesosListaRochaM(&rochas);

    printf("Metodo de Organizacao: SelectionSort\n");
    selecao(vetor_auxiliar, quantidade_rochas);
    for(int i = 0; i < quantidade_rochas; i++){
        printf("%.2f ", vetor_auxiliar[i].peso);
    }

    // printf("Metodo de Organizacao: ShellSort\n");
    // shellsort(vetor_auxiliar, quantidade_rochas);
    // for(int i = 0; i < quantidade_rochas; i++){
    //     printf("%f", vetor_auxiliar[i].peso);
    // }

    free(vetor_auxiliar);

    end = clock(); //fim da medição

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //tempo em segundos
    printf("Tempo de execucao: %.3f segundos\n", cpu_time_used);
    return 0;
}