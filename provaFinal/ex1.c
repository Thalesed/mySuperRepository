#include <stdio.h>
#include <stdlib.h>

#define END_SUCCESS 0
#define LIM 1/1000000

int fibo(int x){
	int res = 1;
	if(x == 0)
		return 1;
	for(int i=1;i<=x;i++){
		res *= i;
	}

	return res;
}

int main(){
	double e = 1, tmp;
	int count = 1;

	do{
		tmp = 1.0/fibo(count);
		e += tmp;
		count ++;
	}while(tmp > LIM);

	printf("%lf", e);

	return END_SUCCESS;
}
