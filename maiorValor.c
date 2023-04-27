#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000000

float *geraVetor(int tam);

int main(){
    time_t t;
    srand(time(NULL));
    float *vet = NULL;
    vet = geraVetor(MAX);

    int i, x;
    int maior = vet[0];
    int maiores[4];
    int indices[4];

    #pragma omp parallel num_threads(4)
    {
        #pragma omp for
        for(i = 0; i < MAX; i++){
            if(vet[i] > maior){
                maior = vet[i];
            }
        }
        maiores[omp_get_thread_num()] = maior;
    }

    for(i = 0; i<4; i++){
        printf("Maior da thread %d: %d\n",i, maiores[i]);
    }
    
    return 0;
}

float *geraVetor(int tam){
    float *vetor;
    vetor = (float*)malloc(sizeof(float)*tam);
    for(int i = 0; i < tam; i++){
        float num = (rand() / (float)RAND_MAX)*100;
        vetor[i] = num;
    }
    return vetor;
}