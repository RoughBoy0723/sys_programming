#include "pipe.h"

void sigint(){
		printf("Contlor C\n");
}

void sigquit(){
		printf("Contlor \\\n");
		exit(1);
}

int main(){
		int n;
		char buf[512];
		signal(SIGQUIT,sigquit);
		signal(SIGINT,sigint);
		while((n = read(0,buf,sizeof(buf)))>0)
				write(1,buf,n);
}
