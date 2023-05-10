#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
		int rand_num;
		srand(getpid());
		rand_num = rand();
		rand_num %= 20;
		printf("\t[child] : sleep random number : %d\n",rand_num);
		sleep(rand_num);
		printf("\t[child] : process terminate!\n");
		exit(0x35);
}
