#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>


int main (void) {
	char * argv[] = { "./test/test.out", NULL};
	pid_t pid;
   	switch (pid = fork ()) {
   		case -1: {
      			printf("error: kein child\n");
      			return -1;
		}
   		case 0: {
			printf("Kind-PID: %i\n", getpid());
                	printf("Kind-PPID: %i\n", getppid());
       			execv("./test/test.out", argv);
			printf("nicht funktioniert?\n");
       			break;
		}
   		default: {
			printf("Parent-PID: %i\n", getpid());
                	printf("Parent-PPID: %i\n", getppid());
       			if (waitpid (pid, NULL, 0) != pid) {
          			printf("error\n");
          			return -1;
       			}
			sleep(10);
		}
   	}
	return(0);
}
