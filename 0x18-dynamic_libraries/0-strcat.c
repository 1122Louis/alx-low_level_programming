#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int string1;
	int string2;

	string1 = 0;
	while (dest[string1] != '\0')
	{
		string1++;
	}
	string2 = 0;
	while (src[string2] != '\0')
	{
		dest[string1] = src[string2];
		string1++;
		string2++;
	}

	dest[string1] = '\0';
	return (dest);
}

