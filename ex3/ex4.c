#include <stdio.h>
#include <math.h>

#define END_SUCCESS 0

double soma(double num1, double num2) {
    return num1 + num2;
}

double produto_quadrado(double num1, double num2) {
    return num1 * pow(num2, 2);
}

double quadrado(double num) {
    return pow(num, 2);
}

double seno_diferenca(double num1, double num2) {
    return sin(num1 - num2);
}

int main(int argc, char ** argv) {
    double num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%lf", &num1);

    printf("Digite o segundo número: ");
    scanf("%lf", &num2);

    printf("Soma dos números: %.2lf\n", soma(num1, num2));
    printf("Produto do primeiro pelo quadrado do segundo: %.2lf\n", produto_quadrado(num1, num2));
    printf("Quadrado do primeiro número: %.2lf\n", quadrado(num1));
    printf("Seno da diferença do primeiro número pelo segundo: %.2lf\n", seno_diferenca(num1, num2));

    return END_SUCCESS;
}

