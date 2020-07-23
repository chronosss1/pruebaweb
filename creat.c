#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CWD_SIZE 200

int cmd_start (int argc, char ** argv){
    if (argv[1]==NULL){
		printf("creat: Missing operand");
	}else{
		if (creat(argv[1],0777) == -1)
			perror("Error:couldn`t create the directory");
	}
    return 0;
}