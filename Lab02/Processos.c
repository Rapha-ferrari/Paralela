#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num, j, i = 1;
    printf("Enter the number: ");
    scanf("%d", &num);
    j = num;
    
    // Criação de um processo filho
    pid_t pid = fork();

    if (pid == 0) {
        // Processo filho calcula a metade inferior do fatorial
        for (; j > num / 2; j--) {
            i = i * j;
        }
        exit(0);  // Saída do processo filho
    } else if (pid > 0) {
        // Processo pai calcula a metade superior do fatorial
        for (; j > 1; j--) {
            i = i * j;
        }
        // Aguarda o processo filho terminar
        wait(NULL);

        printf("The factorial of %d is %d\n", num, i);
    } else {
        // Erro na criação do processo filho
        perror("fork");
        return 1;
    }

    return 0;
}
