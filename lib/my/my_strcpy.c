/*
** EPITECH PROJECT, 2017
** task01
** File description:
** my str copy
*/

#include <stdio.h>
#include <stdlib.h>

int	my_strlen(char const *str);

char	*my_strcpy(char *str)
{
	char *dest = NULL;

	if (str == NULL)
		return (str);
	dest = (char*)malloc(sizeof(char) * (my_strlen(str) + 1));
	for (int i = 0; i < my_strlen(str) + 1; i++)
		dest[i] = '\0';
	for (int i = 0; str[i] != '\0'; i++)
		dest[i] = str[i];
	return (dest);
}
