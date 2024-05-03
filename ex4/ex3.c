#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define END_SUCCESS 0

float calcularMedia(float a, float b, float c) {
    return (a + b + c) / 3.0;
}

float encontrarMaior(float a, float b, float c) {
    float maior = a;
    if (b > maior) {
        maior = b;
    }
    if (c > maior) {
        maior = c;
    }
    return maior;
}

float encontrarMenor(float a, float b, float c) {
    float menor = a;
    if (b < menor) {
        menor = b;
    }
    if (c < menor) {
        menor = c;
    }
    return menor;
}

float calcularSoma(float a, float b, float c) {
    return a + b + c;
}

float calcularSomaQuadrados(float a, float b, float c) {
    return (a * a) + (b * b) + (c * c);
}

int main(int argc, char ** argv){
	float a, b, c, res;
	int cmd;
	
	printf("Digite os valores A B C: ");
	scanf("%f %f %f", &a, &b, &c);

	do{
		printf("1 - Media dos Valores.\n \
		2 - Maior Valor.\n \
		3 - Menor Valor.\n \
		4 - Soma dos Valores.\n \
		5 - Soma dos Quadrados dos Valores.\n \
		6 - Finalizar.\n");
		printf("Digite o comando: ");
		scanf("%d", &cmd);
		switch (cmd){
			case 1:
				res = calcularMedia(a, b, c);
				break;
			case 2:
				res = encontrarMaior(a, b, c);
				break;
			case 3:
				res = encontrarMenor(a, b, c);
				break;
			case 4:
				res = calcularSoma(a, b, c);
				break;
			case 5:
				res = calcularSomaQuadrados(a, b, c);
				break;
			case 6:
				break;
			default:
				printf("Comando inesistente\n");
				cmd = 0;
		}
		if(cmd != 6 && cmd  != 0) printf("o resultado eh %f\n", res);
	}while(cmd != 6);
	printf("programa encerrado");


	return END_SUCCESS;
}
