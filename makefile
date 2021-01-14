CC=gcc
FLAGS= -Wall -g

.PHONY= all clean
frequency:main.o
	$(CC) $(FLAGS) -o frequency main.o
main.o: main.c 
	$(CC) $(FLAGS) -c main.c
clean: 
	rm -f *.o  frequency
	
all: frequency
	
