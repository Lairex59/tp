CC=gcc
ARGS=-ansi -std=c99 -Wall
ZIEL=exec.out
OBJECTS=exec.o
CLEAN=rm -f
$(ZIEL): $(OBJECTS)
	$(CC) $(ARGS) -o $(ZIEL) $(OBJECTS)

exec.o: exec.c
	$(CC) -c $(ARGS) -o exec.o exec.c

clean:
	$(CLEAN) $(OBJECTS)

cleanall:
	$(CLEAN) $(OBJECTS) $(ZIEL)
