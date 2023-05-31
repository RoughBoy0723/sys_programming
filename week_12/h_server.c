#include "namedPipe.h"

int main(int argc, char *argv[]){
		int fdpub;
		char line[LINESIZE];
		mknod(SERVER,S_IFIFO|0666, 0);
		if((fdpub = open(SERVER, O_RDONLY)) == -1 ){
				perror(SERVER);
				exit(1);
		}
		while(read(fdpub, line, LINESIZE)>0){
				if(fork() == 0){
						execl(line,line,(char*)0);
				}
		}
		close(fdpub);
}

