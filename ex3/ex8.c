#include <stdio.h>

//valores para conversao
#define END_SUCCESS 0
#define DECIMETRO 10
#define CENTIMETRO 100
#define MILIMETRO 1000

int main() {
    double metros;

    printf("Digite um valor em metros: ");
    scanf("%lf", &metros);

    double decimetros = metros * DECIMETRO;
    double centimetros = metros * CENTIMETRO;
    double milimetros = metros * MILIMETRO;

    printf("%.2lf metros correspondem a:\n", metros);
    printf("%.2lf decímetros\n", decimetros);
    printf("%.2lf centímetros\n", centimetros);
    printf("%.2lf milímetros\n", milimetros);

    return END_SUCCESS;
}

