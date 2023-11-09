#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double calcular_e(int n) {
    double e = 1.0;
    double termo = 1.0;

    #pragma omp parallel for reduction(*:termo) num_threads(4)
    for (int i = 1; i <= n; i++) {
        termo *= 1.0 / i;
        e += termo;
    }

    return e;
}

int main() {
    int n = 1000000;  // Ajuste o valor de n conforme necessário
    double resultado;
    double inicio, fim;

    inicio = omp_get_wtime();  // Obtemos o tempo de início

    resultado = calcular_e(n);

    fim = omp_get_wtime();  // Obtemos o tempo de fim

    printf("Valor de e: %lf\n", resultado);
    printf("Tempo T: %lf segundos\n", fim - inicio);

    return 0;
}
