#include <stdio.h>
#include <string.h>

int findCharacterPosition(const char *str, char target) {
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == target) {
            return i;  // Retorna a primeira ocorrência do caractere
        }
    }

    return -1;  // Retorna -1 se o caractere não for encontrado na string
}

int main() {
    char inputString[100];
    char targetChar;

    printf("Digite uma string: ");
    scanf("%s", inputString);

    printf("Digite o caractere a ser procurado: ");
    scanf(" %c", &targetChar);  // Note o espaço antes de %c para consumir a quebra de linha

    int position = findCharacterPosition(inputString, targetChar);

    if (position != -1) {
        printf("O caractere '%c' foi encontrado na posição %d da string.\n", targetChar, position);
    } else {
        printf("O caractere '%c' não foi encontrado na string.\n", targetChar);
    }

    return 0;
}
