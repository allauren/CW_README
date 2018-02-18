/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:08:29 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/18 10:43:37 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "cycles.h"
#include "process.h"

t_timer			cycle_init(void)
{
	t_timer		res;

	res.cycle = 1;
	res.next_check = CYCLE_TO_DIE;
	res.to_die = CYCLE_TO_DIE;
	res.fail_check = 0;
	return (res);
}

t_bool			cycle_count(t_timer *timer, t_proc **proc)
{
	if (timer->cycle == timer->next_check)
	{
		if (proc_alive(proc) > NBR_LIVE && !(timer->fail_check = 0))
			timer->to_die -= CYCLE_DELTA;
		else
		{
			timer->fail_check += 1;
			if (timer->fail_check == MAX_CHECKS && !(timer->fail_check = 0))
				timer->to_die -= CYCLE_DELTA;
		}
		timer->next_check += timer->to_die;
	}
	vm->cycle += 1;
	return (proc == NULL);
}

/*
** |
** | code to be moved in another file
** V
*/

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
