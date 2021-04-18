CC=gcc
ARGS=-ansi -std=c99 -Wall
ZIEL=posix.out
OBJECTS=posix.o
CLEAN=rm -f
$(ZIEL): $(OBJECTS)
	$(CC) $(ARGS) -o $(ZIEL) $(OBJECTS)

101automat.o: posix.c
	$(CC) -c $(ARGS) -o posix.o posix.c

clean:
	$(CLEAN) $(OBJECTS)

cleanall:
	$(CLEAN) $(OBJECTS) $(ZIEL)
