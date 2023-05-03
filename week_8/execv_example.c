#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
				char *new_argv[] = {"diffName","p1","p2",(char *)NULL};
				printf("execv() test program!!!\n");
				execv("./default_envp",new_argv);
				perror("execv() :");
				exit(0);
}
