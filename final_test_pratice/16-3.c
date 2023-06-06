#include "pipe.h"

int main(int argc, char *argv[]){
		int fd[2];
		char buf[1024];
		pipe(fd);

		if(fork()==0){
				close(fd[0]);
				write(fd[1],argv[1],strlen(argv[1]));
				close(fd[1]);
		}else{
				close(fd[1]);
				int n = read(fd[0],buf,1024);
				close(fd[0]);
				write(1,buf,n);
		}
		exit(1);
}
