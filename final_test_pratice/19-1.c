#include "pipe.h"

struct priv{
		char name[20];
		int age;
};

char buf = '-';

int main(int argc, char *argv[]){
		int fd =  open(argv[1],O_CREAT|O_APPEND|O_WRONLY,0666);
		struct priv p;
		while(1){
				printf("name, age : ");
				scanf("%s %d",p.name, &p.age);

				if(strcmp(&p.name[0],&buf) == 0){
						exit(1);
				}
				write(fd, &p, sizeof(p));
		}
}
