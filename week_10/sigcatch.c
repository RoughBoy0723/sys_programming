#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void child(int sig){
		printf("Childe : signal occured.\n");
}

void parent(int sig){
		printf("Parent : signal occured.\n");
}

int main(){

		if(fork() == 0){
				signal(SIGQUIT,child);
				while(1)
						sleep(1);
		}
		signal(SIGQUIT, parent);
		while(1)
				sleep(1);
}
