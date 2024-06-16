#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define END_SUCCESS 0
#define NO_FILE_ERROR 15
#define true (1 == 1)
#define false (1 == 0)

int main(int argc, char ** argv){
	
	FILE * msf;
	int col, lin, quant = 0, buff;
	uint8_t run = true;
	int *** matrizes;
	char * fileName = "mySuperFile";

	if(argc > 1){
		fileName = argv[1];
	}

	msf = fopen(fileName, "r");

	if(msf == NULL){
		fprintf(stderr, "Arquivo não encontrado ou sem permissão para abrir");
		return NO_FILE_ERROR;
	}
	fscanf(msf, "%d %d", &lin, &col);
	
	matrizes = (int ***)malloc((quant + 1) * sizeof(int **));

	while(run && !feof(msf)){
		if(quant != 0){
			matrizes = (int ***)realloc(matrizes, (quant + 1)* sizeof(int **));
		}
		matrizes[quant] = (int **)malloc(lin * sizeof(int *));
		for(int i=0;i<lin;i++){
			matrizes[quant][i] = (int *)malloc(col * sizeof(int));
		}

		for(int i=0;i<lin;i++){
			for(int j=0;j<col;j++){
				fscanf(msf, "%d", &buff);
				if(buff != EOF){
					matrizes[quant][i][j] = buff;
				}else{
					run = false;
					break;
				}
			}
		}
		if(buff != EOF){
			quant ++;
		}
	}

	for(int i=0;i<lin;i++){
		for(int j=0;j<col;j++){
			buff = 0;
			for(int k=0;k<quant - 1;k++){
				buff += matrizes[k][i][j];
			}
			printf("%d\t", buff);
		}
		printf("\n");
	}

	fclose(msf);

	return END_SUCCESS;
}
