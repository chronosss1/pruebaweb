# OS-shell-and-API-portal

Para compilar: 

gcc shell.c -ldl -o shell

gcc -fPIC -shared ls.c -o ls.so

gcc -fPIC -shared echo.c -o echo.so

gcc -fPIC -shared cd.c -o cd.so

gcc -fPIC -shared creat.c -o creat.so

gcc -fPIC -shared mkdir.c -o mkdir.so

gcc -fPIC -shared pwd.c -o pwd.so

gcc -fPIC -shared fork.c -o fork.so

gcc -fPIC -shared exec.c -o exec.so

Lista de funciones usadas:

En el código el path para encontrar y abrir las librerias dinámicas estan a nivel local del sistema de archivos donde se programó. Simplemente cambiar eso para adaptarse al sistema de archivos del Sistema Operativo.

Shell:
strcmp -> 0 iguales
otro nº diferentes

strtok

fork -> exito devuleve el pid del hijo
	si es el hijo devuleve 0
	si da error devuelve -1

perror

execv -> return -1 si da error

exit

wait

printf

dlopen -> devuelve un puntero al archivo abierto,
	si no lo consigue abrir devuelve NULL

dlsym -> devuelve el puntero a la dirección donde se ha cargado la función,
	si no  la consigue cargar devuelve NULL

dlerror -> devuelve un string describiendo el error, si no hay error devuelve NULL

strcpy -> devuelve un puntero al string ( nunca usamos lo que devuelve)

strcat -> nos da igual lo que devuelva

getcwd -> (nos da igual lo que devuelva)

malloc -> devuelve el puntero o en caso de que no se cree devuelve NULL

strlen -> devuelve el tamaño del string

fgets -> nos da igual lo que devuelva

sizeof


cd.so:
chdir-> 0 si ben, diferente si mal

pwd.so:
getcwd->non importa código retorno

mkdir.so:
mkdir->-1 error, 0 ben

creat.so:
creat->-1 error, 0 ben

ls.so:
opendir->NULL si mal, puntero si ben
readdir->NULL si mal, puntero si ben
snprintf->retorno non importa
stat->retorno non importa
S_ISDIR->0 si non e directorio, outro si é directorio

fork.so:
fork->retorno pid
waitpid->retorno non importa

exec.so:

execvp -> return -1 si da error
