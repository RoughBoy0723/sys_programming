#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int count = 0;

void sigint(int sig){
		printf("interrupt signal\n");
}

void sigquit(int sig){
		exit(19);
}

void func(int sig){
		count++;
		
}


int main(){
		struct itimerval t_val;
		signal(SIGINT,sigint);
		signal(SIGQUIT, sigquit);
		signal(SIGALRM, func);
		
		t_val.it_interval.tv_sec = 2L;
		t_val.it_interval.tv_usec = 5L;
		t_val.it_value.tv_sec = 0L;
		t_val.it_value.tv_usec = 0L;
		
		setitimer(ITIMER_VIRTUAL, &t_val,NULL);
		int pid, stat;
		
		if((pid=fork())==0){
				while(1)
						;
		}
		while(count <= 4)
				;
		kill(pid,SIGQUIT);
		wait(&stat);
		printf("%d",stat);
}
