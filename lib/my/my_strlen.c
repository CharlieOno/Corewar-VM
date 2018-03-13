/*
** EPITECH PROJECT, 2017
** task03
** File description:
** string lenght
*/

#include <stdio.h>

int	my_strlen(char const *str)
{
	int	i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		i += 1;
	}
	return (i);
}
