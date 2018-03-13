/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** commands part 4
*/

#include "vm_prototype.h"
#include "my.h"

int	command_add(data_t *champion, core_t *core)
{
	int 	sum;

	if (core->mem[champion->pc] == 4 && champion->command.cycle_left == -1)
		setup_add(champion, core);
	if (champion->command.code != 4)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	sum = champion->reg[r_index(champion->command.argv[0])] +
	champion->reg[r_index(champion->command.argv[1])];
	champion->reg[r_index(champion->command.argv[2])] = sum;
	champion->carry = sum;
	close_command(core, champion, 5);
	return (1);
}

int	command_sub(data_t *champion, core_t *core)
{
	int	sum;

	if (core->mem[champion->pc] == 5 && champion->command.cycle_left == -1)
		setup_sub(champion, core);
	if (champion->command.code != 5)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	sum = champion->reg[r_index(champion->command.argv[0])] -
	champion->reg[r_index(champion->command.argv[1])];
	champion->reg[r_index(champion->command.argv[2])] = sum;
	champion->carry = sum;
	close_command(core, champion, 5);
	return (1);
}