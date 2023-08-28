#include <stdio.h>
#include <string.h>

void insertCharacterAtIndex(char *str, int index, char character) {
    int length = strlen(str);

    if (index < 0 || index > length) {
        // Verifica se a posição é válida
        printf("Posição inválida.\n");
        return;
    }

    // Move os caracteres uma posição para frente para abrir espaço para o novo caractere
    for (int i = length; i > index; i--) {
        str[i] = str[i - 1];
    }
    str[index] = character;  // Insere o novo caractere na posição desejada
}

int main() {
    char inputString[100];
    char character;
    int index;

    printf("Digite uma string: ");
    scanf("%s", inputString);

    printf("Digite o caractere a ser inserido: ");
    scanf(" %c", &character);  // Note o espaço antes de %c para consumir a quebra de linha

    printf("Digite a posição de inserção: ");
    scanf("%d", &index);

    insertCharacterAtIndex(inputString, index, character);

    printf("String após a inserção do caractere: %s\n", inputString);

    return 0;
}
