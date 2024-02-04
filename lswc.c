#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){


    int pfd[2];
    char buf[128] = {0}; 
    
    pipe(pfd);

    pid_t pid = fork(); 

    if (pid == -1) {
        perror("fork");
        return 2;
    }

    if (pid == 0) {
        // this happens in child process
        close(pfd[1]);
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[0]);
        execlp("wc", "wc","-l",(char *) NULL);

    }
        close(pfd[0]); 
        dup2(pfd[1], STDOUT_FILENO);
        execlp("ls", "ls", "-1a",(char *) NULL);
        wait(NULL);
        exit(0);

    return 0;
}