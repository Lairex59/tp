CC = gcc
ZIEL = primzahlzwilling
OBJECT = primzahlzwilling.o
CLEAN = rm -f

$(ZIEL): $(OBJECT)
	$(CC) -o $(ZIEL) primzahlzwilling.c -lm

clean:
	$(CLEAN) $(OBJECT)

cleanall:
	$(CLEAN) $(OBJECT) $(ZIEL)

run:
	./primzahlzwilling
	cat 1.txt 2.txt 3.txt 4.txt > ergebnis.txt
	cat ergebnis.txt
