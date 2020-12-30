CC=gcc 
AR=ar
MAINOBJECTS2=txtfind_main.o
MAINOBJECTS1=isort_main.o
LIBOBJECTS=isort.o isort.h 
LIBOBJECTS2=txtfind.o txtfind.h
LIBa=libisort_.a 
LIBa2=libtxtfind_.a
LIBso=libisort.so 
LIBso2=libtxtfind.so
FLAGS= -Wall -g 

all: isortd isorts txtfindd txtfinds isort isort_maind  txtfind txtfind_maind

isort: $(MAINOBJECTS1) $(LIBa)
	$(CC) $(flags) -o isort $(MAINOBJECTS1) $(LIBa) 
isort_maind: $(MAINOBJECTS1)
	$(CC) $(flags) -o isort_maind $(MAINOBJECTS1) ./$(LIBso)
txtfind: $(MAINOBJECTS2) $(LIBa2)
	$(CC) $(flags) -o txtfind $(MAINOBJECTS2) $(LIBa2) 
txtfind_maind: $(MAINOBJECTS2)
	$(CC) $(flags) -o tktfind_maind $(MAINOBJECTS2) ./$(LIBso2)

isortd: $(LIBOBJECTS)
	$(CC) -shared -o $(LIBso) $(LIBOBJECTS)
isorts: $(LIBOBJECTS)
	$(AR) -rcs $(LIBa) $(LIBOBJECTS)
txtfindd: $(LIBOBJECTS2)
	$(CC) -shared -o $(LIBso2) $(LIBOBJECTS2)
txtfinds: $(LIBOBJECTS2)
	$(AR) -rcs $(LIBa2) $(LIBOBJECTS2)

isort_main.o: isort_main.c isort.h 
	$(CC) $(FLAGS) -c isort_main.c
txtfind_main.o: txtfind_main.c txtfind.h
	$(CC) $(FLAGS) -c txtfind_main.c
isort.o: isort.c
	$(CC) -fPIC $(FLAGS) -c isort.c
txtfind.o: txtfind.c
	$(CC) -fPIC $(FLAGS) -c txtfind.c

.PHONY: clean all isortd isorts txtfindd fintxts

clean: 
	rm -f *.o isort_mains isort_maind txtfind_mains txtfind_maind $(LIBso) $(LIBa) $(LIBso2) $(LIBa2)

