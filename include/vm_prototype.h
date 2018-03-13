/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** functions
*/

#ifndef	__FUNCTION_H__
#define	__FUNCTION_H__

#include "vm_struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/Window.h>

/* Core related */
void print_champion_info(data_t *champion);
void free_struct_champions(data_t *);
void duplicate_node(core_t *core, data_t *champion, int is_long);
void duplicate_node(core_t *core, data_t *champion, int is_long);
void	add_champion_to_vm(int fd, int ac, core_t *core, data_t *champion);
data_t *init_new_node(data_t *champion, int fd);
data_t	*init_generating_pc(data_t *champion, core_t *core, int ac, char **av);
void	init_register(data_t *new, int player_nb);
void	duplicate_register(data_t *new, data_t *initial);
void vm_loop(data_t *champion, core_t *core);
char	*convert_nbr_base(int nbr, int base);
void	dump_memory(char *memory);

/* Endian / Byte code / Mem value */
int	endian_swap(int x);
int	mem_value(char *mem, int index, int length);
int	analys_byte_code(char byte, int argc, int indexes);
int	length_byte_code(char byte, int indexes);
void fill_cmd_params(core_t *core, data_t *champion, int params[4],
int is_bytecode);
void 	is_len_equals_zero(data_t *champion, int args);

/* Indexes */
int 	c_index(int value);
int 	r_index(int value);
int 	i_index(int value);
void 	close_command(core_t *core, data_t *champion, int index);

/* Live related */
void	reduce_cycle(core_t *core);
void	check_live(core_t *core, data_t *champion);

/* Commands */
int	command_live(data_t *champion, core_t *core);
int	command_st(data_t *champion, core_t *core);
int	command_zjump(data_t *champion, core_t *core);
int	command_sti(data_t *champion, core_t *core);
int	command_add(data_t *champion, core_t *core);
int	command_sub(data_t *champion, core_t *core);
int	command_and(data_t *champion, core_t *core);
int	command_or(data_t *champion, core_t *core);
int	command_xor(data_t *champion, core_t *core);
int	command_aff(data_t *champion, core_t *core);
int	command_fork(data_t *champion, core_t *core);
int	command_lfork(data_t *champion, core_t *core);
int	command_ld(data_t *champion, core_t *core);
int	command_ldi(data_t *champion, core_t *core);
int	command_lld(data_t *champion, core_t *core);
int	command_lldi(data_t *champion, core_t *core);

/* Setup commands */
void	setup_st(data_t *champion, core_t *core);
void	setup_live(data_t *champion, core_t *core);
void	setup_sti(data_t *champion, core_t *core);
void	setup_zjump(data_t *champion, core_t *core);
void	setup_add(data_t *champion, core_t *core);
void	setup_sub(data_t *champion, core_t *core);
void	setup_and(data_t *champion, core_t *core);
void	setup_or(data_t *champion, core_t *core);
void	setup_xor(data_t *champion, core_t *core);
void	setup_aff(data_t *champion, core_t *core);
void	setup_fork(data_t *champion, core_t *core);
void	setup_lfork(data_t *champion, core_t *core);
void	setup_ld(data_t *champion, core_t *core);
void	setup_ldi(data_t *champion, core_t *core);
void	setup_lld(data_t *champion, core_t *core);
void	setup_lldi(data_t *champion, core_t *core);

/* Graphics */
sfRenderWindow 	*my_window_create(void);
void 	corewar_events(sfRenderWindow *window, sfEvent event);
void 	mem_display_replace(int start, core_t *core, data_t *champion);
void 	window_display_mem(sfRenderWindow *window, char *mem);
void	display_win(data_t *champion, sfRenderWindow *window, core_t *core);

#endif
