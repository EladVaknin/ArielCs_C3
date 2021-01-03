FLAGS= -Wall -g 
CFLAGS= -Werror
CC= gcc
all: isort txtfind
isort: mainS.o isort.o
	$(CC) $(FLAGS) -o isort mainS.o isort.o
txtfind: mainT.o txtfind.o
	$(CC) $(FLAGS) -o txtfind mainT.o txtfind.o
mainS.o: mainS.c isort.h
	$(CC) $(FLAGS) -c mainS.c
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c
mainT.o: mainT.c txtfind.h
	$(CC) $(FLAGS) -c mainT.c
txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c
clean:
	rm isort txtfind *.o

.PHONY: clean all isort txtfind