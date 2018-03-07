/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/06 14:25:11 by gsmith           ###   ########.fr       */
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
	unsigned int		ocp;
	unsigned int		rg;
	unsigned int		ind;
	unsigned int		val;
	unsigned int		offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, (proc->pc) + 1, 1);
	offset = 2 + (ARG(ocp, 3) == A_REG ? 1 : 2);
	offset += (ARG(ocp, 2) == A_REG ? 1 : 2);
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) && ARG(ocp, 2) != A_IND
			&& ARG(ocp, 3))
	{
		ind = ind_sum_ldi(ocp, mem, proc);
		val = read_mem(mem, proc->pc + (ind % IDX_MOD), 4);
		rg = read_mem(mem, proc->pc + offset, 1);
		if (rg > 0 && rg <= REG_NUMBER)
			(proc->reg)[rg - 1] = val;
	}
	else
		val = 1;
	(proc->carry) = !val;
	(proc->pc) += offset + 1;
}

void	op_sti(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg;
	unsigned int		ind;
	unsigned int		val;
	unsigned int		offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, (proc->pc) + 1, 1);
	offset = 3 + (ARG(ocp, 2) == A_REG ? 1 : 2);
	offset += (ARG(ocp, 1) == A_REG ? 1 : 2);
	if (ARG(ocp, 3) == A_REG && ARG(ocp, 1) && ARG(ocp, 1) != A_IND
			&& ARG(ocp, 2))
	{
		rg = read_mem(mem, proc->pc + 2, 1);
		val = 0;
		if (rg > 0 && rg <= REG_NUMBER)
			val = (proc->reg)[rg - 1];
		ind = ind_sum_sti(ocp, mem, proc);
		write_mem(mem, proc->pc + (ind % IDX_MOD), val);
	}
	else
		val = 1;
	(proc->carry) = !val;
	(proc->pc) += offset;
}

void	op_fork(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		dest;

	(void)timer;
	dest = proc->pc + (read_mem(mem, (proc->pc) + 1, 2) % IDX_MOD);
	proc_add(lst_proc, proc_dup(proc, dest));
	(proc->pc) += 3;
}
