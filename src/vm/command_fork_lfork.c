/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** commands part 6
*/

#include "vm_prototype.h"
#include "my.h"

int	command_fork(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 12 &&
	champion->command.cycle_left == -1)
		setup_fork(champion, core);
	if (champion->command.code != 12)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	duplicate_node(core, champion, 0);
	close_command(core, champion, 3);
	return (1);
}

int	command_lfork(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 15 &&
	champion->command.cycle_left == -1)
		setup_lfork(champion, core);
	if (champion->command.code != 15)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	duplicate_node(core, champion, 1);
	close_command(core, champion, 3);
	return (1);
}
