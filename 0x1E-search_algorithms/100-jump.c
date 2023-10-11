#include "search_algos.h"
#include <stdio.h>
#include <math.h>

/**
 * jump_search - find a value in an array using jump search
 * (root of 2 as jump step)
 * @array: array of integer values
 * @size: size of the array
 * @value: integer value to find
 * Return: first index of the value found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, j;
	int found = -1;
	size_t jump = sqrt(size);

	if (!array)
		return (found);

	/* Jump step */
	for (i = 0; i < size && array[i] < value; i += jump)
		printf("Value checked array[%lu] = [%i]\n", i, array[i]);

	printf("Value found between indexes [%lu] and [%lu]\n", i - jump, i);

	for (j = i - jump; j < size; j++)
	{
		printf("Value checked array[%lu] = [%i]\n", j, array[j]);
		if (array[j] == value)
			return (j);
	}

	return (found);
}
