CC = gcc
all : queue exec 

queue: queue.c
	$(CC) -c queue.c -o queue.o 

exec: queue.h main.c 
	$(CC) -c main.c -o main.o
	$(CC) queue.o main.o -o exec.out
clean:
	rm -f *.o
