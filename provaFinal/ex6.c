#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define END_SUCCESS 0
#define NUM_REP 5000000
#define LIM 1000

int main(){
	srand(time(NULL));
	int vetor[LIM], tmp, max, min;

	for(int i=0;i<LIM;i++){
		vetor[i] = 0;
	}

	for(int i=0;i<NUM_REP;i++){
		tmp = rand() % LIM;
		vetor[tmp] ++;
	}
	
	max = vetor[0];
	min = vetor[0];

	for(int i=1;i<LIM;i++){
		if(vetor[i] > max)
			max = vetor[i];
		else if(vetor[i] < min)
			min = vetor[i];
	}

	printf("%d - %d = %d", max, min, (max - min));

	return END_SUCCESS;
}
