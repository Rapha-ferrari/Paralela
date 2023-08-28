#include <stdio.h>
#include <string.h>

void removeCharacterAtIndex(char *str, int index) {
    int length = strlen(str);

    if (index < 0 || index >= length) {
        // Verifica se a posição é válida
        printf("Posição inválida.\n");
        return;
    }

    // Move os caracteres uma posição para trás para "remover" o caractere
    for (int i = index; i < length - 1; i++) {
        str[i] = str[i + 1];
    }
    str[length - 1] = '\0';  // Define o novo final da string
}

int main() {
    char inputString[100];
    int index;

    printf("Digite uma string: ");
    scanf("%s", inputString);

    printf("Digite a posição do caractere a ser removido: ");
    scanf("%d", &index);

    removeCharacterAtIndex(inputString, index);

    printf("String após a remoção do caractere: %s\n", inputString);

    return 0;
}
