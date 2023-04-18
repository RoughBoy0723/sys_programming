#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int fd1;
    char buf;

    close(1)
    fd1 = open(argv[1], O_WRONLY);
    
    while((count = read(fd1, &buf,1))>0){       
        buf[count] = 0;
        printf("%s",buf);
    }
    exit(0);
    close(fd1);
}