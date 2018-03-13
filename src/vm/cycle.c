/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** processing commands, handle cycles
*/

#include "vm_prototype.h"
#include "my.h"

void	reduce_cycle(core_t *core)
{
	static int 	live_calls = 0;

	live_calls += 1;
	if (live_calls % NBR_LIVE == 0)
		core->cycle -= CYCLE_DELTA;
}

void 	end_corewar(core_t *core, data_t *champion, int remember)
{
	if (remember != -1)
		return;
	while (1) {
		if (core->last_live == 0) {
			my_printf("No lives\n");
			core->cycle = 0;
			break;
		}
		if (core->last_live == champion->player_nb)
			break;
		champion = champion->next;
	}
	my_printf("The player %d(%s) has won.\n",
	core->last_live, champion->prog_name);
	core->cycle = 0;
}

void	check_live(core_t *core, data_t *champion)
{
	int	remember = -1;

	for (int i = 0; i < core->total_player; i++) {
		champion->live = (champion->live == 1) ? 0 : -1;
		if (champion->live > remember)
			remember = champion->live;
		champion = champion->next;
	}
	end_corewar(core, champion, remember);
}
