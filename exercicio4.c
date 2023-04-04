#include <stdio.h>
#include <omp.h>

int main(){

    int x = 5;
    #pragma omp parallel private(x) num_threads(3)
    {
        x++;
        printf("%d\n",x);
    }
    printf("%d", x);

    return 0;
}