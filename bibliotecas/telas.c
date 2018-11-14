#include <stdio.h>
#include <strings.h>
#include <time.h>
#include "../tipos/filme.c"

int home() {
	int opc;
	do {
		system("clear");
		printf("*** Locadora ***\n\t1) Cadastrar Filme\n\t2) Editar\n\t3) Locar\n\t4) Devolver\n\t5) Pesquisar\n\t6) Relatório\n\t7) Relatório PDF\n\t8) Sair\nOpção: ");
		scanf("%d", &opc);
	} while(opc < 1 && opc > 8);
	return opc;
}



int cadastrar(struct filme f[], int tamanho) {
	int quantidade, index;
	struct filme novoFilme;
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
	printf("*** Digite o nome do filme***\n");
	fgets(novoFilme.nome, 40, stdin);
	novoFilme.locado = 0;
	printf("*** Digite a quantidade filmes a serem cadastrados ***\n");
	scanf("%i", &quantidade);
	for(index = tamanho; index < tamanho+quantidade; index++){
		f[index] = novoFilme;
	}
	return index;
}


void editar (struct filme f){
	printf("*** Digite o nome do filme ***\n");
	scanf("%s", &f.nome);
}

int listar (struct filme f[], int tamanho){
	system("clear");
	int opc;
	printf("*** Escolha um filme ***");
	for(int i = 0; i < tamanho; i++){
		if(f[i].locado == 0) {
			printf("\n%d - %s", i+1, f[i].nome);
		}	
	}
	scanf("%d", &opc);
	return opc-1;
}

struct filme locar (struct filme f){
	int c;
	printf("%s", f.nome);
	while ((c = getchar()) != '\n' && c != EOF)
		;
	printf("*** Digite o nome do cliente ***\n");
	fgets(f.nomeCliente, 40, stdin);
	printf("*** Digite o CPF do cliente ***\n");
	fgets(f.cpfCliente, 11, stdin);
	printf("*** Digite o endereco do cliente ***\n");
	fgets(f.enderecoCliente, 80, stdin);
	time_t data;
	time(&data);
	strcpy(f.dataDeLocacao, ctime(&data));
	f.locado = 1;
	printf("\nLocado com sucesso em %s", f.dataDeLocacao);
	getchar();
	return f;
}

void devolver(struct filme f){
	printf("*** Digite o nome e o cpf do cliente ***\n");
	scanf("%s", &f.nomeCliente);
	scanf("%s", &f.cpfCliente);
}		





