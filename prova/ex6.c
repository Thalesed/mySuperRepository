#include <stdio.h>

#define END_SUCCESS 0

#define X 18
#define Y 12


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

int main(int argc, char ** argv) {
    printf("%d", numeroDivisores(X, Y));
    
    return END_SUCCESS;
}

