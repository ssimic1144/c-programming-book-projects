program: program.o stack.o
	gcc -o program program.o stack.o

program.o: program.c stack.h
	gcc -c program.c

stack.o: stack.c stack.h
	gcc -c stack.c
