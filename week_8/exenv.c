#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(){
				static char *new_envp[] = {"USER = TESTER","HOME=/TEST_DIR","TESTSTRING= execl() test"};
				printf("execl() test program!!!\n");
				execle("~./default_envp","new_pgm","p1","p2",(char *)NULL, new_envp);
				perror("execle() :");
				exit(0);

}
