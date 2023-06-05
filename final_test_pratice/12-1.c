#include "pipe.h"


int pid;
int i;

void sigalrm(int sig){
		kill(pid,SIGQUIT);
		i++;
}

int main(int argc, char *argv[]){
		signal(SIGALRM, sigalrm);
		alarm(atoi(argv[2]));
		if((pid =fork()) == 0){
				execl(argv[1],argv[1],(char*)0);
		}
		wait((int*)0);
		if(i > 0){
				printf("Parent : chiled killed after %d second\n",atoi(argv[2]));
		}else{
				printf("Parent :  chiled exit within %d second\n",atoi(argv[2]));
		}
		exit(0);


}
