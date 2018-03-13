/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** command part 2
*/

#include "vm_prototype.h"
#include "my.h"

void	do_sti(data_t *champion, core_t *core)
{
	int adress = 0;

	adress += (champion->command.len[1] == 1) ?
	champion->reg[r_index(champion->command.argv[1] - 1)] :
	champion->command.argv[1];
	adress += (champion->command.len[2] == 1) ?
	champion->reg[r_index(champion->command.argv[2] - 1)] :
	champion->command.argv[2];
	adress = i_index(adress);
	core->mem[c_index(champion->pc + adress + 3)] =
	c_index(champion->reg[r_index(champion->command.argv[0] - 1)]);
	core->mem_display[c_index(champion->pc + adress + 3)] =
	champion->player_nb;
}

int	command_sti(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 11 &&
	champion->command.cycle_left == -1)
		setup_sti(champion, core);
	if (champion->command.code != 11)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_sti(champion, core);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + champion->command.len[2] + 2);
	return (1);
}

void 	do_zjmp(core_t *core, data_t *champion)
{
	if (champion->carry != 0) {
		champion->pc = c_index(champion->pc +
		i_index(champion->command.argv[0] - 1));
		champion->carry = 0;
	} else {
		champion->pc = (champion->pc + 3) % MEM_SIZE;
	}
	core->mem_display[champion->pc] = champion->player_nb;
}

int	command_zjump(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 9 && champion->command.cycle_left == -1)
		setup_zjump(champion, core);
	if (champion->command.code != 9)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_zjmp(core, champion);
	champion->command.cycle_left = -2;
	champion->command.code = 0;
	return (1);
}
