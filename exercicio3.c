#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500000000

float *geraVetor(int tam){
    float *vetor;
    vetor = (float*)malloc(sizeof(float)*tam);
    for (int i = 0; i < tam; i++){
        float num = (rand() / (float)RAND_MAX)*100;
        vetor[i] = num;
    }
    return vetor;
}

void mostrarVetor(float *v,int tamanho) {
    int i;
    for (i=0;i<tamanho;i++) {
        printf("[%.5f]",v[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    float *vetor = NULL; 
    vetor = geraVetor(MAX);

    int i;
    double soma;

    double inicio = omp_get_wtime();
    #pragma omp parallel num_threads(4)
    {
        #pragma omp for reduction(+:soma)
        for (i = 0; i < MAX; i++){
            soma = soma + vetor[i];
        }
    }
    double media = soma / MAX;
    double fim = omp_get_wtime();
    double tempo = fim - inicio;
    
    printf("Tempo: %f\nMedia: %f", tempo, media);

    return 0;
}