#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    int fd1;
    char buf;
    char *buff[256];
    memset(buff, 0x00, sizeof(buff));
    cnt = 0;
    while(read(fd1, &buf,1)>0){       
        if(buf == ' '){
            cnt++;
        }
        buff[cnt] += &buf;
    }
    for(int i = 0 ; i < cnt, i++){
        if(buff[i] == argv[2]){
            printf("Found\n");
            exit(0);
        }
    }
    printf("NOT Found\n");
    exit(0);
}