/*
** EPITECH PROJECT, 2018
** task02
** File description:
** str cat
*/

#include <stdio.h>
#include <stdlib.h>

int	my_strlen(char const*);
char *my_calloc(int);

char *my_strcat(char *dest, char *src)
{
	char *newdest = NULL;

	if (src == NULL)
		return (dest);
	newdest = my_calloc(my_strlen(dest) + my_strlen(src) + 1);
	if (dest != NULL) {
		for (int i = 0; newdest != NULL && dest[i] != '\0'; i++)
			newdest[i] = dest[i];
		free(dest);
	}
	for (int i = 0; newdest != NULL && src[i] != '\0'; i++)
		newdest[my_strlen(newdest)] = src[i];
	dest = my_calloc(my_strlen(newdest) + 1);
	for (int i = 0; dest != NULL && newdest[i] != '\0'; i++)
		dest[i] = newdest[i];
	free(newdest);
	return (dest);
}
