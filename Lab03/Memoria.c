#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    pid_t childpid;
    int shm_id;
    int *shrd_var;

    // Cria uma região de memória compartilhada
    shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0660);
    if (shm_id < 0) {
        perror("shmget error");
        exit(1);
    }

    // Conecta-se à região de memória compartilhada
    shrd_var = (int*)shmat(shm_id, NULL, 0);
    if (shrd_var == (int*)-1) {
        perror("shmat error");
        exit(1);
    }

    // Define o valor inicial da variável compartilhada
    *shrd_var = 1;

    // Imprime o valor inicial da variável compartilhada
    printf("Valor inicial da variável compartilhada: %d\n", *shrd_var);

    // Cria o processo filho
    childpid = fork();

    if (childpid < 0) {
        perror("fork error");
        exit(1);
    } else if (childpid == 0) { // Processo filho
        // Realiza a operação de adição (2) na variável compartilhada
        *shrd_var += 2;

        // Imprime o valor após a operação de adição
        printf("Processo filho: Valor após adição: %d\n", *shrd_var);

        // Libera a memória compartilhada
        shmdt(shrd_var);
        exit(0);
    } else { // Processo pai
        // Espera pelo processo filho
        wait(NULL);

        // Realiza a operação de multiplicação (4) na variável compartilhada
        *shrd_var *= 4;

        // Imprime o valor após a operação de multiplicação
        printf("Processo pai: Valor após multiplicação: %d\n", *shrd_var);

        // Libera a memória compartilhada
        shmdt(shrd_var);

        // Remove a região de memória compartilhada
        shmctl(shm_id, IPC_RMID, NULL);
    }

    return 0;
}
