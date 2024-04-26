#include <stdio.h>
#include <stdlib.h>


#define END_SUCCESS 0
#define QUANT 3 + 1

double calcResistencia(int quant, double resistencias[QUANT]){
	double res = 0.0;
	for(int i=0;i<quant;i++){
		res += 1/(resistencias[i]);
	}

	res = 1/res;

	return res;
	
}

int main(int argc, char ** argv){
	printf("teste");
	double resistencias[QUANT]; // ponteiro para o vetor de resistencias
			      
	resistencias[0] = 20;
	resistencias[2] = 30;
	resistencias[3] = 30;
	
//	printf("%lf", calcResistencia(QUANT, resistencias));

	return END_SUCCESS;
}
