#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500000000

// Funcao que gera um vetor de tamanho MAX com elementos aleatorios
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
    double soma1, soma2;

    // INICIO DO SEQUENCIAL
    double inicio1 = omp_get_wtime();
    for (i = 0; i < MAX; i++){
            soma1 = soma1 + vetor[i];
    }
    double media1 = soma1 / MAX;
    double fim1 = omp_get_wtime();
    
    double tempo_S = fim1 - inicio1;
    printf("Media sequencial: %f\nTempo Sequencial: %f", media1, tempo_S);
    //FIM DO SEQUENCIAL

    // INICIO DO PARARELO
    double inicio2 = omp_get_wtime();
    #pragma omp parallel num_threads(4)
    {
        #pragma omp for reduction(+:soma2)
        for (i = 0; i < MAX; i++){
            soma2 = soma2 + vetor[i];
        }
    }
    double media2 = soma2 / MAX;
    double fim2 = omp_get_wtime();
    double tempo_P = fim2 - inicio2;
    
    printf("\nMedia Paralela: %f\nTempo paralelo: %f",media2, tempo_P);
    // FIM DO PARALELO
    
    double speedup = tempo_P / tempo_S;
    printf("\nSpeedup: %f", speedup);
    printf("\nEficiencia: %f", (speedup*0.4));
    
    return 0;
}