#include <stdio.h>
#include <omp.h>

#define MAX 10000000

int *geraVetor(int tam){
    int *vetor = (float*)malloc(sizeof(int)*tam);
    for(int i = 0; i < tam; i++){
        int num = (rand() / RAND_MAX)*100;
        vetor[i] = num;
    }
    return vetor;
}

int main(){
    int vet[];
    vet = geraVetor(MAX);
    int i, x;
    int maior = vet[0];
    int maiores[4];

    #pragma omp parallel firstprivate(maior) num_threads(4)
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
        printf("Maior: %d", maiores[i]);
    }
    
    return 0;
}