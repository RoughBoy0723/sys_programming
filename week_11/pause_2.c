#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
		void func(int);
		signal(SIGALRM,func);
		alarm(1);
		int ret = pause();
		printf("ret = [%d]\n",ret);
		fprintf(stderr,"good\n");
}

void func(int signum){
		fprintf(stderr,"in handler.\n");
}
