#include <stdio.h>

#define END_SUCCESS 0

#define X 123
#define Y 172


int maior(int x, int y) {
    return (x >= y) ? x : y;
}

int main(int argc, char ** argv) {
    printf("%d", maior(X, Y));

    return END_SUCCESS;
}

