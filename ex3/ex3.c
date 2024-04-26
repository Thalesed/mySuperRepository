#include <stdio.h>

#define END_SUCCESS 0

double potencia(double base, int expoente) {
    double resultado = 1.0;

    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int main() {
    double base;
    int expoente;

    printf("Digite a base: ");
    scanf("%lf", &base);

    printf("Digite o expoente (inteiro maior ou igual a 1): ");
    scanf("%d", &expoente);

    double resultado = potencia(base, expoente);
    printf("%lf elevado a %d é igual a %lf\n", base, expoente, resultado);

    return END_SUCCESS;
}

