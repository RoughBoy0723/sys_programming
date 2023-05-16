#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define LBUF 1024

int new_arr(char* fir, char* arr[], int len);

int main(int argc, char *argv[]){
		char* path[4] = {"","/bin/","/usr/bin/","/usr/local/bin/"};
		char str_read[LBUF] = {0,};
		char *str_adr = str_read;
		char str_opt[20]={0,};
		while(1){
				int i = 0;
				int j = 0;

				memset(str_read,0, LBUF* sizeof(char));
				memset(str_opt,0,20 * sizeof(char));

				fgets(str_read,LBUF,stdin);

				if(strlen(str_read) == 0){
						continue;
				}
				
				char str_path[20];
				memset(str_path, 0, 20*sizeof(char));

				while(*(str_adr+i) != ' '){
						str_path[j] = *(str_adr+i);
						i++;
						j++;
				}

				j=0;
				i++;
				
				while(*(str_adr+i) != '\n'){
						str_opt[j] = *(str_adr+i);
						j++;
						i++;
				}
				
				char test_str[30];
				memset(test_str,0, sizeof(test_str));
				int t = 0;

				for(int i = 0; i < 4 ; i++){
						if(!strcmp(path[i],"cd")){
								chdir(str_opt);
								break;
						}
						strcpy(test_str, path[i]);
						strcat(test_str, str_path);
						strtok(test_str,"\n");
						if(access(test_str,F_OK)== 0){
								t =1;
								if(fork() == 0 ){
										if(str_opt[0] == '\0'){
												execl(test_str,test_str,(char*) 0);
										}else{
												execl(test_str,test_str, str_opt,(char *)0);
										}
								}else{
										wait((int*)0);
								}						
						}
				}
				if(t == 0){
						printf("Command Not Found\n");
				}
		}
}

