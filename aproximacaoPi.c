#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(){
    int num_steps = 100000000;
    double step;
    int i;
    double x, pi, sum = 0.0;

    step = 1.0/(double)num_steps;

    // INICIO DO SEQUENCIAL
    double inicio_S = omp_get_wtime();
    for (i = 0; i < num_steps; i++)
    {
        x = (i+0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }
    double fim_S = omp_get_wtime();

    double tempo_S = fim_S - inicio_S;
    pi = step*sum;

    printf("Pi sequencial: %f", pi);
    printf("\nTempo sequencial: %f", tempo_S);
    // FIM DO SEQUENCIAL


    // INICIO DO PARALELO
    double inicio_P = omp_get_wtime();
    sum = 0.0;   
    pi = 0.0;
    #pragma omp parallel private(x) num_threads(3)
    {
        #pragma omp for reduction(+:sum)
        for (i = 0; i < num_steps; i++)
        {
            x = (i+0.5)*step;
            sum = sum + 4.0/(1.0+x*x);
        }   
    }
    double fim_P = omp_get_wtime();

    double tempo_P = fim_P - inicio_P;
    pi = step*sum;

    printf("\nPi paralelo: %f", pi);
    printf("\nTempo paralelo: %f", tempo_P);
    // FIM DO PARALELO

    double speedup = tempo_S / tempo_P;
    printf("\nSpeedup: %f", speedup);
    printf("\nEficiencia: %f", speedup/3.0);

    return 0;
}