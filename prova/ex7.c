#include <stdio.h>

#define END_SUCCESS 0

#define X 27
#define Y 32


int numeroDivisores(int x, int y) {
    int menor = (x < y) ? x : y;
    int count = 0;
    
    for (int i = 2; i <= menor; i++) {
        if (x % i == 0 && y % i == 0) {
            count++;
        }
    }
    
    return count;
}

int primosEntreSi(int x, int y){
    return (numeroDivisores(x, y) == 0) ? 1 : 0;
}

int main(int argc, char ** argv) {
    printf("%d", primosEntreSi(X, Y));
    
    return END_SUCCESS;
}

