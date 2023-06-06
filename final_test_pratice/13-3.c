#include "pipe.h"


int pid;

void func(){
		kill(pid,SIGQUIT);
		exit(1);
}

int main(int argc, char *argv[]){
		signal(SIGALRM,func);
		if((pid = fork())==0){
				execl(argv[1],argv[1],(char*)0);
		}
		alarm(atoi(argv[2]));
		if(wait((int*)0) > 0)
				exit(1);
}
