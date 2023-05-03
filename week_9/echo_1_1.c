#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void f (int sigNum){
}

int main(){
		signal(SIGINT, f);
		while(1){
				sleep(1);
		}
}
