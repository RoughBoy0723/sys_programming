#include <stdio.h>
#include <stlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define SERVER "server"
#define LINESIZE 512
#define NUMTRIES 3

int main(int argc, char  *argv[]){

    int n, fdpub, fdpriv;
    char line[256];

    mknod(SERVER,S_IFIFO|0666, 0);
    //안열리면 오류
    if(fdpub = open(SERVER,O_WRONLY) == -1){
        perror(SERVER);
        exit(1);
    }

    write(fdpub, argv[1], sizeof(argv[1])); 
    close(fdpub);
    exit(0);
}