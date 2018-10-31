#include <stdio.h>
#include <strings.h>
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



int cadastrar(struct filme f) {

		int quantidade;		
		printf("*** Digite o nome e a quantidade do filme ***\n");
		scanf("%s", &f.nome);
		scanf("%i", &quantidade);
		return quantidade;
}


void editar (struct filme f){
		printf("*** Digite o nome do filme ***\n");
		scanf("%s", &f.nome);
}

void locar (struct filme f){

		printf("*** Digite o nome e o cpf do cliente ***\n");
		scanf("%s", &f.nomeCliente);
		scanf("%s", &f.cpfCliente);
	 	scanf("%s", &f.enderecoCliente);
		time_t data;
		time(&data);
		strcpy(f.dataDeLocacao, ctime(&data));
}

void devolver(struct filme f){
		printf("*** Digite o nome e o cpf do cliente ***\n");
		scanf("%s", &f.nomeCliente);
		scanf("%s", &f.cpfCliente);
		strcpy(f.cpfCliente, "");
		strcpy(f.nomeCliente, "");
		strcpy(f.status, "d");
}		





