#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void func(){
    printf("timeout\n");
    exit(1);
}

int main(int argc, char *argv[]){
    signal(SIGALRM,func);
    alarm(atoi(argv[1]));
	while(1)
			;
}
