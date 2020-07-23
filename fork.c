#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void cmd_start(int argc, char ** argv) {
	pid_t pid;
	(pid =fork());
	if ( pid == -1)
		perror("Error:");
	else
		waitpid(pid,NULL,0);
}