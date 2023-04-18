#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int fd1;
    char buf;

    fd1 = open(argv[1], O_RDONLY);

    cnt = 0;
    
    while(read(fd1, &buf,1)>0){       
        if(buf == ' '){
            cnt++;
        }
    }
    
    printf("%d",cnt);
    exit(0);
    close(fd1);
}