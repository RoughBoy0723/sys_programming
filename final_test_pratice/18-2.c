#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int sigint(int sig){
		printf("interrupt signal\n");
}

int sigquit(int sig){
		exit(19);
}

int alarm(int sig){
		
		
}


int main(){
		struct itimerval t_val;
		signal(SIGINT,sigint);
		signal(SIGQUIT, sigquit);
		signal(SIGALRM, alarm);
		t_val.it_interval.tvusec = 2.5L;

		int pid, stat;
		
		if((pid=fork())==0){
				while(1)
						;
		}


		wait(&stat);
		printf("%d",stat);
}
