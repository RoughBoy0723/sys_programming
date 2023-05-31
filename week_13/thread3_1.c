#include <stdio.h>
#include <pthread.h>

#define NTHREADS 5

int counter = 0;

void *thread(void *dummy){
		printf("Thread number %ld\n",pthread_self());
		counter++;
}

void main(){
		pthread_t t_id[NTHREADS];
		int i,j;

		for(i = 0 ; i < NTHREADS ;i++){
				pthread_create(&t_id[i],NULL,thread,NULL);		
		}
		/*
		for(j = 0 ; j < NTHREADS ; j++){
				pthread_join(t_id[j],NULL);
		}
		*/
		printf("Final counter value : %d\n",counter);
}
