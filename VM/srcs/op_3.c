/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/28 14:54:52 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_zjmp(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	int		dest;

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

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, (proc->pc) + 1, 1);
}

void	op_sti(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}

void	op_fork(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}
