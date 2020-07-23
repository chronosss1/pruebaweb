#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>


/*void list(char * dir){
	DIR *p;
	struct dirent *d;
	struct stat s;
	char * buf;
	size_t len;
	if ((p = opendir(dir)) == NULL) {    
		perror("Cannot open directory");
		return;
	}
	while ((d = readdir(p)) != NULL) { 
		len = strlen (dir) + strlen (d->d_name) + 2;
		buf = malloc (len);
		snprintf (buf,len,"%s/%s",dir,d->d_name);
		stat (buf,&s);
		printf("%s %ld \n",d->d_name,s.st_size);
	}
}*/

char TipoFichero (mode_t m){
	switch (m&S_IFMT){
		case S_IFSOCK: return 's'; /*socket*/
		case S_IFLNK: return 'l'; /*symbolic link*/
		case S_IFREG: return '-'; /*fichero normal*/
		case S_IFBLK: return 'b'; /*block device*/
		case S_IFDIR: return 'd'; /*directorio*/
		case S_IFCHR: return 'c'; /*char device*/
		case S_IFIFO: return 'p'; /*pipe*/
		default: return '?'; /*desconocido, no deberia aparecer*/
	}
}

char * ConvierteModo (mode_t m){
	char * permisos;
	permisos = (char *) malloc (12);
	strcpy (permisos,"----------");

	permisos[0]=TipoFichero(m);
	if (m&S_IRUSR) permisos[1]='r';
	if (m&S_IWUSR) permisos[2]='w';
	if (m&S_IXUSR) permisos[3]='x';
	if (m&S_IRGRP) permisos[4]='r';
	if (m&S_IWGRP) permisos[5]='w';
	if (m&S_IXGRP) permisos[6]='x';
	if (m&S_IROTH) permisos[7]='r';
	if (m&S_IWOTH) permisos[8]='w';
	if (m&S_IXOTH) permisos[9]='x';
	if (m&S_ISUID) permisos[3]='s';
	if (m&S_ISGID) permisos[6]='s';
	if (m&S_ISVTX) permisos[9]='t';
	return (permisos);
}

void longlist(char *d, struct stat s){
	printf("-%lu %s %lu %s %s %ld %s %s \n",s.st_ino, ConvierteModo(s.st_mode), s.st_nlink, (getpwuid(s.st_uid))->pw_name, (getgrgid(s.st_gid))->gr_name, s.st_size, ctime(&s.st_mtime),d);
}

void shortlist (char *d, struct stat s){
	printf("-%s %ld \n",d,s.st_size);
}

int selfParent(char * name){
	return (!strcmp(name,".") || !strcmp(name,".."));
}

void list (char * dir, int l, int r, int count){
	DIR *p;
	struct dirent *d;
	struct stat s;
	char * buf;
	size_t len;
	int i;
	if ((p = opendir(dir)) == NULL) {    
		perror("Cannot open directory");
		return;
	}
	while ((d = readdir(p)) != NULL) { 
		for (i=0; i<count; i++){
			printf("\t");
		}
		len = strlen (dir) + strlen (d->d_name) + 2;
		buf = malloc (len);
		snprintf (buf,len,"%s/%s",dir,d->d_name);
		stat (buf,&s);
		if (r) {
			if (S_ISDIR(s.st_mode)){
				if (l){
					longlist (d->d_name,s);
				}else{
					shortlist(d->d_name,s);
				}
				if (!selfParent(d->d_name))
					list(buf,l,r, (count+1));
			}else{
				if (l){
					longlist (d->d_name,s);
				}else{
					shortlist(d->d_name,s);
				}
			}
		} else {
			if (!l){
				shortlist(d->d_name,s);
			} else{
				longlist (d->d_name,s);
			}
		}
	}
}

int cmd_start(int argc, char ** argv) {
    int l = 0;
	int r = 0;
	int i;

	for(i = 1;argv[i] != NULL;i++) {
		if (strcmp(argv[i], "-l") == 0) { l = 1;}
		else if (strcmp(argv[i], "-r") == 0) { r = 1;}
		else break;
	}

    if (argv[i]!=NULL){
        list(argv[i], l, r, 0);
    }else{
        list(".", l, r, 0);
    }

	return 0;
}