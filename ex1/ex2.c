#include <stdio.h> // incluindo biblioteca de entrade e saida

//definindo constante 0 para nao jogar valores sem sentido
#define END_SUCCESS 0 

// EX2: Imprimir o sinal Sonoro \a
// Max disse que isso nao funcionava na aula, mas funcionou para mim
int main(int argc, char ** argv){ //minha funcao principal

	printf("\a");
	// std::cout << "\a";

	return END_SUCCESS; //retornando 0 porque o programa deu bom
}
