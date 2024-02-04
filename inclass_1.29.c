#include <stdio.h>
#include <unistd.h>

int main(void) {

    int fd;
    fd  = dup(1);

    printf("duplicate fd is %d\n", fd);

    write(1, "hello\n", 7);
    write(fd, "hello2\n", 8);
}