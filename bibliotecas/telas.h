#include "../tipos/filme.c"

int home();

int cadastrar(struct filme f[], int tamanho);

int listar(struct filme f[], int tamanho);

struct filme locar(struct filme f);

int listarLocados(struct filme f[], int tamanho);

struct filme devolver(struct filme f);

int listarTodos(struct filme f[], int tamanho);

struct filme editar(struct filme f);

void pesquisar(struct filme f[], int tamanho);

void relatorio(struct filme f[], int tamanho);

void gerarRelatorioPDF();
