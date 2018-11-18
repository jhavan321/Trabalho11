#include <stdio.h>
#include <stdlib.h>
#include "../tipos/filme.c"

int ler(struct filme f[]) {
	int indice = 0;
	FILE *arquivo;
	struct filme entrada;
	arquivo = fopen("./dados/filmes.dat", "r");
	if(arquivo == NULL) {
		return 0;
	}
	while(fread(&entrada, sizeof(struct filme), 1, arquivo)) {
		f[indice] = entrada;
		indice++;
	}
	fclose(arquivo);
	return indice;
}

int escrever(struct filme f[], int tamanho) {
	FILE *arquivo;
	int indice = 0;
	arquivo = fopen("./dados/filmes.dat", "w");
	if(arquivo == NULL) {
		return 0;
	}
	fwrite(f, sizeof(struct filme) * tamanho, 1, arquivo);
	fflush(arquivo);
	fclose(arquivo);
	return 1;
}

int gerarRelatorioTXT(struct filme f[], int tamanho) {
    FILE *arquivo;
    arquivo = fopen("./dados/relatorio.txt", "w");
    if(arquivo == NULL) {
        return 0;
    }
    int optD = 0, optL = 0;
    fprintf(arquivo, "*** RELATORIO ***\n\n");
    fprintf(arquivo, "Disponiveis:\n");
	for(int i = 0; i < tamanho; i++) {
        if(f[i].locado == 0) {
            fprintf(arquivo, "%d - %s | ", i+1, f[i].nome);
            if(f[i].jaLocado == 0) {
                fprintf(arquivo, "Nunca locado");
            } else {
                fprintf(arquivo, "Devolvido pela ultima vez em %s", f[i].dataDeDevolucao);
            }
            fprintf(arquivo, "\n");
            optD++;
        }
	}
	if(optD == 0) {
        fprintf(arquivo, "Nenhum filme disponivel\n");
    }
    fprintf(arquivo, "\nLocados:\n");
	for(int i = 0; i < tamanho; i++) {
        if(f[i].locado > 0) {
            fprintf(arquivo, "%d - %s\n\tNome: %s  CPF: %s\n\tEndereco: %s\n\tLocado em %s\n", i+1, f[i].nome, f[i].nomeCliente, f[i].cpfCliente, f[i].enderecoCliente, f[i].dataDeLocacao);
            optL++;
        }
	}
	if(optL == 0) {
        fprintf(arquivo, "Nenhum filme locado\n");
    }
    fflush(arquivo);
	fclose(arquivo);
    return 1;
}
