#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int main(){
		int pid = 0, status = 0;
		if((pid = fork()) == 0){
				execlp("rcv_sig","rcv_sig",(char *)NULL);
				perror("execlp() : ");
				exit(2);
		}else if(pid > 0){
				sleep(2);
				kill(pid, SIGINT);
				printf("[Parent]: Send SIGINT\n");
				wait(&status);
				printf("[Parent]:child killed by parent. [%x]\n",status);
		}
}
