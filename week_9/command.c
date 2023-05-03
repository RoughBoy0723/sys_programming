#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void handler (int);

int main(int argc, char* argv[]){
		if(argc<2){
				printf("retry\n");
				exit(1);
		}
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, handler);
		execlp(argv[1],argv[1],(char *)0);
		perror("execlp() : ");
		exit(2);
}

void handler(int sigNum){
		printf("Signal handler.\n");
}
