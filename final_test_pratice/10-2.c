#include "pipe.h"

void sigint(int sig){
		printf("SIGINT\n");
}

void sigquit(int sig){
		printf("SIGQUIT\n");
		exit(1);
}

int main(){
		char buf[512];
		int n;
		signal(SIGINT,sigint);
		signal(SIGQUIT,sigquit);
		while((n=read(0,buf,sizeof(buf)))>0)
				write(1,buf,n);
		exit(0);
}
