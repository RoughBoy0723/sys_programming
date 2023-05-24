#include "namedPipe.h"

int main(int argc, char *argv[]){
		int fdpub, n;
		char line[LINESIZE];

		if((fdpub = open(PUBLIC, O_RDONLY)) == -1 ){
				perror(PUBLIC);
				exit(1);
		}

		while((n = read(fdpub, line, LINESIZE))>0){
				write(1,line,n);
		}
		close(fdpub);
}

