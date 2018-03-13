/*
** EPITECH PROJECT, 2018
** create_nodes.c
** File description:
** vm
*/

#include "vm_prototype.h"
#include "my.h"

void fill_node(data_t *new, data_t *champion, header_t header)
{
	new->carry = 0;
	new->prog_name = my_strcpy(header.prog_name);
	if (endian_swap(header.magic) != COREWAR_EXEC_MAGIC)
		exit(84);
	new->magic = endian_swap(header.magic);
	new->prog_size = endian_swap(header.prog_size);
	new->comment = my_strcpy(header.comment);
	new->next = champion;
}

data_t *init_new_node(data_t *champion, int fd)
{
	data_t *new = malloc(sizeof(*new));
	header_t header;
	int a = 0;
	static int player_nb = 1;

	a = read(fd, &header, sizeof(header));
	if (a == -1 || new == NULL)
		return (NULL);
	new->player_nb = player_nb;
	new->live = 0;
	new->command.cycle_left = -1;
	new->command.code = 0;
	for (int i = 0; i < MAX_ARGS_NUMBER; i++)
		new->command.argv[i] = 0;
	init_register(new, player_nb);
	fill_node(new, champion, header);
	player_nb++;
	return (new);
}

void fill_duplicated_node(data_t *new, data_t *champion)
{
	new->prog_name = my_strcpy(champion->prog_name);
	new->magic = champion->magic;
	new->prog_size = champion->prog_size;
	new->comment = my_strcpy(champion->comment);
	new->player_nb = champion->player_nb;
	new->carry = champion->carry;
	new->live = champion->live;
}

void duplicate_node(core_t *core, data_t *champion, int is_long)
{
	data_t *new = malloc(sizeof(*new));

	core->total_player += 1;
	if (new == NULL)
		return;
	fill_duplicated_node(new, champion);
	duplicate_register(new, champion);
	new->command.cycle_left = -1;
	new->command.code = 0;
	for (int i = 0; i < MAX_ARGS_NUMBER; i++)
		new->command.argv[i] = 0;
	new->pc = (is_long == 0) ? c_index(champion->pc +
	i_index(champion->command.argv[0])) : c_index(champion->pc +
	champion->command.argv[0]);
	new->next = champion->next;
	champion->next = new;
}
