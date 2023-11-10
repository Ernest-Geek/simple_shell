#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t Read;
    pid_t pid;
    int status;

    while (1) {
        // Display prompt and wait for user input
        printf("shell$ ");
        Read = getline(&line, &len, stdin);
        if (Read == -1) {
            printf("EOF encountered\n");
            break;
        }
        if (line[Read - 1] == '\n')
            line[Read - 1] = '\0';

        // Fork a child process
        pid = fork();
        if (pid == -1) {
            perror("Fork failed");
            break;
        } else if (pid == 0) {
            // Child process
            char *argv[] = {line, NULL};
            execve(line, argv, NULL);
            
            // If execve fails, print an error message
            perror("Error");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
        }
    }

    free(line);
    return 0;
}

