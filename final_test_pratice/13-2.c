#include "pipe.h"

void func1(){
}

void func2(){
		printf("Time out\n");
		exit(0);
}

int main(int argc, char *argv[]){
		signal(SIGINT,func1);
		signal(SIGALRM,func2);
		alarm(atoi(argv[1]));
		while(1)
				;
}
