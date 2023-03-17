#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *string_nconcat - concatenates two strings.
 *@s1: The first String
 *@s2: The second string 
 *@n: is the number of bytes the s2 to concate to s1.
 *@ptr: Pointer to return the address of the the memory block
 *Return: NULL if the pointer fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *ptr;
	unsigned int len = 0, i = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		ptr[len++] = s1[i];

	for (i = 0; s2[i] && i < n; i++)
		ptr[len++] = s2[i];

	return (ptr);
}
