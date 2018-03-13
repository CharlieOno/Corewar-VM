/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** display functions
*/

#include "vm_prototype.h"
#include "my.h"

char	*convert_nbr_base(int nbr, int base)
{
	int 	index = 0;
	char	*res = malloc(sizeof(char) * 11);
	int 	nbr_mod = 0;
	int	reminder = nbr;

	for (int i = 0; i < 11; i++)
		res[i] = 0;
	nbr = (nbr < 0) ? nbr * -1 : nbr;
	while (nbr > 0) {
		nbr_mod = nbr % 16;
		res[index++] = (nbr_mod >= 0 && nbr_mod <= 9) ?
		nbr_mod + '0' : nbr_mod - 10 + 'A';
		nbr /= base;
	}
	res = my_revstr(res);
	if (my_strlen(res) == 1) {
		res[1] = res[0];
		res[0] = '0';
	}
	return ((reminder == 0) ? "0" : res);
}

void	print_memory_zone(char memory_zone)
{
	if (memory_zone < 0)
		my_printf("%s", convert_nbr_base(memory_zone + 256, 16));
	if (memory_zone == 0)
		my_printf("00");
	if (memory_zone > 0)
		my_printf("%s", convert_nbr_base(memory_zone, 16));
}

void	dump_memory(char *memory)
{
	int	length = 0;
	int	i = 0;

	for (int start = 0; start < MEM_SIZE; start += 32) {
		my_printf("%s", convert_nbr_base(start, 16));
		length = my_strlen(convert_nbr_base(start, 16));
		for (int i = 5; i > length; i--)
			my_printf(" ");
		my_printf(":");
		for (; i < start + 32; i++) {
			my_printf(" ");
			print_memory_zone(memory[i]);
		}
		my_printf("\n");
	}
}

void 	mem_display_replace(int start, core_t *core, data_t *champion)
{
	int 	relative = start;

	for (; start < relative + champion->prog_size; start++)
		core->mem_display[start] = champion->player_nb;
}
