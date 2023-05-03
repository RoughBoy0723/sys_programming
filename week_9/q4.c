#include <signal.h>
#include <unistd.h>

int main(){
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGKILL, SIG_IGN);

		while(1)
				sleep(1);
}
