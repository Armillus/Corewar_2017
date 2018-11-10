/*
** EPITECH PROJECT, 2018
** memory_writing.c
** File description:
** rite the bytecode in memory
*/

#include <unistd.h>
#include "../include/mem_writing.h"
#include "../include/arena.h"
#include "../op/op.h"
#include "../include/asm.h"

void init_my_champion(champion_t *champion)
{
	if (!champion)
		return ;
	champion->buffer = NULL;
	champion->nb_bytes = 0;
}

void recover_my_champion(char *arena, process_t *proc,
header_t *players, champion_t *champion)
{
	unsigned char buf[BUFF_SIZE];
	int read_size = 0;
	int fd = open(proc->name, O_RDONLY);
	static int num = 0;

	if (!champion || !proc->name || fd == -1)
		free_and_quit(arena, proc, champion, 1);
	if (read(fd, &(players[num]), sizeof(header_t)) == -1)
		free_and_quit(arena, proc, champion, 1);
	while ((read_size = read(fd, buf, BUFF_SIZE)) > 0) {
		champion->nb_bytes += read_size;
		champion->buffer = my_binary_strcat(champion->buffer, buf,
		champion->nb_bytes, read_size);
	}
	close(fd);
	num++;
	read_size < 0 ?	free_and_quit(arena, proc, champion, 1) : 0;
	players[num].magic = num + 1;
}

void fill_my_memory(char *dest, champion_t *champ,
process_t *proc, int *intervals)
{
	unsigned int j = 0;
	unsigned int i = proc->PC;

	for (; i < MEM_SIZE && j < champ->nb_bytes; i++, j++) {
		for (int x = 0; x < champ->malloc_size &&
		intervals[x] != -1; x += 2) {
			(intervals[x] != proc->PC && ((i >= intervals[x] &&
			i <= intervals[x + 1]) || dest[i] != 0)) ?
			free_and_quit(dest, proc, champ, 0) : 0;
		}
		i = (i == MEM_SIZE - 1 ? -1 : i);
		dest[i] = champ->buffer[j];
	}
	free(champ->buffer);
	init_my_champion(champ);
}

void browse_process(unsigned char *arena, process_t *proc_list,
header_t *players, champion_t *champion)
{
	unsigned int pos = 0;
	unsigned int i = 0;

	for (; proc_list; i++, pos += 2) {
		recover_my_champion(arena, proc_list, players, champion);
		players[i].prog_size = my_swap(players[i].prog_size);
		champion->intervals[pos] = proc_list->PC;
		champion->intervals[pos + 1] = proc_list->PC +
		players[i].prog_size;
		champion->intervals[pos + 1] -=
		champion->intervals[pos + 1] > MEM_SIZE ? MEM_SIZE : 0;
		fill_my_memory(arena, champion, proc_list, champion->intervals);
		proc_list = proc_list->next;
	}
}

void write_bytecode_in_mem(unsigned char *arena,
process_t *proc_list, header_t *players)
{
	champion_t *champion = malloc(sizeof(champion_t));

	init_my_champion(champion);
	if (!champion)
		return;
	champion->malloc_size = 0;
	for (unsigned int j = 0; players[j].magic != -1;
	champion->malloc_size += 2, j++);
	champion->intervals = malloc(sizeof(unsigned int) *
	(champion->malloc_size + 1));
	for (int i = 0; i < champion->malloc_size; i++)
		champion->intervals[i] = -1;
	if (!champion->intervals)
		return ;
	write(1, "Let the game begin !\n", 21);
	browse_process(arena, proc_list, players, champion);
	free(champion->intervals);
	free(champion);
}
