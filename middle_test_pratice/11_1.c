#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd1;
    char buf[256];

    fd1 = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666);
    
    while(1){
        scanf("%s", buf);
        if(buf[0] == '.')
            break;
        write(fd1, buf, sizeof(buf));
    }
}
