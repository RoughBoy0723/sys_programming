#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
				printf("execl() test program!\n");
				execl("default_envp","new_pgm","p1","p2",(char *)NULL);
				printf("Execl error\n");
				perror("execl():");
				exit(0);
}
