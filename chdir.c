#include "chdir.h"

void chcwd(char * path){
	if(path == NULL){
		char cwd[1024];
		getcwd(cwd,sizeof(cwd));
		printf("%s\n",cwd);
	}else
		if(chdir(path) != 0)
			printf("%s\n", "Imposible cambiar directorio: No such file or directory");
}