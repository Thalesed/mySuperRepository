#include <stdio.h>
#include <stdlib.h>

#define END_SUCCESS 0

int main(){
	int nota;
	char conceito;

	printf("Digite a nota do aluno: ");
	scanf("%d", &nota);

	switch(nota){
		case 5:
			conceito = 'E';
			break;
		case 6:
			conceito = 'D';
			break;
		case 7:
			conceito = 'C';
			break;
		case 8:
			conceito = 'B';
			break;
		case 9:
			conceito = 'A';
			break;
		case 10:
			conceito = 'A';
			break;
		default:
			conceito = 'F';
			break;
	}

	printf("Nota %d recebe conceito %c", nota, conceito);

	return END_SUCCESS;
}
