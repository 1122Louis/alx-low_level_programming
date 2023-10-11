#include "search_algos.h"
#include <stdio.h>

/**
 * linear_search - find a value in an array using linear search
 * @array: array of integer values
 * @size: size of the array
 * @value: integer value to find
 * Return: first index of the value found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;
	int found = -1;

	if (!array)
		return (found);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%i]\n", i, array[i]);
		if (array[i] == value)
		{
			found = i;
			break;
		}
	}

	return (found);
}
