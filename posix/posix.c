#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main(void) {
	char path[PATH_MAX];
	printf(" %i\n", getpid());
	printf(" %i\n", getppid());
	printf(" %i\n", getuid());
	printf(" %i\n", geteuid());
	getcwd(path, sizeof(path));
	printf(" %s\n", path);
	sleep(5);
	return(0);
}
