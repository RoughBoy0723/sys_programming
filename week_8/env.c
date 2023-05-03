#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[]){
				char **ptr;
				int index;
				
				for(index = 0; index<argc; index++){
								printf("argv[%d] : %s\n", index, argv[index]);
				}
				printf("Environment Variables----------\n");

				for(ptr=environ, index = 0; *ptr != 0 ; ptr++, index++){
								printf("argv[%d] : %s\n", index, *ptr);
				}
}
