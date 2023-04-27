#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int main(){
    int vet[MAX];
    int i, x;
    int somatorio = 0;
    double media = 0.0;

    srand(time(NULL));

    for (i = 0; i < MAX; i++)
    {
        vet[i] = rand();
    }

    #pragma omp parallel firstprivate(somatorio) num_threads(4)
    {
        #pragma omp for
        for (i = 0; i < MAX; i++)
        {
            somatorio = somatorio + (vet[i]/MAX);
        }

    }

    return 0;
}