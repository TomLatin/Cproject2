CC=gcc
FLAGS=-Wall -g

all:myBanks ExeBank

myBanks:libmyBank.a

main.o:main.c myBank.h
	$(CC) $(FLAGS) -c main.c

ExeBank:main.o libmyBank.a
	$(CC) $(FLAGS) -o ExeBank main.o libmyBank.a

libmyBank.a:myBank.o myBank.h
	ar rcs libmyBank.a myBank.o myBank.h

myBank.o:myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c



.PHONY:clean all

clean:
	rm -f *.o *.a *.so ExeBank