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
	gets(novoFilme.nome);
	novoFilme.locado = 0;
    novoFilme.jaLocado = 0;
	printf("*** Digite a quantidade filmes a serem cadastrados ***\n");
	scanf("%i", &quantidade);
	for(index = tamanho; index < tamanho+quantidade; index++){
		f[index] = novoFilme;
	}
	return index;
}

int listar(struct filme f[], int tamanho) {
	system("clear");
	int c, opc, opt = 0;
	printf("*** Escolha um filme ***\n\n");
	for(int i = 0; i < tamanho; i++) {
		if(f[i].locado == 0) {
			printf("%d - %s\n", i+1, f[i].nome);
            opt++;
		}	
	}
	if(opt == 0) {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        system("clear");
        printf("*** Nenhum filme disponível ***");
        getchar();
        return -1;
    }
	scanf("%d", &opc);
	return opc-1;
}

struct filme locar(struct filme f) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
	printf("*** Digite o nome do cliente ***\n");
	gets(f.nomeCliente);
	printf("*** Digite o CPF do cliente ***\n");
	gets(f.cpfCliente);
	printf("*** Digite o endereco do cliente ***\n");
	gets(f.enderecoCliente);
	time_t data;
	time(&data);
	strftime(f.dataDeLocacao, 12, "%d/%m/%Y", localtime(&data));
	f.locado = 1;
    f.jaLocado = 1;
	printf("\nLocado com sucesso em %s", f.dataDeLocacao);
	getchar();
	return f;
}

int listarLocados(struct filme f[], int tamanho) {
    system("clear");
	int c, opc, opt = 0;
	printf("*** Escolha um filme ***\n\n");
	for(int i = 0; i < tamanho; i++) {
		if(f[i].locado == 1) {
			printf("%d - %s\n", i+1, f[i].nome);
            opt++;
		}	
	}
	if(opt == 0) {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        system("clear");
        printf("*** Nenhum filme locado ainda ***");
        getchar();
        return -1;
    }
	scanf("%d", &opc);
	return opc-1;
}

struct filme devolver(struct filme f) {
	f.locado = 0;
    time_t data;
	time(&data);
	strftime(f.dataDeDevolucao, 12, "%d/%m/%Y", localtime(&data));
    printf("\nDevolvido com sucesso em %s", f.dataDeDevolucao);
	getchar();
    return f;
}

int listarTodos(struct filme f[], int tamanho) {
    system("clear");
	int c, opc, opt = 0;
	printf("*** Escolha um filme ***\n\n");
	for(int i = 0; i < tamanho; i++) {
        printf("%d - %s\n", i+1, f[i].nome);
        opt++;
	}
	if(opt == 0) {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        system("clear");
        printf("*** Nenhum filme cadastrado ainda ***");
        getchar();
        return -1;
    }
	scanf("%d", &opc);
	return opc-1;
}

struct filme editar(struct filme f) {
    int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
	printf("*** Digite o nome do filme ***\n");
	gets(f.nome);
	return f;
}

void pesquisar(struct filme f[], int tamanho) {
    system("clear");
	int c, opt = 0;
    char nome[40];
    while ((c = getchar()) != '\n' && c != EOF)
        ;
	printf("*** Informe o nome do filme ***\n");
    gets(nome);
	for(int i = 0; i < tamanho; i++) {
        if(strstr(nome, f[i].nome)) {
            printf("%d - %s | ", i+1, f[i].nome);
            if(f[i].locado == 0) {
                printf("Disponivel");
                if(f[i].jaLocado > 0) {
                    printf(" - devolvido pela ultima vez em %s", f[i].dataDeDevolucao);
                }
            } else {
                printf("Locado em %s por %s", f[i].dataDeLocacao, f[i].nomeCliente);
            }
            printf("\n");
            opt++;
        }
	}
	if(opt == 0) {
        system("clear");
        printf("*** Nenhum filme encontrado ***");
    }
	getchar();
}

void relatorio(struct filme f[], int tamanho) {
    system("clear");
	int c, optD = 0, optL = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
	printf("*** RELATORIO ***\n\n");
    printf("Disponiveis:\n");
	for(int i = 0; i < tamanho; i++) {
        if(f[i].locado == 0) {
            printf("%d - %s | ", i+1, f[i].nome);
            if(f[i].jaLocado == 0) {
                printf("Nunca locado");
            } else {
                printf("Devolvido pela ultima vez em %s", f[i].dataDeDevolucao);
            }
            printf("\n");
            optD++;
        }
	}
	if(optD == 0) {
        printf("Nenhum filme disponivel\n");
    }
    printf("\nLocados:\n");
	for(int i = 0; i < tamanho; i++) {
        if(f[i].locado > 0) {
            printf("%d - %s | Locado em %s por %s", i+1, f[i].nome, f[i].dataDeLocacao, f[i].nomeCliente);
            printf("\n");
            optL++;
        }
	}
	if(optL == 0) {
        printf("Nenhum filme locado\n");
    }
	getchar();
}

void gerarRelatorioPDF() {
    int c;
    system("rm relatorio.pdf");
    system("enscript -p relatorio.ps dados/relatorio.txt");
    system("ps2pdf relatorio.ps relatorio.pdf");
    system("rm relatorio.ps");
    system("rm dados/relatorio.txt");
    system("clear");
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("*** Relatorio gerado e salvo como PDF ***");
    getchar();
}
