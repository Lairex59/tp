CC=gcc
ARGS=-ansi -std=c99 -Wall
ZIEL=kind.out
OBJECTS=kind.o
CLEAN=rm -f
$(ZIEL): $(OBJECTS)
	$(CC) $(ARGS) -o $(ZIEL) $(OBJECTS)

101automat.o: kind.c
	$(CC) -c $(ARGS) -o kind.o kind.c

clean:
	$(CLEAN) $(OBJECTS)

cleanall:
	$(CLEAN) $(OBJECTS) $(ZIEL)
