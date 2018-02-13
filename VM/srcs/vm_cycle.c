/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:08:29 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/13 15:24:02 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

static int		cycle_process(t_proc **proc)
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

void			cycle_count(t_vm *vm)
{
	if (vm->cycle == vm->next_check)
	{
		if (cycle_process(&(vm->process)) > NBR_LIVE && !(vm->failed_check = 0))
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
