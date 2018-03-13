/*
** EPITECH PROJECT, 2017
** day06
** File description:
** my putchar
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}
