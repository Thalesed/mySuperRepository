#include <stdio.h>
#include <stdlib.h>

#include <stdint.h>

#define END_SUCCESS 0
#define NO_FILE_ERROR 15
#define true (1 == 1)
#define false (1 == 0)

int main(int argc, char ** argv){
	FILE * msf;

	char * fileName = "mySuperFile";

	int codigo, estoque, preco, prod = 0;

	if(argc > 1){
		fileName = argv[1];
	}

	msf = fopen(fileName, "r");
	if(msf == NULL){
		fprintf(stderr, "Arquivo não encontrado ou sem permissão para abrir");
		return NO_FILE_ERROR;
	}

	while(!feof(msf)){
		prod ++;
		fscanf(msf, "%d %d %d", &codigo, &estoque, &preco);
		printf("Produto %d:\n\tCódigo: %d\n\tQuantidade disponivel: %d\n\tPreco Unitario: %d\n", prod,  codigo, estoque, preco);
	}

	fclose(msf);

	return END_SUCCESS;
}
