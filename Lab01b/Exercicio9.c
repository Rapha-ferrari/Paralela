#include <stdio.h>
#include <stdlib.h>

void replaceNegativesWithAbsolute(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < 0) {
                matrix[i][j] = abs(matrix[i][j]);
            }
        }
    }
}

int main() {
    int rows, cols;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &rows);

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    replaceNegativesWithAbsolute(rows, cols, matrix);

    printf("Matriz após substituir os negativos pelo módulo:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
