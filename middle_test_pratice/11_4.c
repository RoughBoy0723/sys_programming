#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]){
    int pid;
    if((pid = fork()) == 0){
        printf("Hello, World\n");
        exit(10);
    }else{
        wait((int *) 3);
        printf("%d", pid);
        exit(0x00);
    }

}
