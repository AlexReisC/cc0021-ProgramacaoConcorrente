#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500000000

float *gerar_vetor(int n);

void mostrar_vetor(float *v,int tamanho);

int main() {
    /*
    INICIO
    */
    time_t t;
    srand(time(NULL));
    float *vetor = NULL;
    vetor = gerar_vetor(MAX);

    float n = 0.3578;
    int i, achou;

    double inicio = omp_get_wtime();
    #pragma omp parallel num_threads(4)
    {
        #pragma omp for
            for (i = 0; i < MAX; i++){
                if(vetor[i] == n){
                    printf("Achou!\n");
                    achou = 1;
                }
            }
    }
    double fim = omp_get_wtime();

    double tempo = fim - inicio;

    if(achou != 1){
        printf("Não achou!\n");
    }
    printf("Tempo em segundos: %f", tempo);

    /*
    FIM
    */
    return 0;
}

float *gerar_vetor(int n) {
    float *vetor;
    int i;
    vetor = (float *)malloc(sizeof(float) * n);
    for (i=0;i<n;i++) {
        float num = (rand() / (float)RAND_MAX);
        vetor[i] = num;
    }
    return vetor;
}

void mostrar_vetor(float *v,int tamanho) {
    int i;
    for (i=0;i<tamanho;i++) {
        printf("[%.5f]",v[i]);
    }
    printf("\n");
}