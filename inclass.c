#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int pfd[2];
    char buf[128] = {0}; // initiaizes t 0

    if (pipe(pfd) == -1){
        perror("pipe");
        return 1;
    } 

    close(2);
    printf("pfd[0]  is %d\n", pfd[0]);
    printf("pfd[1]  is %d\n", pfd[1]);

    pid_t pid = fork(); 

    if (pid == -1) {
        perror("fork");
        return 2;
    }
     if (pid == 0) {
        // this happens in child process
        read(pfd[0], buf, 128);
        printf("buf is \"%s\"\n", buf);
        exit(0);

    }

    close(1);
    dup(pfd[1]); 
    // this happens in parent
    // write(1, "Hi there!", 9); // this goes into the pipe
    printf("another test"); //
    fflush(stdout);


    wait(NULL);

}