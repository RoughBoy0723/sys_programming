#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define LBUF 1024

int main(int argc, char *argv[]){
		char* path[4] = {"","/bin/","/usr/bin/","/usr/local/bin/"};
		while(1){
				int cnt = 0; 
				int i = 0;
				char str_read[LBUF];
				memset(str_read,0, LBUF* sizeof(char));
				char* str_arr[20];
				memset(str_arr,0,20 * sizeof(char));
				fgets(str_read,LBUF,stdin);				
				if(strlen(str_read) == 0){
						continue;
				}
				char* arr = strtok(str_read," ");
				

				while(arr != NULL){
						
						str_arr[cnt] = arr;
						
						arr = strtok(NULL," ");
						cnt++;
				}


				char test_str[30];
                memset(test_str,0, sizeof(test_str));
                int t;
                for(int i = 0; i < 4 ; i++){
						strcpy(test_str, path[i]);
						strncat(test_str, str_arr[0],sizeof(str_arr[0]));
						strtok(test_str,"\n");
						if(access(test_str,F_OK) == 0){
								t = 1;
								printf("0");
								char *str_fin[20];
								printf("1");
								strcpy(str_fin[0], test_str);
								printf("2");
								for(int n = 1 ; n < cnt;n++){
										strcpy(str_fin[n], str_arr[n]);
								}
								printf("3");
								for(int m = 0; m <cnt;m++){
										printf("%s ",str_fin[m]);
								}
								printf("4");
								if(fork() == 0 ){
										execv(str_fin[0], str_fin);
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
