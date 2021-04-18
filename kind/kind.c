#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int erg = 0;
	if(argc != 3) {
		fprintf(stderr, "Aufruf: kind <Zeit Kindprozess> <Zeit Elternprozess>\n");
		exit(-1);
	}
	erg = fork();
	switch (erg) {
		case -1: printf("ERROR: Erstellen des KindProzesses fehlgeschlagen\n");
			 exit(-2);
		case 0: {
		       	printf("Erstellen des Kindprozesses erfolgreich\n");
			printf("Kind-PID: %i\n", getpid());
			printf("Kind-PPID: %i\n", getppid());
			fflush(stdout);
			sleep(atoi(argv[1]));
			printf("Kind -ENDE-\n PID: %i || PPID: %i\n", getpid(), getppid());
			fflush(stdout);
			break;
		}
		default: {
                        printf("Parent-PID: %i\n", getpid());
                        printf("Parent-PPID: %i\n", getppid());
			fflush(stdout);
			if (atoi(argv[2]) > atoi(argv[1])) {
				printf("Kindprozess wurde beendet. Wait(return): %i\n", wait(NULL));
				sleep(atoi(argv[2]) - atoi(argv[1]));
			} else {
				sleep(atoi(argv[2]));
			}
			printf("Eltern -ENDE-\n");
			fflush(stdout);
		       	break;
		}
	}
	return(0);
}
