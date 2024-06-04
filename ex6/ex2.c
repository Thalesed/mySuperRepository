#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define END_SUCCESS 0 

int main() {
    uint8_t numeroAleatorio, entrada, continuar = 1;
    
    srand(time(NULL));
    
    while (continuar) {
        numeroAleatorio = (uint8_t)(rand() % 100 + 1);
        printf("Jogo de Adivinhacao: Tente adivinhar o numero entre 1 e 100.\n");

        do {
            printf("Informe seu palpite: ");
            scanf("%hhu", &entrada);

            if (entrada < numeroAleatorio) {
                printf("ERROU, o numero e MAIOR que %u.\n", entrada);
            } else if (entrada > numeroAleatorio) {
                printf("ERROU, o numero e MENOR que %u.\n", entrada);
            } else {
                printf("ACERTOU!\n");
            }
        } while (entrada != numeroAleatorio);
	
	continuar = 0;
        printf("Deseja tentar novamente? (1 para sim, 0 para nao): ");
        scanf("%hhu", &continuar);
    }

    printf("Obrigado por jogar!\n");

    return END_SUCCESS;
}

