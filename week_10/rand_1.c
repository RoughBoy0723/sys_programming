#include <stdlib.h>
#include <stdio.h>

int main(){
		srand(getpid());
		printf("%d\n",rand()%100);
		printf("%d\n",rand()%50);
		printf("%d\n",rand()%10);
}
