/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** count word
*/

#include <stdio.h>

int	my_count_word_array_args(char **word_array)
{
	int nb = 0;

	if (word_array == NULL)
		return (0);
	while (word_array[nb] != NULL) {
		nb++;
	}
	return (nb);
}
