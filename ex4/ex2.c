#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define END_SUCCESS 0

int main(int argc, char ** argv){
	int num, maior;
	maior = INT32_MIN;

	while(1){
		printf("(0 encerra o programa)Digite um numero: ");
		scanf("%d", &num);
		if(num == 0){
			printf("programa encerrado\n");
			break;
		}else if(num > maior){
			maior = num;
		}

		printf("Ultimo numero digitado: %d\nMaior numero ja digitado: %d\n", num, maior);
	}


	return END_SUCCESS;
}
