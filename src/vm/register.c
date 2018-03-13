/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** register fill functions
*/

#include "vm_prototype.h"

void	init_register(data_t *new, int player_nb)
{
	for (int i = 0; i < REG_NUMBER; i++)
		new->reg[i] = 0;
	new->reg[0] = player_nb;
}

void	duplicate_register(data_t *new, data_t *initial)
{
	for (int i = 0; i < REG_NUMBER; i++)
		new->reg[i] = initial->reg[i];
}