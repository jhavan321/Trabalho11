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
				index = listarTodos(f, tamanho);
                if(index == -1) {
                    break;
                } else {
                    f[index] = editar(f[index]);
                    escrever(f, tamanho);
                    break;
                }
				break;
			case 3:
				index = listar(f, tamanho);
                if(index == -1) {
                    break;
                } else {
                    f[index] = locar(f[index]);
                    escrever(f, tamanho);
                    break;
                }
			case 4:
                index = listarLocados(f, tamanho);
                if(index == -1) {
                    break;
                } else {
                    f[index] = devolver(f[index]);
                    escrever(f, tamanho);
                    break;
                }
			case 5:
                pesquisar(f, tamanho);
				break;
			case 6:
                relatorio(f, tamanho);
				break;
			case 7:
                gerarRelatorioTXT(f, tamanho);
                gerarRelatorioPDF();
				break;
		}
	}
	while (opcao !=8);
	return 0;
}
