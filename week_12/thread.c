#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

void * threadFunc(void *arg){
		char *s = (char* ) arg;
		printf("%s\n",s);
		return((void *) strlen(s));
}

int main(){
		pthread_t t_id;
		int res, s;

		if(pthread_create(&t_id, NULL , threadFunc, "Hello World\n") != 0)
				printf("pthread_creat error\n");

		printf("message from main()\n");

		if(pthread_join(t_id, (void**)&res) != 0)
				printf("phread_join error\n");

		printf("Thread returnde %d\n", res);
		exit(EXIT_SUCCESS);
}
