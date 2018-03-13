/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** setup commands to execute them properly
*/

#include "vm_prototype.h"
#include "my.h"

void	fill_cmd_params(core_t *core, data_t *champion, int params[4],
int is_bytecode)
{
	int	pc = champion->pc + is_bytecode + 1;

	pc = pc % MEM_SIZE;
	for (int i = 0; i < 4; i++) {
		if (params[i] == 0)
			break;
		champion->command.argv[i] = mem_value(core->mem, pc, params[i]);
		pc += params[i];
		pc = pc % MEM_SIZE;
	}
}

void	setup_st(data_t *champion, core_t *core)
{
	int	len1 = 0;
	int	len2 = 0;

	champion->command.len[0] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 1, 0);
	champion->command.len[1] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 2, 0);
	champion->command.code = 3;
	champion->command.argc = 2;
	champion->command.cycle_left = 1 + 1;
	len1 = champion->command.len[0];
	len2 = champion->command.len[1];
	fill_cmd_params(core, champion, (int[4]){len1, len2, 0, 0}, 1);
	is_len_equals_zero(champion, 2);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_sti(data_t *champion, core_t *core)
{
	int	len1 = 0;
	int	len2 = 0;
	int	len3 = 0;

	champion->command.len[0] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 1, 1);
	champion->command.len[1] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 2, 1);
	champion->command.len[2] = analys_byte_code(
	core->mem[(champion->pc + 1) % MEM_SIZE], 3, 1);
	champion->command.code = 11;
	champion->command.argc = 3;
	champion->command.cycle_left = 5 + 1;
	len1 = champion->command.len[0];
	len2 = champion->command.len[1];
	len3 = champion->command.len[2];
	fill_cmd_params(core, champion, (int[4]){len1, len2, len3, 0}, 1);
	is_len_equals_zero(champion, 3);
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_zjump(data_t *champion, core_t *core)
{
	champion->command.len[0] = 2;
	champion->command.code = 9;
	champion->command.argc = 1;
	champion->command.cycle_left = 4 + 1;
	fill_cmd_params(core, champion, (int[4]){2, 0, 0, 0}, 0);
	champion->command.argv[0] = c_index(champion->pc +
	i_index(champion->command.argv[0]));
	core->mem_display[champion->pc] = champion->player_nb;
}

void	setup_live(data_t *champion, core_t *core)
{
	champion->command.len[0] = 4;
	champion->command.code = 1;
	champion->command.argc = 1;
	champion->command.cycle_left = 2 + 1;
	champion->command.argv[0] = mem_value(core->mem, champion->pc + 1, 4);
	champion->command.argv[0] = i_index(champion->command.argv[0]);
	core->mem_display[champion->pc] = champion->player_nb;
}
