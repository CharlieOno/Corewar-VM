/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** commands part 8
*/

#include "vm_prototype.h"
#include "my.h"

void 	do_lld(data_t *champion, core_t *core)
{
	int 	index = champion->command.argv[0];
	int	value;

	index = c_index(index + champion->pc);
	value = mem_value(core->mem, index, REG_SIZE);
	champion->carry = value;
	champion->reg[r_index(champion->command.argv[1] - 1)] = value;
}

int	command_lld(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 13 &&
	champion->command.cycle_left == -1)
		setup_lld(champion, core);
	if (champion->command.code != 13)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_lld(champion, core);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + 2);
	return (1);
}

void 	do_lldi(data_t *champion, core_t *core)
{
	int 	index;
	int 	value;

	value = c_index(champion->command.argv[0] + champion->pc);
	index = mem_value(core->mem, value, IND_SIZE);
	index += c_index(champion->command.argv[1]);
	value = mem_value(core->mem, index, REG_SIZE);
	champion->carry = value;
	champion->reg[r_index(champion->command.argv[2] - 1)] = value;
}

int	command_lldi(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 14 &&
	champion->command.cycle_left == -1)
		setup_lldi(champion, core);
	if (champion->command.code != 14)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_lldi(champion, core);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + champion->command.len[2] + 2);
	return (1);
}