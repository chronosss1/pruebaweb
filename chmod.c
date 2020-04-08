#include "chmod.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
 	
	void cmdChmod(char *tr[], int i){
		//Faltaria meter la info que printea cuando tecleas chmod --help.
		
		char path[1024];
		getcwd(path,sizeof(path));
		printf("%s\n", path);
	
		if (i==1){
			printf("%s: falta un opereando\n", tr[0]);
			printf("Pruebe '%s --help' para más información.\n", tr[0]);
		}
		
		else if (i==2){
			printf("%s: falta un opereando después de %s\n", tr[0], tr[1]);
			printf("Pruebe '%s --help' para más información.\n", tr[0]);
		}
		
		else if (i==3){
			
			char *ptr;
			chmod(tr[2],strtol(tr[1],&ptr,8));
		}
			
	}
