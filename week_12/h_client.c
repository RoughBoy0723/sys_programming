#include "namedPipe.h"

int main(int argc, char *argv[]){
		int fdpub,n;
		char cmd[20];

		strcpy(cmd, argv[1]);

		if((fdpub = open(SERVER, O_WRONLY)) == -1 ){
				perror(SERVER);
				exit(2);
		}

		write(fdpub,cmd,strlen(cmd));
		close(fdpub);
		exit(0);
}

