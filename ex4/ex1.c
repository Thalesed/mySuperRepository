#include <stdio.h>
#include <stdlib.h>

#define END_SUCCESS 0

int main(int argc, char ** argv){
	int num;

	while(1){
		printf("Digite um numero:");
		scanf("%d", &num);
		if(num < 0){
			fprintf(stderr, "Numero negativo detectado. INsira numeros positivos ou zero\n");
			continue;
		}else if(num == 0){
			printf("Programa encerrado\n");
			break;
		}else {
			printf("%d eh um numero %s\n", num, (num % 2) ? "impar" : "par");
		}

	}

	return END_SUCCESS;
}
