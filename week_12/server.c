#include "namedPipe.h"

int main(int argc, char *argv[]){
		int fdpub, fdpriv, fd, n, i;
		struct message msg;
		char line[LINESIZE];

		mknod(PUBLIC,S_IFIFO|0666, 0);

		if((fdpub = open(PUBLIC, O_RDONLY)) == -1 ){
				perror(PUBLIC);
				exit(1);
		}
		loop:
		while(read(fdpub, (char *)&msg, sizeof(msg))>0){
				printf("client request arrived.\n");
				if((fd=open(msg.filename, O_RDONLY)) == -1){
						perror(msg.filename);
						break;
				}
				for(i = 0 ; i < NUMTRIES ; i++ ){
						if((fdpriv = open(msg.privfifo, O_WRONLY|O_NDELAY)) == -1){
								sleep(1);
						}else{
								break;		
						}
				}
				if(fdpriv == -1){
						perror(msg.privfifo);
						break;
				}
				while((n = read(fd, line, LINESIZE))>0){
						write(fdpriv,line,n);
				}
				close(fd);
				close(fdpriv);
		}
		goto loop;
}

