#include <stdio.h>
#include <omp.h>

int main(){

    // INICIO DO PARALELO
    int num_steps = 100000000;
    double step;
    double x, pi, sum;

    step = 1.0/(double)num_steps;

    double inicio_P = omp_get_wtime();
    pi = 0.0;
    int i;
    #pragma omp parallel num_threads(3)
    {
        double x;
        double sum = 0.0;
  
        #pragma omp for
        for (i = 0; i < num_steps; i++)
        {
            x = (i+0.5)*step;
            sum = sum + 4.0/(1.0+x*x);
        }
        #pragma omp atomic
            pi += sum*step;
    }
    double fim_P = omp_get_wtime();

    double tempo_P = fim_P - inicio_P;

    printf("\nPi com sincronizacao: %f", pi);
    printf("\nTempo: %f", tempo_P);
    // FIM DO PARALELO

    return 0;
}