#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

int main(int argc, char* argv[]){

    pid_t pid = fork(); 
    if (pid == 0) {
        int fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
        dup2(fd, STDOUT_FILENO);
        close(fd);
        execvp(argv[2], &argv[2]);
    }
    return 0;
}