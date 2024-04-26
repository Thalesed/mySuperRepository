#include <stdio.h>

#define END_SUCCESS 0

int main() {
    int numero;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    // Verifica se o número é múltiplo de 5
    if (numero % 5 == 0) {
        printf("%d é múltiplo de 5.\n", numero);
    } else {
        printf("%d não é múltiplo de 5.\n", numero);
    }

    return END_SUCCESS;
}

