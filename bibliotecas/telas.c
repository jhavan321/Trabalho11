int home() {
	int opc;
	do {
		system("cls");
		printf("*** Locadora ***\n\t1) Cadastrar Filme\n\t2) Editar\n\t3) Locar\n\t4) Devolver\n\t5) Pesquisar\n\t6) Relatório\n\t7) Relatório PDF\nOpção:");
		scanf("%d", &opc);
	while(opc < 1 && opc > 7);
	return opc;
}
