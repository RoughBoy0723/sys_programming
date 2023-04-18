#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int fd1, count;
    char buf[512];

    fd1 = open(argv[1], O_RDWR|O_CREAT|O_TRUNC,0666);
    close(1);
    dup(fd1);

    while((count = read(0, buf,512))>0){       
        buf[count] = 0;
        printf("%s",buf);
    }
}
