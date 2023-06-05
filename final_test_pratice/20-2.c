#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
		int fd;
		char *path[10];

		fd = open(argv[argc-1],O_WRONLY|O_CREAT|O_TRUNC,0655);

		for(int i = 0 ; i < argc-2 ; i++){
				path[i] = argv[i+1];
				path[i+1] = "\0";
		}
		close(1);

		char *dest = path[0];

		if(fork() ==0){
				dup(fd);
				execv(dest,&path[0]);
		}
		wait(0);
		exit(1);
}
