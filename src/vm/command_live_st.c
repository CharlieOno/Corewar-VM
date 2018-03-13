/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** command part 1
*/

#include "vm_prototype.h"
#include "my.h"

void 	do_live(data_t *champion, core_t *core, int live)
{
	for (int count = 0; count < core->total_player; count++) {
		if (live == champion->player_nb) {
			core->last_live = champion->player_nb;
			champion->live = 1;
			reduce_cycle(core);
			break;
		}
		champion = champion->next;
	}
}

int	command_live(data_t *champion, core_t *core)
{
	int 	live;

	if (core->mem[champion->pc] == 1 && champion->command.cycle_left == -1)
		setup_live(champion, core);
	if (champion->command.code != 1)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	live = champion->command.argv[0];
	do_live(champion, core, live);
	close_command(core, champion, champion->command.len[0] + 1);
	return (1);
}

void 	do_st(data_t *champion, core_t *core)
{
	if (champion->command.len[1] == 1) {
		champion->reg[r_index(champion->command.argv[1] - 1)] =
		champion->reg[r_index(champion->command.argv[0] - 1)];
	} else {
		core->mem[c_index(champion->command.len[1] +
		champion->command.len[0] + champion->pc +
		i_index(champion->command.argv[1]))] =
		champion->reg[r_index(champion->command.argv[0] - 1)];
		core->mem_display[c_index(champion->command.len[1] +
		champion->command.len[0] + champion->pc +
		i_index(champion->command.argv[1]))] = champion->player_nb;
	}
}

int	command_st(data_t *champion, core_t *core)
{
	if (core->mem[champion->pc] == 3 && champion->command.cycle_left == -1)
		setup_st(champion, core);
	if (champion->command.code != 3)
		return (0);
	if ((champion->command.cycle_left -= 1) != 0)
		return (1);
	do_st(champion, core);
	close_command(core, champion, champion->command.len[0] +
	champion->command.len[1] + 2);
	return (1);
}