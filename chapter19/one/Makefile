main: main.o stackADT.o
	gcc -o main main.o stackADT.o

main.o: main.c stackADT.h
	gcc -c main.c

stackADT.o: stackADT.c stackADT.h
	gcc -c stackADT.c
