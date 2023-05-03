#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
				char *new_argv[] = {"/bin/ls","-l",(char *)NULL};
				printf("execv() test program!!!\n");
				execv("",new_argv);
				perror("execv() :");
				exit(0);
}
