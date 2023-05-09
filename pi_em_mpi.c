#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(){
    MPI_Init(NULL, NULL);
    int n_procs;
    MPI_Comm_size(MPI_COMM_WORLD, &n_procs);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int num_steps = 1000000;
    double step;
    int i; double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps;

    for (i = rank; i < num_steps; i+= n_procs)
    {
        x = (i + 0.5) * step;
        sum = sum + 4.0 / (1.0 + x*x);
    }
    
    pi = step*sum;
    double pi_total;
    
    MPI_Reduce(&pi, &pi_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0){
        printf("%.10f\n", pi_total);
    }

    MPI_Finalize();
    return 0;
}