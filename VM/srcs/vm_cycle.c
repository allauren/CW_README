/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:08:29 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/10 14:14:49 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

static int		cycle_process(t_list **lst_proc)
{
	t_process	*process;
	int			lives;

	if (!lst_proc)
		return (0);
	process = (t_process *)((*lst_proc)->content);
	if (!(process->last_live))
	{
		cycle_pkill(lst_proc);
		return (cycle_process(lst_proc));
	}
	lives = process->last_live;
	process->last_live = 0;
	return (lives + cycle_process(&(lst_proc->next)));
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
		vm_itsover(vm);
	vm->cycle += 1;
}
