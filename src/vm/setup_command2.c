/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** setup commands part 2
*/

#include "vm_prototype.h"
#include "my.h"

void	setup_add(data_t *champion, core_t *core)
{
	champion->command.len[0] = 1;
	champion->command.len[1] = 1;
	champion->command.len[2] = 1;
	champion->command.code = 4;
	champion->command.argc = 3;
	champion->command.cycle_left = 2 + 1;
	fill_cmd_params(core, champion, (int[4]){1, 1, 1, 0}, 1);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_sub(data_t *champion, core_t *core)
{
	champion->command.len[0] = 1;
	champion->command.len[1] = 1;
	champion->command.len[2] = 1;
	champion->command.code = 5;
	champion->command.argc = 3;
	champion->command.cycle_left = 2 + 1;
	fill_cmd_params(core, champion, (int[4]){1, 1, 1, 0}, 1);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_and(data_t *champion, core_t *core)
{
	int 	len1;
	int 	len2;
	int 	len3;

	champion->command.len[0] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 1, 0);
	champion->command.len[1] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 2, 0);
	champion->command.len[2] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 3, 0);
	champion->command.code = 6;
	champion->command.argc = 3;
	champion->command.cycle_left = 1 + 1;
	len1 = champion->command.len[0];
	len2 = champion->command.len[1];
	len3 = champion->command.len[2];
	fill_cmd_params(core, champion, (int[4]){len1, len2, len3, 0}, 1);
	is_len_equals_zero(champion, 3);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_or(data_t *champion, core_t *core)
{
	int 	len1;
	int 	len2;
	int 	len3;

	champion->command.len[0] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 1, 0);
	champion->command.len[1] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 2, 0);
	champion->command.len[2] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 3, 0);
	champion->command.code = 7;
	champion->command.argc = 3;
	champion->command.cycle_left = 1 + 1;
	len1 = champion->command.len[0];
	len2 = champion->command.len[1];
	len3 = champion->command.len[2];
	fill_cmd_params(core, champion, (int[4]){len1, len2, len3, 0}, 1);
	is_len_equals_zero(champion, 3);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_xor(data_t *champion, core_t *core)
{
	int 	len1;
	int 	len2;
	int	len3;

	champion->command.len[0] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 1, 0);
	champion->command.len[1] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 2, 0);
	champion->command.len[2] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 3, 0);
	champion->command.code = 8;
	champion->command.argc = 3;
	champion->command.cycle_left = 1 + 1;
	len1 = champion->command.len[0];
	len2 = champion->command.len[1];
	len3 = champion->command.len[2];
	fill_cmd_params(core, champion, (int[4]){len1, len2, len3, 0}, 1);
	is_len_equals_zero(champion, 3);
	core->mem_display[champion->pc] = champion->player_nb;
}