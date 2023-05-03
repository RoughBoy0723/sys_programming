#include <stdio.h>

int myfuntion(char *name){
		printf("\t-->[%s]\n",name);
		return(123);
}

int main(){
		int i,a;
		int (*fp)(char*);

		fp = myfuntion;

		i = (*fp)("This");
		printf("%d\n",i);
}
