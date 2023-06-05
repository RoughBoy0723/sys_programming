#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *print(void *arg){
    printf("This is thread\n");
    sleep(1);
	return(0);
}

int main(){
    pthread_t t_id;
    int *res;
    pthread_create(&t_id,NULL,print,NULL);
    pthread_join(t_id,NULL);
    printf("OK\n");
	exit(0);
}
