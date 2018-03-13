/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** utilities functions, search at the right index ...
*/

#include "vm_prototype.h"

int 	c_index(int value)
{
	while (value < 0)
		value += MEM_SIZE;
	if (value > MEM_SIZE)
		value %= MEM_SIZE;
	return (value);
}

int 	r_index(int value)
{
	while (value < 0)
		value += REG_NUMBER;
	if (value > REG_NUMBER)
		value %= REG_NUMBER;
	return (value);
}

int 	i_index(int value)
{
	while (value < IDX_MOD * -1)
		value += IDX_MOD;
	if (value > IDX_MOD)
		value %= IDX_MOD;
	return (value);
}

void 	close_command(core_t *core, data_t *champion, int index)
{
	champion->pc += index;
	champion->pc = champion->pc % MEM_SIZE;
	core->mem_display[champion->pc] = champion->player_nb;
	champion->command.cycle_left = -2;
	champion->command.code = 0;
}

void 	is_len_equals_zero(data_t *champion, int args)
{
	int 	status = 0;

	status = (args >= 1 && champion->command.len[0] == 0) ? 1 : status;
	status = (args >= 2 && champion->command.len[1] == 0) ? 1 : status;
	status = (args >= 3 && champion->command.len[2] == 0) ? 1 : status;
	status = (args >= 4 && champion->command.len[3] == 0) ? 1 : status;
	if (status == 1) {
		champion->pc = c_index(champion->pc + 1);
		champion->command.cycle_left = -2;
		champion->command.code = 0;
	}
}