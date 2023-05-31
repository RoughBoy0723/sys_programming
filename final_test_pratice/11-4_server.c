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
    int fdpub;
    char line[256];

    fdpub = open(SERVER,O_RDONLY)

    while(read(fdpub, line, 256)>0){
        if(fork()==0)
            execl(line, line, (char*)0);
    }
    close(fdpub);
}