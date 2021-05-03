#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>

int primerk(int zahl) {
	for(int i = 2; i <= sqrt(zahl); i++) {
		if (zahl % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main(void) {
	int rueck, letzte, aktuelle;
	int j = 0;
	int max = 400;
	int ber = max / 4;

	while(j < 4) {
		rueck = fork();
		switch (rueck) {
			case -1: {
				printf("Error: Fehler beim erstellen des Kindprozesses");
				break;
			}

			case 0: {
				FILE *fp;
				char name[30];
				int kindber = ber * j;

				sprintf(name, "%i.txt", j);
				fp = fopen(name, "w");
				if(fp == NULL) {
					printf("Datei kann nicht geöffnet werden\n");
					exit(0);
				}
				for(int i = kindber; i < ber + kindber; i++) {
					if (primerk(i)) {	
						if(i - letzte == 2) {
							fprintf(fp, "%i, %i\n", letzte, i);
						}
						letzte = i;
					}
				}
				fclose(fp);
				exit(0);
			}

			default: {
				j++;
				break;
			}
		}
	}
	
}
