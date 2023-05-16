#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
		execl("ls","ls",(char*)0);
}
