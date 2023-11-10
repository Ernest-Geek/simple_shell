#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
/**
 * main - Prompts a user to enter a command
 * Description: Prompts a user to enter a command and read the
 * users command using the getline function
 * Return: Always 0
 **/
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t Read;
	pid_t pid;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		Read = getline(&line, &len, stdin);
		if (Read == -1)
		{
			printf("\n");
			break;
		}
		/**printf("%s", line);**/
		if (line[Read - 1] == '\n')
			line[Read - 1] = '\0';
	pid = fork();
	if (pid == -1)
	{
		perror("Error\n");
	        break;
	}
	else if (pid == 0)
	{
		char *argv[] = {line, NULL};

		execve(line, argv, NULL);
			perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	}
	free(line);
	return (0);
}
