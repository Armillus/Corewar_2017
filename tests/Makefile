##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for unit testing of my_printf
##

SRC_VIRT= 	../virtual_machine/utils_vm.c			\
		../virtual_machine/vm_error_handling.c		\
		../virtual_machine/vm_player_properties.c	\
		../virtual_machine/memory_writing.c		\
		../virtual_machine/memory_error_handling.c	\
		../virtual_machine/arena_processing.c		\
		../virtual_machine/arena_computing.c		\
		../virtual_machine/arena_schedule.c		\
		../virtual_machine/arena_schedule_2.c		\
		../virtual_machine/arena_schedule_3.c		\
		../virtual_machine/free_memory.c		\
		../virtual_machine/binary_functions.c		\
		../virtual_machine/dump_display.c		\
		../get_next_line/get_next_line.c		\
		../get_next_line/utils.c			\
		../lib/my_strcpy.c				\
		../lib/my_strerr.c				\
		../lib/my_put_nbr.c				\
		../lib/my_strdup.c				\
		../lib/my_strncpy.c				\
		../lib/my_getnbr.c				\
		../lib/my_strcmp.c				\
		../lib/my_memset.c				\
		../command_assembly/aff_c.c			\
		../command_assembly/browse_command.c		\
		../command_assembly/fork_c.c			\
		../command_assembly/ld_c.c			\
		../command_assembly/ldi_c.c			\
		../command_assembly/live_c.c			\
		../command_assembly/logic_op.c			\
		../command_assembly/math_op.c			\
		../command_assembly/st.c			\
		../command_assembly/sti_c.c			\
		../command_assembly/zjump.c			\
		../asm/utils.c					\
		../op/op.c

SRC_UT_DIR=     $(realpath .)

SRC_UT=         $(SRC_UT_DIR)/unit_test_corewar.c 		\
	        $(SRC_UT_DIR)/unit_test_corewar_2.c

OBJ=            $(SRC_UT:.c=.o) $(SRC_VIRT:.c=.o) 

CFLAGS=         -Wall -Wextra --coverage

LDFLAGS=        -lcriterion -lgcov

NAME=           unit_test

all:            $(NAME) run

$(NAME):        $(OBJ)
		cc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

run:		$(NAME)
		./unit_test

clean:
		rm -f $(OBJ)
		rm -f *.gcda
		rm -f *.gcno
		rm -f ../virtual_machine/*.gcda
		rm -f ../virtual_machine/*.gcno
		rm -f ../command_assembly/*.gcda
		rm -f ../command_assembly/*.gcno
		rm -f ../include/*.gcda
		rm -f ../include/*.gcno
		rm -f ../get_next_line/*.gcda
		rm -f ../get_next_line/*.gcno
		rm -f ../lib/*.gcno
		rm -f ../lib/*.gcda

fclean:         clean
		rm -f $(NAME)

re:             fclean all
