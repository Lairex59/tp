//Alle includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/**
 * Dieses Projekt ist ein Schulprojekt, welches dazu ist, eine kleine Shell zu
 * programmieren, welche man in der Shell ausführen kann.
 * @author: Ahmed Laraib
 * Klasse: 3IB
 * Datum: 11.04.2021
 * Copyright protected
 */
int main(){
	// Initialisierung der Anzahl der Befehle
	char input[100000];
	char *args[100];
	char befehle[100][100];
	char a;
	int i=0;
	int j=0;
	int k=0;
	int ex;
	int abbruch=0;
        int boolean=0;
	//Wird solange ausgeführe bis der Benutzer nicht exit schreibt, indem man von der Shell rauskommt
  	do{
		for(i=0;i<50;i++){
			for(j=0;j<100;j++){
				befehle[i][j]=0;
			}
			args[i]=befehle[i];
		}
		fgets(input,500,stdin);
		j=0;
		k=0;
		boolean=1;
		abbruch=0;
		for(i=0;i<500&&input[i]!=0&&abbruch==0;i++){
			if(input[i]=='\n'){
				abbruch=1;
			}else
		       	if(input[i]!=' '){
				  befehle[j][k]=input[i];
				  k++;
				  boolean=0;
		 	  }else {
				  if(input[i]==' '&&!boolean){
				        befehle[j][k+1]=0;
				        k=0;
					j++;
					boolean=1;
			 	  }
		          }
		}
		args[j+1]=0;
		//Falls der Benutzer cd schreibt, wird chdir aufgerufen, da es ein eigener Befehl ist
		if(strcmp(args[0],"cd")==0)
			chdir(args[1]);
		else
			//Erstellt Verzeichnis
			if(strcmp(args[0],"mkdir")==0)
				mkdir(args[1],S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
			else{
				//Fork prozess wird erstellt
				int erg=fork();
				switch (erg){
 				case -1:
					printf("Fehler");
					break;
				case 0:
					ex=execvp(args[0],args);
					if(ex=-1&&strcmp(args[0],"exit"))
						printf("Befehl wurde nicht gefunden!\n");
					exit(0);
					break;
				default:
					wait(NULL);
					break;
				}	
			}
	}while(strcmp(args[0],"exit")!=0);
	//Ende der Shell
}
