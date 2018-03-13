/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** commands part 7
*/

#include "vm_prototype.h"
#include "my.h"

void	do_xor(data_t *champion)
{
	int	sum;
	int 	value1 = champion->command.argv[0];
	int 	value2 = champion->command.argv[1];

	if (champion->command.len[0] == 1)
		value1 = champion->reg[r_index(champion->command.argv[0])];
	if (champion->command.len[1] == 1)
		value2 = champion->reg[r_index(champion->command.argv[1])];
	sum = value1 ^ value2;
	champion->reg[r_index(champion->command.argv[2])] = sum;
	champion->carry = sum;
}

int	command_xor(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 8 && champion->command.cycle_left == -1)
		setup_xor(champion, core);
	if (champion->command.code != 8)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_xor(champion);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + champion->command.len[2] + 2);
	return (1);
}

int	command_aff(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 16 &&
	champion->command.cycle_left == -1)
		setup_aff(champion, core);
	if (champion->command.code != 16)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	close_command(core, champion, 3);
	return (1);
}