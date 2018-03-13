/*
** EPITECH PROJECT, 2018
** Libmy
** File description:
** free word array
*/

#include <stdio.h>
#include <stdlib.h>

void	free_strdarray(char **darray)
{
	for (int i = 0; darray != NULL && darray[i] != NULL; i++)
		free(darray[i]);
	if (darray != NULL)
		free(darray);
}
