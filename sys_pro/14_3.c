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
    close(1);
    open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666);


    printf("Hello, World.\n");
    printf("Test input.\n");
}
