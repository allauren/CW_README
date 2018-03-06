/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/06 14:00:47 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_lld(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int	ocp;
	unsigned int	rg;
	unsigned int	val;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (!ARG(ocp, 1) && ARG(ocp, 2) == A_REG
			&& (ARG(ocp, 3) == A_DIR || ARG(ocp, 3) == A_IND))
	{
		if (ARG(ocp, 3) == A_DIR)
			val = read_mem(mem, proc->pc + 2, 4);
		else
			val = read_mem(mem, proc->pc + read_mem(mem, proc->pc + 2, 2), 4);
		rg = read_mem(mem, proc->pc + 2 + (ARG(ocp, 3) == A_DIR ? 4 : 2), 1);
		if (rg <= REG_NUMBER && rg > 0)
		{
			(proc->reg)[rg - 1] = val;
			(proc->carry) = !(val);
		}
	}
	(proc->pc) += 3 + (ARG(ocp, 3) == A_DIR ? 4 : 2);
}

void	op_lldi(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg;
	unsigned int		ind;
	unsigned int		val;
	unsigned int		offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, (proc->pc) + 1, 1);
	offset = 2 + ARG(ocp, 3) == A_REG ? 1 : 2;
	offset += ARG(ocp, 2) == A_REG ? 1 : 2;
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) && ARG(ocp, 2) != A_IND
			&& ARG(ocp, 3))
	{
		ind = ind_sum_ldi(ocp, mem, proc);
		val = read_mem(mem, proc->pc + ind, 4);
		rg = read_mem(mem, proc->pc + offset, 1);
		if (rg > 0 && rg <= REG_NUMBER)
			(proc->reg)[rg - 1] = val;
	}
	else
		val = 1;
	(proc->carry) = !val;
	(proc->pc) += offset + 1;
}

void	op_lfork(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		dest;

	(void)timer;
	dest = proc->pc + read_mem(mem, (proc->pc) + 1, 2);
	proc_add(lst_proc, proc_dup(proc, dest));
	(proc->pc) += 3;
}

void	op_aff(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int	ocp;
	char			rg;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (ARG(ocp, 1) == A_REG && !ARG(ocp, 2) && !ARG(ocp, 3))
	{
		rg = read_mem(mem, proc->pc + 2, 1);
		if (rg > 0 && rg <= REG_NUMBER)
			ft_putchar((char)((proc->reg)[rg - 1] % 256));
	}
	(proc->pc) += 3;
}
