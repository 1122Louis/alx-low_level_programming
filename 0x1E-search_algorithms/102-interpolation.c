#include "search_algos.h"
#include <stdio.h>

/**
 * interpolation_search - find a value in an array using interpolation search
 * (root of 2 as jump step)
 * @array: array of integer values
 * @size: size of the array
 * @value: integer value to find
 * Return: first index of the value found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t high, low, pos;
	int found = -1;

	low = 0;
	high = size - 1;

	if (!array)
		return (found);

	while (array[high] != array[low])
	{
		pos = low + (((double)(high - low) / (array[high] - array[low])) *
			(value - array[low]));

		if (value >= array[low] && value <= array[high])
		{
			printf("Value checked array[%lu] = [%i]\n", pos, array[pos]);
		}
		else
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			break;
		}

		if (array[pos] < value)
			low = pos + 1;
		else if (value < array[pos])
			high = pos - 1;
		else
			return (pos);
	}

	if (value == array[low])
		return (low);
	else
		return (-1);
}
