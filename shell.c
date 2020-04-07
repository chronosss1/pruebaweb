#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/mman.h>
#include <ctype.h>
#include <sys/wait.h>

#include "provisional.h"

/*************************************************************************************************/

#define MAXLINE 2048
#define MAXNAME 1024
#define MAXARRAY 4096

struct COMMAND{
	char *name;
	void(*pfunc)(char *tr[]);
};

void CmdCdir(char * tr[]){
	if (tr[0] == NULL)
		printf("%s\n", getcwd(tr[0],MAXNAME));
	else
		if (chdir(tr[0])==-1)
			perror("Cannot change directory");
}

void CmdPid (char *tr[]){
	if (tr[0] !=NULL && strcmp(tr[0],"-p")==0)
		printf("parent proces pid %d\n",getpid());
	else
		printf("process pid: %d\n",getpid());
}

void CmdFecha (){
	time_t t;
	struct tm *tm;
	char date[100];

	t=time(NULL);
	tm=localtime(&t);
	if (t && tm){
		strftime(date,100,"%d / %m / %Y",tm);
		printf("Today is %s\n",date);
	}else {perror("error, time couldn`t be collected");}
}

void CmdExit(){
	exit(0);
}

void CmdHora (){
	time_t t;
	struct tm *tm;
	char date[100];

	t=time(NULL);
	tm=localtime(&t);
	if (t && tm){
	strftime(date,100,"%H:%M:%S",tm);
	printf("It is %s\n",date);}
	else {perror("error, time couldn`t be collected");}
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

void CmdDup(char * tr[]){
	int i;
	if ((i = atoi(tr[0]) != 0))
		dupNuevo(i);

}


struct COMMAND cmd []={
	{"pid",CmdPid},
	{"cdir",CmdCdir},
	{"fecha",CmdFecha},
	{"hora",CmdHora},
	{"date",CmdFecha},
	{"time",CmdHora},
	{"fin",CmdExit},
	{"end",CmdExit},
	{"exit",CmdExit},
    /*********************************************************************************************/
    {"dup",CmdDup},
	{NULL,NULL}
};

void ProcessInput (char imp[]){
	char *tr[MAXLINE/2];
	int i;
	if(TrocearCadena(imp, tr)==0){
		return;
	}
	for (i=0; cmd[i].name!=NULL;i++){
		if (strcmp(tr[0],cmd[i].name)==0){
			(*cmd[i].pfunc)(tr+1);
			return;
		}
	}
	CmdNotFound(tr); //antes: CmdNotFound(tr);
}


int main (int argc, char *argv[]){
	int i;
	char input[MAXLINE];
	for (i=0; i<argc; i++)
		printf("main's %dth argument value in: %s\n",i,argv[i]);

	while (1){
		printf("#) ");
		//printf("%lu",sizeof(struct node)); 56
		fgets (input,MAXLINE,stdin);
		ProcessInput (input);
	}
}