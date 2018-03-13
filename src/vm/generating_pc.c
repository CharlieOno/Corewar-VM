/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** pc generation functions
*/

#include "vm_prototype.h"
#include "my.h"

void close_loop(data_t *champion)
{
	data_t *tmp = champion;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = champion;
}

data_t *init_generating_pc(data_t *champion, core_t *core, int ac, char **av)
{
	int fd;

	core->total_player = 0;
	core->total_process = 0;
	for (int i = 1; i < ac; i++) {
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			exit(84);
		champion = init_new_node(champion, fd);
		if (champion == NULL)
			exit(84);
		add_champion_to_vm(fd, ac, core, champion);
		core->total_player += 1;
		if (core->mem == NULL)
			exit(84);
		close(fd);
	}
	close_loop(champion);
	return (champion);
}

void free_struct_champions(data_t *champion)
{
	data_t *tmp;

	while (champion != NULL) {
		tmp = champion;
		champion = champion->next;
		free(tmp->prog_name);
		free(tmp->comment);
		free(tmp);
	}
}

void	add_champion_to_vm(int fd, int ac, core_t *core, data_t *champion)
{
	static int champ_nb = 0;
	static int i = 0;
	int start = i;
	int return_of_read = 1;

	champion->pc = i;
	while (return_of_read != 0) {
		return_of_read = read(fd, &core->mem[i], 1);
		if (return_of_read == -1)
			exit(84);
		i++;
		if (i > (MEM_SIZE / (ac - 1)) * (champ_nb + 1))
			exit(84);
	}
	champ_nb++;
	mem_display_replace(start, core, champion);
	i = (MEM_SIZE / (ac - 1)) * champ_nb;
}
