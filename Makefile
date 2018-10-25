all: locadora.exe

locadora.exe: main.o arquivo.o telas.o
	gcc main.o arquivo.o telas.o -o locadora
	rm *.o

main.o:
	gcc -c main.c

arquivo.o:
	gcc -c bibliotecas/arquivo.c

telas.o:
	gcc -c bibliotecas/telas.c
