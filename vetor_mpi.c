#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define MAX 1000

int main(){
    MPI_Init(NULL, NULL);
    int nprocs;
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    float *vet = NULL;

    if(rank == 0){
        vet = geraVetor(MAX);
        MPI_Bcast(vet, MAX, MPI_FLOAT, 0, MPI_COMM_WORLD);
        printf();
    } else{
        v = (float*)malloc(sizeof(float)*MAX);
        if(rank == 1){
            for (int i = 0; i < MAX; i++){
                
            }
            
        }
    }

    MPI_Finalize();
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