#include "search_algos.h"
#include <stdio.h>


/**
 * print_array - print an array from a start to end index
 * @array: array to print
 * @start: index to start at
 * @end: index to end at
 * Return: void
 */
void print_array(int *array, size_t start, size_t end)
{
	if (!array)
		return;

	while (start < end)
		printf("%i, ", array[start++]);

	printf("%i\n", array[start]);
}

/**
 * binary_search - find a value in an array using binary search
 * @array: array of integer values
 * @size: size of the array
 * @value: integer value to find
 * Return: index of the value found
 */
int binary_search(int *array, size_t size, int value)
{
	size_t low, mid, high;

	if (!array)
		return (-1);

	low = 0;
	high = size - 1;
	mid = low + (high - low) / 2;

	while (low <= high)
	{
		printf("Searching in array: ");
		print_array(array, low, high);

		if (low == high)
		{
			if (array[low] == value)
				return (low);
			else
				return (-1);
		}

		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return (mid);

		mid = low + (high - low) / 2;
	}

	return (-1);
}

/**
 * exponential_search - find a value in an array using exponential search
 * @array: array of integer values
 * @size: size of the array
 * @value: integer value to find
 * Return: index of the value found
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound, len;
	int index;

	if (!array)
		return (-1);

	bound = 1;

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%i]\n", bound, array[bound]);
		bound *= 2;
	}

	len = bound - (bound / 2);
	printf("Value found between indexes [%lu] and ", bound / 2);
	if (bound >= size)
		printf("[%lu]\n", size - 1);
	else
		printf("[%lu]\n", bound);

	index = binary_search(array + bound / 2, len, value);

	if (index != -1)
		return (index + (bound / 2));

	return (index);
}
