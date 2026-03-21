main: main.o queueADT.o
	gcc -o main main.o queueADT.o

main.o: main.c queueADT.h
	gcc -c main.c

queueADT.o: queueADT.c queueADT.h
	gcc -c queueADT.c
