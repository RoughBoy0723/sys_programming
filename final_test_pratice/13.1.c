#include "pipe.h"

void func1(){
		printf("control C\n");
}

void func2(){
		printf("control \\");
		exit(1);
}

int main(){
		int n;
		char buf[32];
		signal(SIGINT,func1);
		signal(SIGQUIT,func2);
		while((n=read(0,buf,32))>0)
				write(1,buf,n);
}
