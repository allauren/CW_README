/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:08:29 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/10 13:37:49 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "vm.h"

static void		cycle_processdeath(t_list *process)
{
}

static void		cycle_suddendeath(t_vm *vm)
{
}

void			cycle_count(t_vm *vm)
{
	if (vm->cycle == vm->next_check)
	{
		if (cycle_processdeath(vm->process) && !(vm->failed_check = 0))
			cycle_suddendeath(vm);
		else
		{
			vm->failed_check += 1;
			if (vm->failed_check == MAX_CHECKS && !(vm->failed_check = 0))
				cycle_suddendeath(vm);
		}
	}
	if (!(vm->process))
		vm_itsover(vm);
	vm->cycle += 1;
}
