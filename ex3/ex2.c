#include <stdio.h>

#define PAR 1
#define IMPAR 0
#define END_SUCCESS 0

int verificaPar(int numero) {
    if (numero % 2 == 0) {
        return PAR;
    } else {
        return IMPAR;
    }
}

int main() {
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    if (verificaPar(num) == PAR) {
        printf("%d é um número par.\n", num);
    } else {
        printf("%d é um número ímpar.\n", num);
    }

    return END_SUCCESS;
}

