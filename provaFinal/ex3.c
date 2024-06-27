#include <stdio.h>
#include <stdlib.h>

#define END_SUCCESS 0

int main(){
	int numLin, num = 1;

	printf("Digite o numero de linhas: ");
	scanf("%d", &numLin);

	for(int i=1;i<=numLin;i++){
		for(int j=0;j<i;j++){
			printf("%d ", num);
			num ++;
		}
		printf("\n");
	}	

	return END_SUCCESS;
}
