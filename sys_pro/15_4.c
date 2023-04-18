#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd1, fd2, size;
    char buf[1024];
    memset(buf, 0x00, sizeof(buf));

    fd1 = open(argv[1], O_RDONLY);
		close(0);
		dup(fd1);

    fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC,0666);
    close(1);
		dup(fd2);

    size = read(0,buf,sizeof(buf));
    write(1, buf, size);
}
