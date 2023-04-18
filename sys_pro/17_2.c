#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int fd1, fd2;
    char buf;
    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[3],O_WRONLY|O_TRUNC|O_CREAT,0666);

    while(read(fd1,&buf,1)>0){
        buf = buf + 3;
        write(fd2,&buf,1);
    }
		lseek(fd2, -1, SEEK_END);
    write(fd2, " ",1);
    close(fd1);
    close(fd2);
}
