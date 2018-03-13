/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** cycle handling
*/

#include "vm_prototype.h"
#include "my.h"

void 	call_commands(int *status, data_t *champion, core_t *core)
{
	*status += command_fork(champion, core);
	*status += command_st(champion, core);
	*status += command_sti(champion, core);
	*status += command_live(champion, core);
	*status += command_zjump(champion, core);
	*status += command_add(champion, core);
	*status += command_sub(champion, core);
	*status += command_and(champion, core);
	*status += command_or(champion, core);
	*status += command_lfork(champion, core);
	*status += command_ld(champion, core);
	*status += command_ldi(champion, core);
	*status += command_xor(champion, core);
	*status += command_aff(champion, core);
	*status += command_lld(champion, core);
	*status += command_lldi(champion, core);
}

void	exec_commands(data_t *champion, core_t *core)
{
	int	status = 0;

	for (int count = 0; count < core->total_player; count++) {
		call_commands(&status, champion, core);
		if (status == 0) {
			champion->pc = (champion->pc + 1) % MEM_SIZE;
			core->mem_display[champion->pc] = champion->player_nb;
		}
		champion = champion->next;
		status = 0;
		if (champion->command.cycle_left == -2)
			champion->command.cycle_left = -1;
	}
}

void vm_loop(data_t *champion, core_t *core)
{
	sfRenderWindow 	*window = my_window_create();
	sfEvent 	event;
	int act_cycle = 1;

	for (act_cycle = 1; sfRenderWindow_isOpen(window); act_cycle += 1) {
		corewar_events(window, event);
		sfRenderWindow_clear(window, sfBlack);
		if (core->cycle > 0) {
			exec_commands(champion, core);
			if (act_cycle >= core->cycle) {
				check_live(core, champion);
				act_cycle = 0;
			}
		}
		window_display_mem(window, core->mem_display);
		display_win(champion, window, core);
		sfRenderWindow_display(window);
	}
}
