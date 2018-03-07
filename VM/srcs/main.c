/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:04:36 by allauren          #+#    #+#             */
/*   Updated: 2018/03/07 19:24:35 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "memory.h"
#include "process.h"
#include "cycles.h"

t_bool			vm_run(t_memory *mem, t_proc **proc, t_timer *timer)
{
	t_proc		*cursor;
	int			i;

	cursor = *proc;
	while (cursor)
	{
		i = 0;
		while (i < 16 && g_op_tab[i].opc != (mem->memory)[cursor->pc])
			i++;
		if (i < 16)
		{
			if (cursor->sleep < g_op_tab[i].sleep)
				cursor->sleep++;
			else
			{
				//print_memory(mem->memory, MEM_SIZE);
				ft_printf("PC de l op%u\n", cursor->pc % MEM_SIZE);
				g_op_tab[i].fun(mem, cursor, proc, timer);
				cursor->sleep = 0;
			}
		}
		else
			(cursor->pc)++;
		cursor = cursor->next;
	}
	return (1);
}

void			vm_winner(t_chmp *player)
{
	ft_printf("Contestant %u, \"%s\", has won !\n",
			player->num_player, player->head.prog_name);
}

int				main(int argc, char *argv[])
{
	t_param		p;
	t_memory	m;
	t_timer		t;
	t_proc		*pc;

	pc = NULL;
	if (argc == 1)
		corewar_usage();
	ft_bzero(&p, sizeof(t_param));
	ft_bzero(&m, sizeof(t_memory));
	ft_parse_options(argc, argv, &p, &m);
//	print_memory(m.memory , MEM_SIZE);
//	ft_printf(" num player%u %u %u %u", p.nchamp[0].num_player, p.nchamp[1].num_player, p.nchamp[2].num_player, p.nchamp[3].num_player);
	t = cycle_init();
	ft_process(&pc, &m, &p);
	ft_printf("registre 0 %d et PC %u\n %p et next %p\n\n", pc->reg[0], pc->pc, pc, pc->next);
	while (vm_run(&m, &pc, &t))
		//continue ;
		ft_printf("cycle %d done. proc->pc = %d\n", t.cycle, pc->pc);
	print_memory(m.memory, MEM_SIZE);
	vm_winner(m.last_live);
	return (0);
}
