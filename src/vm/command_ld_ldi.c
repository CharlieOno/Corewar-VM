/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** command part 3
*/

#include "vm_prototype.h"
#include "my.h"

void 	do_ld(data_t *champion, core_t *core)
{
	int 	index = i_index(champion->command.argv[0]);
	int	value;

	index = c_index(index + champion->pc);
	value = mem_value(core->mem, index, REG_SIZE);
	champion->carry = value;
	champion->reg[r_index(champion->command.argv[1] - 1)] = value;
}

int	command_ld(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 2 && champion->command.cycle_left == -1)
		setup_ld(champion, core);
	if (champion->command.code != 2)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_ld(champion, core);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + 2);
	return (1);
}

void 	do_ldi(data_t *champion, core_t *core)
{
	int 	index;
	int 	value;

	value = c_index(i_index(champion->command.argv[0]) + champion->pc);
	index = mem_value(core->mem, value, IND_SIZE);
	index += c_index(i_index(champion->command.argv[1]));
	value = mem_value(core->mem, index, REG_SIZE);
	champion->carry = value;
	champion->reg[r_index(champion->command.argv[2] - 1)] = value;
}

int	command_ldi(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 10 &&
	champion->command.cycle_left == -1)
		setup_ldi(champion, core);
	if (champion->command.code != 10)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_ldi(champion, core);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + champion->command.len[2] + 2);
	return (1);
}