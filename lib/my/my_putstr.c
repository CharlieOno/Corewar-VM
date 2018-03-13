/*
** EPITECH PROJECT, 2017
** task02
** File description:
** my putstr
*/

void	my_putchar(char);
#include <stdio.h>

int	my_putstr(char const *str)
{
	int	i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}
