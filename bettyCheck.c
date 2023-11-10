#include <stdio.h>
#include <stdlib.h>
/**
 * main -  Prompts a command for a user to enter.
 *
 * Description - This program prompts the user to enter a command
 * and prints the output. It uses getline to read the users input.
 *
 * Return: An integer
 ***/
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t Read;

	printf("$ ");
	while (1)
	{
		Read = getline(&line, &len, stdin);
		printf("\n");
		break;
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
