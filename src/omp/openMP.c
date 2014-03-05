#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

// gcc openMP.c -fopenmp

int
main() {
    #pragma omp parallel
    printf("Hello, World\n");
    return 0;
    
}
