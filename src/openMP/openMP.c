#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

int
main() {
    #pragma omp parallel
    printf("Hello, World\n");
    return 0;
    
}
