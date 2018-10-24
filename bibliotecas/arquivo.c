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
	return 1;
}

int escrever(struct filme f[]) {
	FILE *arquivo;
	int indice = 0;
	arquivo = fopen("./dados/filmes.dat", "w");
	if(arquivo == NULL) {
		return 0;
	}
	fwrite(f, sizeof(struct filme), 1, arquivo);
	fflush(arquivo);
	fclose(arquivo);
	return 1;
}
