#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints all arguments it receives.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int i;
	int j;
	int result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	result = i * j;

	printf("%d\n", result);
	return (0);
}
