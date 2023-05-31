#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd;
    fd = open(argv[2],O_RDONLY|O_CREAT|O_TRUNC,0666);
    close(1);
    dup(fd);
    execl(argv[1],argv[1],(char *)0);
    close(fd);
}