/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:08:29 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/14 17:42:38 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

static int		process_check(t_proc **proc)
{
	int			lives;
	t_proc		**cursor;

	lives = 0;
	cursor = proc;
	while (*cursor)
		if (!((*cursor)->lives_cycle))
			proc_kill(cursor);
		else
		{
			lives += proc->lives_cycle;
			(*cursor)->lives_cycle = 0;
			cursor = &((*cursor)->next);
		}
	return (lives);
}

static void		cycle_count(t_vm *vm)
{
	if (vm->cycle == vm->next_check)
	{
		if (process_check(&(vm->process)) > NBR_LIVE && !(vm->failed_check = 0))
			vm->to_die -= CYCLE_DELTA;
		else
		{
			vm->failed_check += 1;
			if (vm->failed_check == MAX_CHECKS && !(vm->failed_check = 0))
				vm->to_die -= CYCLE_DELTA;
		}
		vm->next_check += vm->to_die;
	}
	if (!(vm->process))
		vm_itsover(vm, FALSE);
	vm->cycle += 1;
}

void			vm_cycle(t_vm *vm)
{
	t_proc		*cursor;
	int			i;

	cursor = vm->proc;
	while (cursor)
	{
		if (cursor->sleep <= 0)
		{
			i = 0;
			while (g_op_tab[i].op_code
					&& g_op_tab[i].op_code != vm->memory[cursor->pc])
				i++;
			if (g_op_tab[i].op_code)
			{
				if (cursor->sleep < 0 || !((cursor->sleep)--))
					cursor->sleep = g_op_tab[i].sleep;
				else
					g_op_tab[i].fun(vm, cursor);
			}
		}
		else
			(cursor->sleep)--;
		cursor = cursor->next;
	}
	cycle_count(vm);
}
