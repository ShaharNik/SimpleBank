CC=gcc
AR=ar -rcs
OBJECTS_MAIN=main.o
OBJECTS_LIB = myBank.o
FLAGS= -Wall -fPIC

all: mybanks mybankd mains maind
mains: $(OBJECTS_MAIN) mybanks
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libmyBank.a
maind: $(OBJECTS_MAIN) mybankd
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyBank.so
mybanks: $(OBJECTS_LIB) myBank.h
	$(AR) libmyBank.a $(OBJECTS_LIB)
mybankd: $(OBJECTS_LIB) myBank.h
	$(CC) -shared -o libmyBank.so $(OBJECTS_LIB)
main.o: main.c
	$(CC) $(FLAGS) -c main.c
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so mybanks mybankd mains maind