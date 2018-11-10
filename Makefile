##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC_ASM	=	get_next_line/get_next_line.c		\
		get_next_line/utils.c			\
		asm/asm.c				\
		asm/lexer.c				\
		lib/my_strcmp.c				\
		lib/my_strncpy.c			\
		lib/my_memset.c 			\
		asm/my_atoi.c				\
		lib/my_strdup.c				\
		asm/usage.c				\
		op/op.c					\
		asm/my_clean_str.c			\
		asm/code_byte.c				\
		asm/labels.c				\
		asm/main.c				\
		asm/parameters.c			\
		asm/write_file.c			\
		asm/utils.c				\
		asm/obtain_filename.c			\
		include/par_tab.c			\
		lib/free_allocs.c			\
		asm/free_structures.c			\
		analyse_syntaxique/analyse_syntaxe.c	\
		analyse_syntaxique/direct_analyse.c	\
		analyse_syntaxique/indirect_analyse.c	\
		analyse_syntaxique/instruction_analyse.c\
		analyse_syntaxique/label_analyse.c	\
		analyse_syntaxique/label_param.c	\
		analyse_syntaxique/my_isdigit.c		\
		analyse_syntaxique/register_analyse.c	\
		analyse_syntaxique/my_puterr.c		\
		analyse_syntaxique/my_put_nbr_err.c	\
		asm/my_str_cpy.c			\
		lib/my_str_isnum.c			\
		asm/errors_handling.c			\
		asm/line_analysing.c			\
		asm/variables_initialization.c		\
		asm/write_utils.c			\
		lib/my_getnbr.c				\
		asm/string_analyzing.c			\
		asm/specific_instructions.c

SRC_VM  =	virtual_machine/virtual_machine.c	\
		virtual_machine/utils_vm.c		\
		virtual_machine/vm_error_handling.c	\
		virtual_machine/vm_player_properties.c	\
		virtual_machine/memory_writing.c	\
		virtual_machine/dump_display.c		\
		virtual_machine/arena_processing.c	\
		virtual_machine/arena_computing.c	\
		virtual_machine/arena_schedule.c	\
		virtual_machine/arena_schedule_2.c	\
		virtual_machine/arena_schedule_3.c	\
		get_next_line/get_next_line.c		\
		get_next_line/utils.c			\
		lib/my_strcmp.c				\
		lib/my_put_nbr.c			\
		lib/my_strcpy.c				\
		lib/my_getnbr.c				\
		lib/my_strdup.c				\
		op/op.c					\
		lib/my_strerr.c				\
		lib/my_memset.c				\
		asm/utils.c				\
		virtual_machine/binary_functions.c	\
		virtual_machine/free_memory.c		\
		command_assembly/aff_c.c		\
		command_assembly/browse_command.c	\
		command_assembly/fork_c.c		\
		command_assembly/ld_c.c			\
		command_assembly/ldi_c.c		\
		command_assembly/live_c.c		\
		command_assembly/logic_op.c		\
		command_assembly/math_op.c		\
		command_assembly/st.c			\
		command_assembly/zjump.c		\
		command_assembly/sti_c.c		\
		virtual_machine/memory_error_handling.c

OBJ_ASM	=	$(SRC_ASM:.c=.o)

OBJ_VM	=	$(SRC_VM:.c=.o)

NAME_ASM= 	asm1

NAME_VM = 	corewar

CC	=	gcc -g3

CFLAGS	+=	-Wuninitialized -Wextra -Wall -Werror -Wpedantic -Wunused -std=c99

all:		comp_1 comp_2

comp_1:		$(SRC_ASM)
		$(CC) -o $(NAME_ASM) $(SRC_ASM) $(COV)
		mv asm1 asm/asm

comp_2:		$(SRC_VM)
		$(CC) -o $(NAME_VM) $(SRC_VM) $(COV)

tests_run:
		cd tests && $(MAKE)

clean:
	rm -f $(OBJ_VM)
	rm -f $(OBJ_ASM)

fclean: clean
	rm -f $(NAME_VM)
	rm -f $(NAME_ASM)

re:	fclean all

.PHONY: all clean fclean re
