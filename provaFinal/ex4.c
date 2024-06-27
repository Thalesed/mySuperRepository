#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define END_SUCCESS 0
#define MAX 255

double mediaVetor(int n, double v[]){
	double res;
	for(int i=0;i<n;i++){
		res += v[i];
	}
	res / n;
	return res;
}

int main(){
	srand(time(NULL));

	int n = rand() % MAX;
	double v[n];

	for(int i=0;i<n;i++){
		v[i] = rand();
	}

	printf("media eh %lf", mediaVetor(n, v));

	return END_SUCCESS;
}

