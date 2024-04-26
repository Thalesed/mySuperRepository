#include <stdio.h>

#define END_SUCCESS 0

float calcularExpressao(float x, float y, float z) {
    return (x * x) + y + z;
}

int main() {
    float num1, num2, num3;

    printf("Digite três valores float (x, y, z): ");
    scanf("%f %f %f", &num1, &num2, &num3);

    float resultado = calcularExpressao(num1, num2, num3);

    printf("O resultado da expressão é: %.2f\n", resultado);

    return END_SUCCESS;
}

