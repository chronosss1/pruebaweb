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
