#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define MAX_THREADS 8

int m, n, thread_count;
double **A, *x, *y;

void *Pth_mat_vect(void *rank) {
    long my_rank = (long)rank;
    int i, j;
    int local_m = m / thread_count;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

    for (i = my_first_row; i <= my_last_row; i++) {
        y[i] = 0.0;
        for (j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    // Inicialize m, n, A, x, y, e thread_count aqui

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

    // Parallel version using pthreads
    pthread_t *thread_handles;
    thread_handles = (pthread_t *)malloc(thread_count * sizeof(pthread_t));

    gettimeofday(&start, NULL);

    for (long thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void *)thread);
    }

    for (long thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    free(thread_handles);

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
