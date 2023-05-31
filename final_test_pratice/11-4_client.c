#include "pipe.h" 

int main(int argc, char  *argv[]){

		int fdpub;
		char line[LINESIZE];
		
		mknod(SERVER,S_IFIFO|0666, 0);

		if((fdpub = open(SERVER,O_WRONLY)) == -1){
				perror(SERVER);
				exit(1);
		}

		write(fdpub, argv[1], sizeof(argv[1])); 
		close(fdpub);
		exit(0);
}
