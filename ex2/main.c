#include <stdio.h>
#include <math.h>

#define END_SUCCESS 0 

double cauchy(double x) {
    return 1 / (M_PI * (1 + x * x));
}

double gumbel(double x, double mu, double beta) {
    return (1 / beta) * exp(-(x - mu) / beta) * exp(-exp(-(x - mu) / beta));
}

double laplace(double x, double mu, double b) {
    return exp(-fabs(x - mu) / b) / (2 * b);
}

int main(int argc, char ** argv) {
    printf("cauchy: %.6lf\ngumbel: %.6lf\nlaplace: %.6lf", cauchy(-2), gumbel(0, 0.5, 2), laplace(-6, -5, 4));

    return END_SUCCESS;
}

