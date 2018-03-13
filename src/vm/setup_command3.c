/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** setup commands part 3
*/

#include "vm_prototype.h"
#include "my.h"

void	setup_aff(data_t *champion, core_t *core)
{
	champion->command.len[0] = 1;
	champion->command.code = 16;
	champion->command.argc = 1;
	champion->command.cycle_left = 2 + 1;
	fill_cmd_params(core, champion, (int[4]){1, 0, 0, 0}, 1);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_fork(data_t *champion, core_t *core)
{
	champion->command.len[0] = 2;
	champion->command.code = 12;
	champion->command.argc = 1;
	champion->command.cycle_left = 160 + 1;
	fill_cmd_params(core, champion, (int[4]){2, 0, 0, 0}, 0);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_lfork(data_t *champion, core_t *core)
{
	champion->command.len[0] = 2;
	champion->command.code = 15;
	champion->command.argc = 1;
	champion->command.cycle_left = 200 + 1;
	fill_cmd_params(core, champion, (int[4]){2, 0, 0, 0}, 0);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_ld(data_t *champion, core_t *core)
{
	int 	len1;
	int 	len2;

	champion->command.len[0] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 1, 0);
	champion->command.len[1] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 2, 0);
	champion->command.code = 2;
	champion->command.argc = 2;
	champion->command.cycle_left = 1 + 1;
	len1 = champion->command.len[0];
	len2 = champion->command.len[1];
	fill_cmd_params(core, champion, (int[4]){len1, len2, 0, 0}, 1);
	is_len_equals_zero(champion, 2);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_ldi(data_t *champion, core_t *core)
{
	int 	len1;
	int 	len2;
	int 	len3;

	champion->command.len[0] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 1, 1);
	champion->command.len[1] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 2, 1);
	champion->command.len[2] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 3, 1);
	champion->command.code = 10;
	champion->command.argc = 3;
	champion->command.cycle_left = 5 + 1;
	len1 = champion->command.len[0];
	len2 = champion->command.len[1];
	len3 = champion->command.len[2];
	fill_cmd_params(core, champion, (int[4]){len1, len2, len3, 0}, 1);
	is_len_equals_zero(champion, 3);
	core->mem_display[champion->pc] = champion->player_nb;
}
