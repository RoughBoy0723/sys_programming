#include "namedPipe.h"

int main(int argc, char *argv[]){
		int fdpub, fdpriv,n, fd;
		char f_name[20];
		char line[LINESIZE];

		strcpy(f_name, argv[1]);

		mknod(PUBLIC,S_IFIFO|0666, 0);

		fd= open(f_name,O_RDONLY);

		if((fdpub = open(PUBLIC, O_WRONLY)) == -1 ){
				perror(PUBLIC);
				exit(2);
		}

		while((n = read(fd, line, LINESIZE))>0){
				write(fdpub,line,n);
		}
		close(fd);
		close(fdpub);
		exit(0);
}

