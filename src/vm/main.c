/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** main file with global tab
*/

#include "vm_prototype.h"
#include "my.h"

int	main(int ac, char **av)
{
	core_t *core = malloc(sizeof(core_t));
	data_t *champion = NULL;

	core->mem = malloc(sizeof(char) * (MEM_SIZE + 1));
	core->mem_display = malloc(sizeof(char) * (MEM_SIZE + 1));
	for (int i = 0; i < MEM_SIZE; i++) {
		core->mem[i] = 0;
		core->mem_display[i] = 0;
	}
	core->cycle = CYCLE_TO_DIE;
	if (ac < 3)
		return (84);
	champion = init_generating_pc(champion, core, ac, av);
	vm_loop(champion, core);
	return (0);
}
