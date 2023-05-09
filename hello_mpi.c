#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

float *gerar_vetor(int n);

int main()
{

    

    // Iniciando MPI
    MPI_Init(NULL, NULL);
    int nprocs;
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    time_t t;
    srand(time(NULL) * rank);

    /*
    INICIO
    */
    int numero;
    if (rank == 0){
        numero = 100;
        MPI_SEND(&numero,1,MPI_INT,1,0,MPI_COMM_WORLD);
    }else if(rank == 1){
        MPI_RECV(&numero,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("valor recebido; %d\n", numero);
    } else{
        printf("Não recebeu nada (%d)\n", rank);
    }
    /*
    FIM
    */

    MPI_Finalize();
    return 0;
}

float *gerar_vetor(int n)
{
    float *vetor;
    int i;
    vetor = (float *)malloc(sizeof(float) * n);
    for (i = 0; i < n; i++)
    {
        float num = (rand() / (float)RAND_MAX);
        vetor[i] = num;
    }
    return vetor;
}