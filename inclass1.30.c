#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>

int main(void) {

    int fd = open("foo.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }
    char *s = pid == 0? "C":"P";

    // if (pid ==0)  as above^^
    //     s="c"?
    // else
    //     s = "p";

    for (int i = 0; i < 10000; i++) {
        write(fd, s, 1);
    }
    close(fd);

    
    //  if (pid == 0) {
    //     // this happens in child process
    //     lseek(fd,0, 10000);
    //     write(d, "P", 10000);
    //     exit(0);
    // }
    // lseek(fd,0, 10000);
    // write(fd, "Qs", 10000);
    // wait(NULL);



}