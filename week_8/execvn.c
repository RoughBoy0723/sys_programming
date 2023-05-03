#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(){
				static char *new_argv[] = {"new_pgm","p1","p2",(char*) NULL};
				static char *new_envp[] = {"USER = TESTER","HOME=/TEST_DIR","TESTSTRING= execl() test"};
				printf("execve() test program!!!\n");
				execve("./default_envp",new_argv, new_envp);
				perror("execve() :");
				exit(0);
}
