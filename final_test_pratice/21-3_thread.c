#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX 512

void *square(void *arg){
		int x = atoi(arg);
		int *res; 
		res = x*x;
		sleep(1);
		pthread_exit(res);
}

int main(int argc, char *argv[]){
    pthread_t t_id;
	int *res;
    pthread_create(&t_id, NULL , square, argv[1]);
	pthread_join(t_id,(int*)&res);
	printf("Thread returned %d\n",(int*)res);
}
