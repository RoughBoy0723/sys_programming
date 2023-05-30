#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 512

int main(int argc, char *argv[]){
    int fd;
    char buf[MAX];
    fd = open(argv[1], O_RDONLY, (char*) 0);
    lseek(fd,atoi(argv[2]) ,SEEK_SET);
    
    read(fd,buf,atoi(argv[3]));
    printf("%s",buf);
}