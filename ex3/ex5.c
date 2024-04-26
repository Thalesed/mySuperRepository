#include <stdio.h>
#include <math.h>

#define END_SUCCESS 0

double calcularVolumeEsfera(double raio) {
    return (4.0 / 3.0) * M_PI * pow(raio, 3);
}

int main(int argc, char ** argv) {
    double raio;

    printf("Digite o raio da esfera: ");
    scanf("%lf", &raio);

    double volume = calcularVolumeEsfera(raio);

    printf("O volume da esfera com raio %.2lf é %.2lf\n", raio, volume);

    return END_SUCCESS;
}

