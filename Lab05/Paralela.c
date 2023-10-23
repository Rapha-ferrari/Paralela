#include <stdio.h>
#include <math.h>
#include <omp.h>

double f(double x) {
    return exp(x);
}

double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        double local_sum = f(x);
        #pragma omp critical
        sum += local_sum;
    }

    return h * sum;
}

int main() {
    double a, b;
    int n;

    printf("Digite o limite inferior (a): ");
    scanf("%lf", &a);
    printf("Digite o limite superior (b): ");
    scanf("%lf", &b);
    printf("Digite o número de subintervalos (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O número de subintervalos deve ser positivo.\n");
    } else {
        double result = trapezoidal(a, b, n);
        printf("Aproximação da integral: %lf\n", result);
    }

    return 0;
}
