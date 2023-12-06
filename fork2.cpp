#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    printf("Parent process (PID: %d)\n", getpid());

    //Parent and child execute the same program, same code
    child_pid = fork();
    if (child_pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing same program, same code\n", getpid());
        execlp("./same_program", "same_program", NULL); // Execute the same program
    } else if (child_pid > 0) {
        // Parent process
        wait(NULL); // Wait for the child to finish
    } else {
        perror("fork");
        exit(1);
    }

    //Parent and child execute the same program, different code
    child_pid = fork();
    if (child_pid == 0) {
        // Child process
        printf("Child process (PID: %d) executing same program, different code\n", getpid());
        execlp("./different_program", "different_program", NULL); // Execute a different program
    } else if (child_pid > 0) {
        // Parent process
        wait(NULL); // Wait for the child to finish
    } else {
        perror("fork");
        exit(1);
    }

    printf("Parent process exiting\n");
    return 0;
}

