#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(fork() == 0){
        close(1);
        open(argv[1], O_WRONLY);
        printf("[%d], [%d], [%d]",getppid(), getuid(), getgid());
    }else{
        printf("[%d], [%d], [%d]",getpid(), geteuid(), getegid());
    }
}
