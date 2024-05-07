#include <stdio.h>

#define END_SUCCESS 0

#define X 16
#define Y 12

int mmc(int x, int y) {
	int maior = x;
	int menor = y;
	int res = 1;
	if(y > x){
		maior = y;
		menor = x;
	}
	for(int i = maior;1;i++){
		if(i % maior == 0 && i % menor == 0){
			res = i;
			break;
		}
	}
	return res;
	
}

int main(int argc, char ** argv) {
    printf("%d", mmc(X, Y));

    return END_SUCCESS;
}

