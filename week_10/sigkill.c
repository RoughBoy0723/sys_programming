#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void child(int sig){
		printf("Childe : signal [%d] occured.\n",sig);
}

int main(){
		int childPid;
		if((childPid = fork()) == 0){
				signal(SIGQUIT,child);
				while(1)
						sleep(1);
		}
		sleep(2);
		kill(childPid,SIGQUIT);
}
