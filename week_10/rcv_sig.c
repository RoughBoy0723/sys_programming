#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void sigint_sighandler(int);

int main(){
		int i = 0;

		for(i=1 ; i < 10 ; i++ ){
				printf("\t[child] sleep count #%d\n",i);
				sleep(1);
		}
		printf("\t[child] process terminate !");
		exit(0);
}

void sigint_sighandler(int sig){
		printf("\t[child] receive SIGINT\n");
		exit(25);
}
