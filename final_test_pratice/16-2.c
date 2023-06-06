#include "pipe.h"

int main(int argc, char *argv[]){

		int fd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);

		if(fork()==0){
				close(1);
				dup(fd);
				execl(argv[1],argv[1],(char*)0);
		}
		wait((int*)0);
		exit(1);
}
