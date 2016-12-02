all:
	gcc -Wall -c listadup.c -o listadup.o
	gcc -Wall -c hashEncadeada.c -o hashEncadeada.o
	gcc -Wall -c lista.c -o lista.o
	gcc -Wall -c arvoreBin.c -o arvoreBin.o
	gcc -Wall -c arvoreAVL.c -o arvoreAVL.o
	gcc -Wall -c indice.c -o indice.o
	gcc -Wall -D O=4 listadup.o hashEncadeada.o lista.o arvoreBin.o arvoreAVL.o indice.o main.c -o main.out

run:
	./main.out