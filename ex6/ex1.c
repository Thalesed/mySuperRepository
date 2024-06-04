#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

#define END_SUCCESS 0 
#define TAMANHO (uint8_t)64

void gerarValores(uint16_t vetor[], uint8_t tamanho) {
    for (uint8_t i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 300 + 1;
    }
}

uint16_t maiorValor(uint16_t vetor[], uint8_t tamanho) {
    uint16_t maior = vetor[0];
    for (uint8_t i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

uint16_t menorValor(uint16_t vetor[], uint8_t tamanho) {
    uint16_t menor = vetor[0];
    for (uint8_t i = 1; i < tamanho; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

double valorMedio(uint16_t vetor[], uint8_t tamanho) {
    uint32_t soma = 0;
    for (uint16_t i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }
    return (double)soma / tamanho;
}

uint16_t primeiroValor(uint16_t vetor[]) {
    return vetor[0];
}

uint16_t ultimoValor(uint16_t vetor[], uint8_t tamanho) {
    return vetor[tamanho - 1];
}

double valorMediano(uint16_t vetor[], uint8_t tamanho) {
    for (uint8_t i = 0; i < tamanho - 1; i++) {
	for (uint8_t j = i + 1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                uint16_t temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    if (tamanho % 2 == 0) {
        return (vetor[tamanho / 2 - 1] + vetor[tamanho / 2]) / 2.0;
    } else {
        return vetor[tamanho / 2];
    }
}

int main() {
    srand(time(NULL));

    uint16_t produtos[TAMANHO];

    gerarValores(produtos, TAMANHO);

    printf("Valores gerados: ");
    for (uint8_t i = 0; i < TAMANHO; i++) {
        printf("%d ", produtos[i]);
    }
    printf("\n");

    printf("Maior valor: %u\n", maiorValor(produtos, TAMANHO));
    printf("Menor valor: %u\n", menorValor(produtos, TAMANHO));
    printf("Valor medio: %.2f\n", valorMedio(produtos, TAMANHO));
    printf("Primeiro valor: %d\n", primeiroValor(produtos));
    printf("Ultimo valor: %d\n", ultimoValor(produtos, TAMANHO));
    printf("Valor mediano: %.2f\n", valorMediano(produtos, TAMANHO));

    return END_SUCCESS;
}

