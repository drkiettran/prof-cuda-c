#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define BILLION  1000000000.0;

/*
 * This example demonstrates a simple vector sum on the host. sumArraysOnHost
 * sequentially iterates through vector elements on the host.
 */

void sumArraysOnHost(float *A, float *B, float *C, const int N)
{
    for (int idx = 0; idx < N; idx++)
    {
        C[idx] = A[idx] + B[idx];
    }

}

void initialData(float *ip, int size)
{
    // generate different seed for random number
    time_t t;
    srand((unsigned) time(&t));

    for (int i = 0; i < size; i++)
    {
        ip[i] = (float)(rand() & 0xFF) / 10.0f;
    }

    return;
}

/*
 * Print out the three arrays A, B, and C. 
 */
void print_arrays(float *a, float *b, float *c, int size) {
    printf("\n>>>>\n");
    for (int i = 0; i < size; i++) {
        printf("%4d. %6.3f + %6.3f = %6.3f\n", i, a[i], b[i], c[i]);
    }
    printf("\n<<<<\n");
}

int main(int argc, char **argv)
{
    int nElem = 1024;
    if (argc > 1) {
        nElem = atoi(argv[1]);
    }
    
    printf("Number of elements: %d\n", nElem);
    size_t nBytes = nElem * sizeof(float);

    float *h_A, *h_B, *h_C;
    h_A = (float *)malloc(nBytes);
    h_B = (float *)malloc(nBytes);
    h_C = (float *)malloc(nBytes);

    initialData(h_A, nElem);
    initialData(h_B, nElem);
    
    struct timespec start;
    if (clock_gettime(CLOCK_REALTIME, &start) == -1) {
        printf("clock_gettime error!\n");
        exit(EXIT_FAILURE);
    }

    sumArraysOnHost(h_A, h_B, h_C, nElem);

    struct timespec stop;
    if (clock_gettime(CLOCK_REALTIME, &stop) == -1) {
        printf("clock_gettime error!\n");
        exit(EXIT_FAILURE);
    }

    double elapsed = (stop.tv_sec - start.tv_sec) + 
                     ( stop.tv_nsec - start.tv_nsec) / BILLION;

    printf("Matrix addition on Host elapsed %lf seconds.\n", elapsed);

    // print_arrays(h_A, h_B, h_C, nElem);

    free(h_A);
    free(h_B);
    free(h_C);

    return(0);
}
