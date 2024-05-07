#include <stdio.h>

#define END_SUCCESS 0

#define N 5

int fibonacci(int n){
	int a=0, b=1, tmp;
	for(int i=0;i<n-1;i++){
		tmp = a;
		a = b;
		b+= tmp;
	}
	return a;
}

int main(int argc, char ** argv){
	printf("%d", fibonacci(N));	
	return END_SUCCESS;
}
