/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/05 16:55:32 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_sub(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg[3];

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) == A_REG && ARG(ocp, 3) == A_REG)
	{
		rg[0] = read_mem(mem, proc->pc + 2, 1);
		rg[1] = read_mem(mem, proc->pc + 3, 1);
		rg[2] = read_mem(mem, proc->pc + 4, 1);
		if (rg[0] > 0 && rg[1] > 0 && rg[2] > 0 && rg[0] <= REG_NUMBER
				&& rg[1] <= REG_NUMBER && rg[2] <= REG_NUMBER)
		{
			(proc->reg)[rg[2] - 1] = (proc->reg)[rg[0] - 1]
				- (proc->reg)[rg[1] - 1];
			(proc->carry) = !((proc->reg)[rg[2]]);
		}
	}
	(proc->pc) += 5;
}

void	op_and(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg[3];

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) == A_REG && ARG(ocp, 3) == A_REG)
	{
		rg[0] = read_mem(mem, proc->pc + 2, 1);
		rg[1] = read_mem(mem, proc->pc + 3, 1);
		rg[2] = read_mem(mem, proc->pc + 4, 1);
		if (rg[0] > 0 && rg[1] > 0 && rg[2] > 0 && rg[0] <= REG_NUMBER
				&& rg[1] <= REG_NUMBER && rg[2] <= REG_NUMBER)
		{
			(proc->reg)[rg[2] - 1] = (proc->reg)[rg[0] - 1]
				& (proc->reg)[rg[1] - 1];
			(proc->carry) = !((proc->reg)[rg[2]]);
		}
	}
	(proc->pc) += 5;
}

void	op_or(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg[3];

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) == A_REG && ARG(ocp, 3) == A_REG)
	{
		rg[0] = read_mem(mem, proc->pc + 2, 1);
		rg[1] = read_mem(mem, proc->pc + 3, 1);
		rg[2] = read_mem(mem, proc->pc + 4, 1);
		if (rg[0] > 0 && rg[1] > 0 && rg[2] > 0 && rg[0] <= REG_NUMBER
				&& rg[1] <= REG_NUMBER && rg[2] <= REG_NUMBER)
		{
			(proc->reg)[rg[2] - 1] = (proc->reg)[rg[0] - 1]
				| (proc->reg)[rg[1] - 1];
			(proc->carry) = !((proc->reg)[rg[2]]);
		}
	}
	(proc->pc) += 5;
}

void	op_xor(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg[3];

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) == A_REG && ARG(ocp, 3) == A_REG)
	{
		rg[0] = read_mem(mem, proc->pc + 2, 1);
		rg[1] = read_mem(mem, proc->pc + 3, 1);
		rg[2] = read_mem(mem, proc->pc + 4, 1);
		if (rg[0] > 0 && rg[1] > 0 && rg[2] > 0 && rg[0] <= REG_NUMBER
				&& rg[1] <= REG_NUMBER && rg[2] <= REG_NUMBER)
		{
			(proc->reg)[rg[2] - 1] = (proc->reg)[rg[0] - 1]
				^ (proc->reg)[rg[1] - 1];
			(proc->carry) = !((proc->reg)[rg[2]]);
		}
	}
	(proc->pc) += 5;
}
