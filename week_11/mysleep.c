#include <stdio.h>
#include <signal.h>
#include <setjmp.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int);
void sigalrm_handler(int);
int mysleep(int);

int main(int argc, char* argv[]){
		int ret = 0;
		signal(SIGINT, sigint_handler);
		ret = mysleep(atoi(argv[1]));
		printf("remaining time : %d\n",ret);
		exit(0);
}

void sigint_handler(int signum){
		if(signum == SIGINT)
				printf("Receive SIGINT signal\n");
}

void sigalrm_handler(int signum){
		printf("Receive SIGALRM signal\n");

}

int mysleep(int sec){
		int remain_sec = 0 ;
		void *old_set;
		old_set = signal(SIGALRM,sigalrm_handler);
		alarm(sec);
		pause();

		remain_sec = alarm(0);
		signal(SIGALRM, old_set);
		return remain_sec;
}
