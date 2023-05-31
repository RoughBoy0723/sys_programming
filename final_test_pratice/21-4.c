#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void read2line(char *line){
    while(read(0,line,1) != '\n'){
    }
}

int main(){
    int fd[2];
    pipe(fd);

    //첫번째 ls -l
    if(fork() == 0){
        close(1);
        dup(fd[1]);
        close(fd[0]);
        close(fd[1]);
        execl("/bin/ls","/bin/ls","-l",(char *)0);
        exit(127);
    }
    //두번째 grep data
    if(fork() == 0){
        close(0);
        dup(fd[0]);
        close(fd[0]);
        close(fd[1]);
        execl("/bin/grep","/bin/grep","data",(char *)0);
        exit(128);
    }
    
    close(fd[0]);
	close(fd[1]);
	while(wait((int *)0) != -1)
		;
	exit(0);
}
