#include "pipe.h"

int i=0,j=0;

void sigint(int sig){
		i++;
}

void sigquit(int sig){
		j++;
}

void sigalrm(){
		printf("Time out!!\n");
		printf("SIGINT : %d\n",i);
		printf("SIGQUIT : %d\n",j);
		exit(1);
}

int main(int argc, char *argv[]){
		char buf[512];
		int n,fd;
		fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);
		signal(SIGALRM,sigalrm);
		signal(SIGINT,sigint);
		signal(SIGQUIT,sigquit);
		alarm(atoi(argv[2]));
		
		while((n=read(0,buf,sizeof(buf)))>0){
				write(fd,buf,n);
		}
		exit(0);
}
