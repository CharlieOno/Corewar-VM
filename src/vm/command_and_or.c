/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** commands part 5
*/

#include "vm_prototype.h"
#include "my.h"

void	do_and(data_t *champion)
{
	int	sum;
	int 	value1 = champion->command.argv[0];
	int 	value2 = champion->command.argv[1];

	if (champion->command.len[0] == 1)
		value1 = champion->reg[r_index(champion->command.argv[0])];
	if (champion->command.len[1] == 1)
		value2 = champion->reg[r_index(champion->command.argv[1])];
	sum = value1 & value2;
	champion->reg[r_index(champion->command.argv[2])] = sum;
	champion->carry = sum;
}

int	command_and(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 6 && champion->command.cycle_left == -1)
		setup_and(champion, core);
	if (champion->command.code != 6)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_and(champion);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + champion->command.len[2] + 2);
	return (1);
}

void	do_or(data_t *champion)
{
	int	sum;
	int 	value1 = champion->command.argv[0];
	int 	value2 = champion->command.argv[1];

	if (champion->command.len[0] == 1)
		value1 = champion->reg[r_index(champion->command.argv[0])];
	if (champion->command.len[1] == 1)
		value2 = champion->reg[r_index(champion->command.argv[1])];
	sum = value1 | value2;
	champion->reg[r_index(champion->command.argv[2])] = sum;
	champion->carry = sum;
}

int	command_or(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 7 && champion->command.cycle_left == -1)
		setup_or(champion, core);
	if (champion->command.code != 7)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_or(champion);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + champion->command.len[2] + 2);
	return (1);
}