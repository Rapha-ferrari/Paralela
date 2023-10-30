#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

#define MAX_THREADS 8

int m, n, thread_count;
double **A, *x, *y;

void Pth_mat_vect() {
    int i, j;

    #pragma omp parallel for num_threads(thread_count) private(i, j)
    for (i = 0; i < m; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
}

int main(int argc, char *argv[]) {
    // Inicialize m, n, A, x, y, e thread_count aqui
    // ...

    // Inicialize as estruturas de dados e alocação de memória
    // ...

    // Serial version
    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < m; i++) {
        y[i] = 0.0;
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    gettimeofday(&end, NULL);
    double serial_execution_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    printf("Serial execution time: %lf seconds\n", serial_execution_time);

    // Parallel version using OpenMP
    gettimeofday(&start, NULL);

    Pth_mat_vect();

    gettimeofday(&end, NULL);
    double parallel_execution_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    printf("Parallel execution time: %lf seconds\n", parallel_execution_time);

    // Calculate and print speedup
    double speedup = serial_execution_time / parallel_execution_time;
    printf("Speedup: %lf\n", speedup);

    // Liberar memória e finalizar
    // ...

    return 0;
}
