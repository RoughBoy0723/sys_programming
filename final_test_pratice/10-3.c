#include "pipe.h"

void func(){
		printf("Time out!!\n");
		exit(1);
}

int main(int argc, char *argv[]){
		signal(SIGALRM,func);
		alarm(atoi(argv[1]));
		while(1)
				;
}
