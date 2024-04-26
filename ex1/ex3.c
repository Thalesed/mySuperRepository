#include <stdio.h> // incluindo biblioteca de entrade e saida
#include <math.h> // biblioteca que contem a funcao seno

//definindo constante 0 para nao jogar valores sem sentido
#define END_SUCCESS 0 

// EX3: Calcular o valor de Seno de 3.14 e 4.13
int main(int argc, char ** argv){ //minha funcao principal
	float y1, y2;
	y1 = sin(3.14); // primeiro seno
	y2 = sin(4.13); // segundo seno
	
	printf("%f %f", y1, y2); // imprimindo

	return END_SUCCESS; //retornando 0 porque o programa deu bom
}
