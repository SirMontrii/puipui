#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid;
    pid = fork();
    if(pid < 0) {
        printf("\nError\n");
        exit(1);
    } else if(pid == 0) {
        printf("\rHello, I am the child process. My PID is %d\n", getpid());
        exit(0);
    } else if(pid > 0) {
        printf("\rHello, I am the parent process. My actual PID is %d\n", getpid());
        wait(NULL);
        exit(1);
    }
    return 0;
}
