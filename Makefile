##
## EPITECH PROJECT, 2018
## CPE_matchstick_2017
## File description:
## MF
##

SRC_VM	=	src/vm/main.c					\
			src/vm/generating_pc.c			\
			src/vm/register.c 				\
			src/vm/processing.c 			\
			src/vm/command_live_st.c 		\
			src/vm/command_sti_zjmp.c 		\
			src/vm/command_add_sub.c 		\
			src/vm/command_and_or.c 		\
			src/vm/command_fork_lfork.c 	\
			src/vm/command_ld_ldi.c 		\
			src/vm/create_nodes.c			\
			src/vm/command_lld_lldi.c 		\
			src/vm/command_xor_aff.c 		\
			src/vm/setup_command.c 			\
			src/vm/setup_command2.c 		\
			src/vm/setup_command3.c 		\
			src/vm/setup_command4.c 		\
			src/vm/graphics.c 				\
			src/vm/cycle.c 					\
			src/vm/utilities.c 				\
			src/vm/display.c 				\
			src/vm/endian.c

CFLAGS	=	-W -Wall -Wextra -L ./lib/my -lmy -I./include

OBJ_VM	=	$(SRC_VM:.c=.o)

VM		=	corewar

TEST		=	tests

MAKE_LIB	=	make -C ./lib/my/

LIB	=	-lcsfml-audio		\
		-lcsfml-graphics	\
		-lcsfml-network		\
		-lcsfml-window		\
		-lcsfml-system		\
		-lm

all: $(VM)

$(VM): $(OBJ_VM)
	$(MAKE_LIB)
	gcc $(OBJ_VM) $(CFLAGS) $(LIB) -o $(VM)

clean:
	rm -f $(OBJ_VM)
	$(MAKE_LIB) clean

fclean:	clean
	rm -rf $(VM)
	$(MAKE_LIB) fclean

re:	fclean all
