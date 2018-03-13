/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** vm struct header
*/

#ifndef	__STRUCT_VM_H__
#define __STRUCT_VM_H__

#include "vm_main.h"

// Related to PCs (processes)
typedef struct header_s {
	int		magic;
	char 	prog_name[PROG_NAME_LENGTH + 1];
	int		prog_size;
	char 	comment[COMMENT_LENGTH + 1];
} header_t;

// Related to commands : infos in global op_tab[]
typedef struct op_s {
	char 	*mnemonique;
	char 	nbr_args;
	char 	type[MAX_ARGS_NUMBER];
	char 	code;
	int 	nbr_cycles;
	char 	*comment;
} op_t;

// Kind-of Buffer of commands
typedef struct command_s {
	char	code;
	int		argc;
	int		argv[MAX_ARGS_NUMBER];
	int		len[MAX_ARGS_NUMBER];
	int		cycle_left;
} command_t;

// Main structure of the program
typedef struct core_s {
	char		*mem;
	char 		*mem_display;
	int 		cycle;
	int 		last_live;
	int			total_player;
	int			total_process;
	int			nb_commands;
	command_t	commands;
} core_t;

// Infos of different PCs
typedef struct data_s {
	char	*prog_name;
	int	magic;
	int	prog_size;
	char	*comment;
	int	player_nb;
	int	carry;
	int	pc;
	int	live;
	int	reg[REG_NUMBER];
	command_t	command;
	struct data_s	*next;
} data_t;

extern op_t	op_tab[];

#endif
