CC = gcc
ZIEL = primzahlzw
OBJECT = primzahlzw.o
CLEAN = rm -f

$(ZIEL): $(OBJECT)
	$(CC) -o $(ZIEL) primzahlzw.c -lm

clean:
	$(CLEAN) $(OBJECT)

cleanall:
	$(CLEAN) $(OBJECT) $(ZIEL)

run:
	./primzahlzw
	cat 1.txt 2.txt 3.txt 4.txt > ergebnis.txt
	cat ergebnis.txt
