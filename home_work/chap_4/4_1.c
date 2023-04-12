#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
		int pid;
		
		if((pid = fork()) == 0 ){
				execl("/bin/ls", "ls","-l",(char*)0);
				exit(0);
		}else{
				wait((int*)1);

		}	

		
}
