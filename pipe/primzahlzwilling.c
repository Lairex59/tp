#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int prim(int z) {
	int ret = 1;	
	for(int i = 2; i <= sqrt(z); i++) {
		if (z % i == 0) {
			ret = 0;
		}
	}
	return(ret);
}

int main(void) {
	FILE *eins, *zwei, *drei, *vier;
	int erg;
	int max = 1000;
	//ERSTER KINDPROZESS
	erg = fork();
	//Rückgabewert von fork analysieren
        switch (erg){
	//Im Fehlerfall
		case -1: {
			//kindprozess wurde nicht erstellt, fehlermeldung erfolgt
        		printf("Error: Fehler beim erstellen des Childprozesses");
        		break;
		}
		//Wenn 0, sind wir im Kindprozess
		case 0: {
			eins = fopen("1.txt", "w");
			int minbereich = 4;
			int maxbereich = max/4;
			for (int j = minbereich; j < maxbereich; j++) {
				int zwilling = (prim(j-2) + prim(j));
				if (zwilling == 2) {
					fprintf(eins, "(%i, %i)\n", j-2, j);
				}
			}
			fclose(eins);
                    	break;
		}
		//groesser 0, ist PID von Kindprozess, wir befinden uns im Elternprozess
		default: {
			//ZWEITER KINDPROZESS
        		erg = fork();
        		//Rückgabewert von fork analysieren
        		switch (erg){
        			//Im Fehlerfall
                			case -1: {
                        		//kindprozess wurde nicht erstellt, fehlermeldung erfolgt
                        		printf("Error: Fehler beim erstellen des Childprozesses");
                        		break;
                		}
                		//Wenn 0, sind wir im Kindprozess
                		case 0: {
                		        zwei = fopen("2.txt", "w");
                		        int minbereich = max/4;
                		        int maxbereich = max/2;
                		        for (int j = minbereich; j < maxbereich; j++) {
                		                int zwilling = (prim(j-2) + prim(j));
                		                if (zwilling == 2) {
                        		                fprintf(zwei, "(%i, %i)\n", j-2, j);
                        		        }
                       			}
                        		fclose(zwei);
                        		break;
                		}
               		 	//groesser 0, ist PID von Kindprozess, wir befinden uns im Elternprozess
                		default: {
					//DRITTER KINDPROZESS
		                        erg = fork();
                		        //Rückgabewert von fork analysieren
                		        switch (erg){
                                		//Im Fehlerfall
                                        	case -1: {
                                        		//kindprozess wurde nicht erstellt, fehlermeldung erfolgt
                                        		printf("Error: Fehler beim erstellen des Childprozesses");
                                        		break;
                                		}
                                		//Wenn 0, sind wir im Kindprozess
                                		case 0: {
                                        		drei = fopen("3.txt", "w");
                                        		int minbereich = max/2;
                                        		int maxbereich = (max/4)*3;
                                        		for (int j = minbereich; j < maxbereich; j++) {
                                        	        	int zwilling = (prim(j-2) + prim(j));
                                        	        	if (zwilling == 2) {
                                        	        	        fprintf(drei, "(%i, %i)\n", j-2, j);
                                        	        	}
                                        		}
                                        		fclose(drei);
                                        		break;
                                		}
                                		//groesser 0, ist PID von Kindprozess, wir befinden uns im Elternprozess
                                		default: {
							//VIERTER KINDPROZESS
				                        erg = fork();
                        				//Rückgabewert von fork analysieren
                        				switch (erg){
                                				//Im Fehlerfall
                                        			case -1: {
                                        				//kindprozess wurde nicht erstellt, fehlermeldung erfolgt
                                        				printf("Error: Fehler beim erstellen des Childprozesses");
                                        				break;
                                				}
                                				//Wenn 0, sind wir im Kindprozess
                                				case 0: {
                                        				vier = fopen("4.txt", "w");
                                        				int minbereich = (max/4)*3;
                                        				int maxbereich = max;
                                        				for (int j = minbereich; j <= maxbereich; j++) {
                                                				int zwilling = (prim(j-2) + prim(j));
                                                				if (zwilling == 2) {
                                                        				fprintf(vier, "(%i, %i)\n", j-2, j);
                                                				}
                                        				}	
                                        				fclose(vier);
                                        				break;
                                				}
                                				//groesser 0, ist PID von Kindprozess, wir befinden uns im Elternprozess
                                				default: {
                                        				//schaut, dass Kindprozess nicht zum Zombie wird
                                        				wait(NULL);
                                        				break;
                                				}
                        				}
                                        		//schaut, dass Kindprozess nicht zum Zombie wird
                                        		wait(NULL);
                                        		break;
                                		}
                        		}
                        		//schaut, dass Kindprozess nicht zum Zombie wird
                        		wait(NULL);
                        		break;
                		}
        		}
			//schaut, dass Kindprozess nicht zum Zombie wird
               		wait(NULL);
                   	break;
		}
      	}
	return(0);
}
