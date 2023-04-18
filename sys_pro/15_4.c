#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd1;
    char buf;

    if(fd1 = open(argv[1], O_RDONLY)<0){
        stderr("error\n");
        exit(0);
    }
    close(1)
    open(argv[2], O_WRONLY|O_CREAT|O_TRUNC,0666);

    while(read(fd1,buf,1)>0){
        write(1,buf,1);
    }
    close(fd1);
}