/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/05 13:11:53 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_zjmp(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		dest;

	(void)lst_proc;
	(void)timer;
	if (proc->carry)
	{
		dest = read_mem(mem, proc->pc + 1, 2);
		(proc->pc) = ((proc->pc) + dest) % MEM_SIZE;
	}
	else
		(proc->pc) += 3;
}

void	op_ldi(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	int		ocp;
	int		rg;
	int		ind;
	int		val;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, (proc->pc) + 1, 1);
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) && ARG(ocp, 2) != A_IND
			&& ARG(ocp, 3))
	{
		return ;
	}
	(proc->pc) = !val;
}

void	op_sti(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}

void	op_fork(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		dest;

	(void)timer;
	dest = proc->pc + (read_mem(mem, (proc->pc) + 1, 2) % IDX_MOD);
	proc_add(lst_proc, proc_dup(proc, dest));
	(proc->pc) += 3;
}
