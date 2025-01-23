#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "headers/central_controle.h"

int main() {
    clock_t start, end;
    double cpu_time_used;

    printf("\nQual algoritmo deseja usar parar ordenar o conjunto de rochas, simples(1) ou sofisticado(2)?\n");
    int resposta;
    scanf("%d", &resposta);

    if (resposta == 1){
        
        start = clock(); //início da medição

        //lista encadeada para armazenar as rochas
        Compartimento rochas;
        FListaRochaM(&rochas);
    
        int quantidade_rochas;
    
        //carrega as rochas a partir do arquivo
        quantidade_rochas = LerArquivo("entrada_10000_rochas.txt", &rochas);
        
        RochaMineral *vetor_auxiliar1 = malloc(quantidade_rochas * sizeof(RochaMineral));
        
        vetor_aux(&rochas, vetor_auxiliar1, quantidade_rochas);

        //Métricas de ordenação
        int comparacoes = 0, movimentacoes = 0;

        printf("Metodo de Organizacao: SelectionSort\n");
        selecao(vetor_auxiliar1, quantidade_rochas, &comparacoes, &movimentacoes);

        ImprimeListaRochaM(vetor_auxiliar1, quantidade_rochas);

        free(vetor_auxiliar1);
    
        end = clock(); //fim da medição

        printf("\nMetricas de SelectionSort:\n");
        printf("Comparacoes: %d\n", comparacoes);
        printf("Movimentacoes: %d\n", movimentacoes);

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //tempo em segundos
        printf("\nTempo de execucao: %.3f segundos", cpu_time_used);
        
        return 0;
    } else if (resposta == 2){
        start = clock(); //início da medição

        Compartimento rochas;
        FListaRochaM(&rochas);
    
        int quantidade_rochas;
    
        quantidade_rochas = LerArquivo("entrada_10000_rochas.txt", &rochas);
        
        RochaMineral *vetor_auxiliar2 = malloc(quantidade_rochas * sizeof(RochaMineral));
    
        vetor_aux(&rochas, vetor_auxiliar2, quantidade_rochas);

        //Métricas de ordenação
        int comparacoes = 0, movimentacoes = 0;

        printf("Metodo de Organizacao: ShellSort\n");
        shellsort(vetor_auxiliar2, quantidade_rochas, &comparacoes, &movimentacoes);
        
        ImprimeListaRochaM(vetor_auxiliar2, quantidade_rochas);

        free(vetor_auxiliar2);
    
        end = clock();

        printf("\nMetricas de ShellSort:\n");
        printf("Comparacoes: %d\n", comparacoes);
        printf("Movimentacoes: %d\n", movimentacoes);
    
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //tempo em segundos
        printf("\nTempo de execucao: %.3f segundos", cpu_time_used);

        return 0;
    }
}