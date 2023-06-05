#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <pthread.h>

#define MAX 512

void *squ(void *arg){
		int x = atoi(arg);
		int res = x*x; 
		pthread_exit((void *)res);
}

int main(int argc, char *argv[]){
    pthread_t t_id;
	int *res;
    pthread_create(&t_id, NULL , squ, argv[1]);
	pthread_join(t_id,(void**)&res);
	printf("Thread returned %d\n",res);
}
