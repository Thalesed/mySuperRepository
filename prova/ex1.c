#include <stdio.h>
#include <math.h>

#define END_SUCCESS 0

#define X 6
#define ALPHA 2
#define BETA 2


float loglcdf(float x, float a, float b) {
    if(x < 0)
	    return 0;
    return (1/(1 + pow(x/a, b) ) );
}

int main(int argc, char ** argv) {
    printf("%f", loglcdf(X, ALPHA, BETA));

    return END_SUCCESS;
}

