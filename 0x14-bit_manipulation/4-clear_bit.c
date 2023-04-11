#include <stdio.h>
#include "main.h"

/**
 * clear_bit - sets bit to 0 at given index
 * @n: pointer to unsigned long int
 * @index: index to set to 0
 *
 * Return: 1 if succeed -1 if failed
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int mask;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	mask = ~(1 << index);
	*n &= mask;

	return (1);
}
