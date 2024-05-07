#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define END_SUCCESS 0

#define X 2
#define ALPHA 2


float flouca(float x, float a) {
    if(x < 0)
	return (a * ( pow(-x, (1/2) ) ) );
    else if(x >= 0 && x < abs(pow(a, 3)))
	return (pow( (a * M_E), (-a * x) ));
    else if(x >= abs(pow(a, 3)))
    	return a;
}

int main(int argc, char ** argv) {
    printf("%f", flouca(X, ALPHA));

    return END_SUCCESS;
}

