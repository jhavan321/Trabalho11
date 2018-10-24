#include <stdio.h>
#include <strings.h>
#include "bibliotecas/telas.h"
#include "bibliotecas/arquivo.h"

int main(){
	int opcao;
	struct filme f[50];
	ler(f);
	printf("%s\n", f[0].nome);
	return 0;
	do {
		opcao = home();
		switch (opcao){
			case 1: 
				//cadastrar(f);
				break;
			case 2:
				//editar(f);
				break;
			case 3: 
				//locar(f);
				break;
			case 4:
				//devolver(f);
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
		}
	}
	while (opcao !=8);
	return 0;
}
