#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void sighandler(int signo){
    if(signo == SIGINT){
        int fout = open("output.txt",O_CREAT | O_WRONLY | O_APPEND, 0664);
        char msg[100];
		strcpy(msg,"Program exited due to SIGINT\n");
        write(fout,msg,strlen(msg));
        close(fout);
        exit(0);        
    }

    if(signo == SIGUSR1){
        printf("PID of the parent is %d\n",getppid());
    }
}

int main(){

    signal(SIGINT,sighandler);
    signal(SIGUSR1,sighandler);

    while(1){
        printf("The PID is %d\n",getpid());
        sleep(1);
    }

    return 0;

}