#include "pipe.h"

int main(int argc, char  *argv[]){
		int fdpub;
		char line[LINESIZE];

		if((fdpub = open(SERVER,O_RDONLY)) == -1){
				perror(SERVER);
				exit(0);
		}	

		while(1){
				if(read(fdpub, line, LINESIZE)>0){
						if(fork()==0){
						execl(line, line, (char*)0);
						}
				}
		}
		close(fdpub);
}
