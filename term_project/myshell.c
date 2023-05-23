#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <signal.h>

#define LBUF 1024

void log_write(char* str_read,int fd, time_t timer){
		char buf[LBUF];
		strcpy(buf,ctime(&timer));
		strtok(buf,"\n");
		strcat(buf," : ");
		strcat(buf,str_read);
		write(fd, buf, strlen(buf));
}

void sigint_handler(int sig){
}
int main(int argc, char *argv[]){
		time_t timer = time(NULL);
		char* path[4] = {"","/bin/","/usr/bin/","/usr/local/bin/"};
		int fd = open(".cmd_log",O_WRONLY|O_CREAT|O_APPEND,0666);
		
		char buf[LBUF];
		strcpy(buf,ctime(&timer));
		strtok(buf,"\n");
		strcat(buf," : ");
		strcat(buf, "shell - start\n");
		write(fd, buf, strlen(buf));

		while(1){
				signal(SIGINT, sigint_handler);
				int cnt = 0; 
				int i = 0;
				char str_read[LBUF];
				memset(str_read,0, LBUF* sizeof(char));
				char* str_arr[20];
				memset(str_arr,0,20 * sizeof(char));
				fputs("oh@");
				fgets(str_read,LBUF,stdin);

				log_write(str_read, fd, timer);

				if(strlen(str_read) == 0){
						continue;
				}

				char* arr = strtok(str_read," ");
				

				while(arr != NULL){
						
						str_arr[cnt] = arr;
						
						arr = strtok(NULL," ");
						cnt++;
				}

				strtok(str_arr[cnt-1],"\n");

				char test_str[30];
                memset(test_str,0, sizeof(test_str));
                int t = 0;

                for(int i = 0; i < 4 ; i++){
						if(!strcmp(str_arr[0],"cd")){
								t=1;
								chdir(str_arr[1]);
						}
						strcpy(test_str, path[i]);
						strncat(test_str, str_arr[0],sizeof(str_arr[0]));
						strtok(test_str,"\n");
						if(access(test_str,F_OK) == 0){
								t = 1;
								if(fork() == 0 ){
										execv(test_str, &str_arr[0]);
								}else{
										wait((int*)0);
								}
						}
				}
				if(t == 0){
						printf("Command not found\n");
				}
        }
}
