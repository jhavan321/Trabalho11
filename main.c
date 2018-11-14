#include <stdio.h>
#include <strings.h>
#include "bibliotecas/telas.h"
#include "bibliotecas/arquivo.h"

#define TAM 100

int main(){
	int index, opcao, tamanho;
	struct filme f[TAM];
	tamanho = ler(f);
	do {
		opcao = home();
		switch (opcao){
			case 1: 
				tamanho = cadastrar(f, tamanho);
				escrever(f, tamanho);
				break;
			case 2:
				//editar(f);
				break;
			case 3:
				index = listar(f, tamanho);
				f[index] = locar(f[index]);
				escrever(f, tamanho);
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
