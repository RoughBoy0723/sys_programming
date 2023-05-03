#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
				if(fork() == 0)
								execl("/bin/echo","/bin/echo","this is","message one",(char*) 0);
				if(fork() == 0)
								execl("/bin/echo","/bin/echo","this is","message two",(char*) 0);

				printf("parent:waiting for chileren\n");
				while(wait((int*)0) != -1)
								;
				printf("parent: all children terminated\n");
				exit(0);
}
