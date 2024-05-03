#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define END_SUCCESS 0

float calcularAreaQuadrado(float lado) {
    return lado * lado;
}

float calcularAreaRetangulo(float base, float altura) {
    return base * altura;
}

float calcularAreaTrapezio(float baseMaior, float baseMenor, float altura) {
    return ((baseMaior + baseMenor) * altura) / 2;
}

float calcularAreaTriangulo(float base, float altura) {
    return (base * altura) / 2;
}

float calcularAreaLosango(float diagonalMaior, float diagonalMenor) {
    return (diagonalMaior * diagonalMenor) / 2;
}

int main(int argc, char ** argv){
	float lado, base, altura, diagonalMaior, diagonalMenor, baseMenor, area;
	int cmd;

	do{
		printf("1 - Quadrado.\n \
		2 - Retangulo.\n \
		3 - Trapezio.\n \
		4 - Triangulo.\n \
		5 - Losangulo.\n \
		6 - Finalizar.\n");
		printf("Digite o comando: ");
		scanf("%d", &cmd);
		switch (cmd){
			case 1:
			    printf("Digite o lado do quadrado: ");
			    scanf("%f", &lado);
			    area = calcularAreaQuadrado(lado);
			    break;
			case 2:
			    printf("Digite a base do retangulo: ");
			    scanf("%f", &base);
			    printf("Digite a altura do retangulo: ");
			    scanf("%f", &altura);
			    area = calcularAreaRetangulo(base, altura);
			    break;
			case 3:
			    printf("Digite a base maior do trapezio: ");
			    scanf("%f", &base);
			    printf("Digite a base menor do trapezio: ");
			    scanf("%f", &baseMenor);
			    printf("Digite a altura do trapezio: ");
			    scanf("%f", &altura);
			    area = calcularAreaTrapezio(base, baseMenor, altura);
			    break;
			case 4:
			    printf("Digite a base do triangulo: ");
			    scanf("%f", &base);
			    printf("Digite a altura do triangulo: ");
			    scanf("%f", &altura);
			    area = calcularAreaTriangulo(base, altura);
			    break;
			case 5:
			    printf("Digite a diagonal maior do losango: ");
			    scanf("%f", &diagonalMaior);
			    printf("Digite a diagonal menor do losango: ");
			    scanf("%f", &diagonalMenor);
			    area = calcularAreaLosango(diagonalMaior, diagonalMenor);
			    break;
			case 6:
				break;
			default:
				printf("Comando inesistente\n");
				cmd = 0;
		}
		if(cmd != 6 && cmd  != 0) printf("a area eh %f\n", area);
	}while(cmd != 6);
	printf("programa encerrado");


	return END_SUCCESS;
}
