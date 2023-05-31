#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int fd1;
    char buf;
    close(0);
    open(argv[1], O_RDONLY);

    while(scanf("%c",&buf)>0){
        printf("%s",&buf);
    }
    close(fd1);
}
