#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *func(void *data){
		while(1){
				printf("Speaking from the detached thread...\n");
				sleep(3);
		}
}

void main(){
		pthread_t t_id;

		if(!pthread_create(&t_id,NULL,func,NULL))
				printf("Thread created successfully!!!\n");

		sleep(2);
		printf("Main thread dying...\n");
		pthread_exit((void *)0);
}
