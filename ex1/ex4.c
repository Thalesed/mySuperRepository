#include <stdio.h> // incluindo biblioteca de entrade e saida
#include <stdlib.h> // biblioteca para system 

//definindo constante 0 para nao jogar valores sem sentido
#define END_SUCCESS 0 

// EX4: Listar conteudo do diretorio
int main(int argc, char ** argv){ //minha funcao principal
	system("ls"); // Linux >>>> Windows

	return END_SUCCESS; //retornando 0 porque o programa deu bom
}
