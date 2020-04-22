#include <stdio.h> //por : printf,perror,stdin
#include <string.h> // por el strok el
#include <unistd.h> //por el execvp y fork
//#include <fcntl.h> //para el dup hará falta
#include <sys/wait.h> //por el waitpid
#include <stdlib.h> //por el exit()

#include "provisional.h"

/*************************************************************************************************/

#define MAXLINE 2048

void CmdExit(){
	exit(0);
}

int TrocearCadena (char * cadena, char * trozos[]){
	int i=1;

	if((trozos[0]=strtok(cadena," \n\t"))==NULL)
		return 0;
	while ((trozos[i]=strtok(NULL," \n\t"))!=NULL)
		i++;
	return i;
}


void CmdNotFound (char * tr[]){
	int i=0;
	while (tr[i]!=NULL){
		printf ("%s ",tr[i]);
		i++;
	}
	printf (" not found \n");
}
/*
void CmdDup(char * tr[]){
	int i;
	if ((i = atoi(tr[0]) != 0))
		dupNuevo(i);

}
*/
void Cmd_exec(char *tr[]){
	if (tr[0] != NULL ){

			execvp(tr[0],tr);
	}
}

int pplano(char *tr[]){
	pid_t p = -1;
	if (tr[0] != NULL ){
		if (*tr[0] == '@') {
			if (tr[1] != NULL){
				if((p=fork()) == -1)
					perror("Error cant fork");
				else if (p == 0) {
				printf("aaa");
					Cmd_exec(tr);
				}
				else waitpid(p,NULL,0);
			}
		}
		else {
			if((p=fork()) == -1)
				perror("Error cant fork");
			else if (p == 0) {
				Cmd_exec(tr);
			}
			else waitpid(p,NULL,0);
		}
	}
	return p;
}	

void Cmd_pplano(char *tr[]){
	pplano(tr);
}

void ProcessInput (char imp[]){
	char *tr[MAXLINE/2];
	if(TrocearCadena(imp, tr)==0){
		return;
	}
	Cmd_pplano(tr);
}


int main (int argc, char *argv[]){
	int i;
	char input[MAXLINE];
	for (i=0; i<argc; i++)
		printf("main's %dth argument value in: %s\n",i,argv[i]);

	while (1){
		printf("#) ");
		fgets (input,MAXLINE,stdin);
		ProcessInput (input);

	}
}