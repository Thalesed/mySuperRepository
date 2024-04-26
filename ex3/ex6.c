#include <stdio.h>

#define END_SUCCESS 0

int main() {
    double salario_minimo, salario_pessoa;
    double salario_minimo_geral; // Defina o valor do salário mínimo geral no seu país

    printf("Digite o valor do salário mínimo: ");
    scanf("%lf", &salario_minimo);

    printf("Digite o valor do salário da pessoa: ");
    scanf("%lf", &salario_pessoa);

    // Calcula quantos salários mínimos a pessoa ganha
    double quant_salarios_minimos = salario_pessoa / salario_minimo;

    printf("A pessoa ganha %.2lf salários mínimos.\n", quant_salarios_minimos);

    return END_SUCCESS;
}

