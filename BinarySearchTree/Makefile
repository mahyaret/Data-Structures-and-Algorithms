# makefile
CC = g++
CFLAGS = -I. -Wall -ftest-coverage -fprofile-arcs
DEPS = binary-search-tree.h
OBJ = binary-search-tree.o test-binary-search-tree.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

test-library.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lm -lncurses -Os 

clean:
	rm *.o 
