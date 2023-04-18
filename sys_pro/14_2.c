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

    fd1 = open(argv[1], O_WRONLY);

    lseek(fd1, atoi(argv[2]) ,SEEK_SET);
    write(fd1, argv[3], strlen(argv[3]));

    close(fd1);
}
