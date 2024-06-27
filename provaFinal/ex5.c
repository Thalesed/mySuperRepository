#include <stdio.h>
#include <stdlib.h>

#define END_SUCCESS 0
#define LIM 10

int main(){
	int x[LIM], y[LIM], z[LIM*2];

	for(int i=0;i<LIM;i++){
		printf("x[%d] = ", i);
		scanf("%d", &(x[i]));
	}
	for(int i=0;i<LIM;i++){
		printf("y[%d] = ", i+1);
		scanf("%d", &(y[i]));
	}

	
	for(int i=0;i<(LIM*2);i++){
		if(i % 2 == 0)
			z[i] = x[i/2];
		else
			z[i] = y[i/2];
		printf("%d\t", z[i]);
	}


	return END_SUCCESS;
}
