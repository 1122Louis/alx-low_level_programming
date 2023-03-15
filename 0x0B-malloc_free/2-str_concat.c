#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *str_concat - a function that concatenates two strings.
 *@s1: First string
 *@s2: Second string
 *
 *Return: NULL on failure, the return pointer should point to the new string
 */

char *str_concat(char *s1, char *s2)
{
	char *p;
	int index, len = 0, new_index = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (index = 0; s1[index] ||  s2[index]; index++)
		len++;

	p = malloc(sizeof(char) * len);

	if (p == NULL)
		return (NULL);

	for (index = 0; s1[index]; index++)
		p[new_index++] = s1[index];

	for (index = 0; s2[index]; index++)
		p[new_index++] = s2[index];

	return (p);
}




