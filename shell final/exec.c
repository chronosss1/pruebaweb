#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int cmd_start(int argc, char ** argv){
	pid_t hijo;
	if (argv[1] != NULL ){
		if ((hijo = fork() )== 0){
			execvp(argv[1],argv + 1);
			return 0;
		}
		waitpid(hijo,NULL,0);
		return 0;
	}
	else return -1;
}