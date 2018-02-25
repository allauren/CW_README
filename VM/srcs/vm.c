/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:58:12 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/24 18:05:08 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (cursor->sleep <= 0)
		{
			i = 0;
			while (i < 16 && g_op_tab[i].opc != mem.memory[cursor->pc])
				i++;
			if (i < 16)
			{
				if (cursor->sleep < 0 || !((cursor->sleep)--))
					cursor->sleep = g_op_tab[i].sleep;
				else
					g_op_tab[i].fun(mem, cursor, proc, timer);
			}
		}
		else
			(cursor->sleep)--;
		cursor = cursor->next;
	}
	return (cycle_count(timer, proc));
}
