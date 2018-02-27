/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/27 18:04:05 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_lld(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}

void	op_lldi(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}

void	op_lfork(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}

void	op_aff(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	int		ocp;
	char	rg;

	(void)lst_process;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (ARG(ocp, 1) == A_REG && !ARG(ocp, 2) && !ARG(ocp, 3))
	{
		rg = read_mem(mem, proc->pc + 2, 1);
		if (rg >= 0 && rg < mem->nb_champ)
			ft_putchar((char)((proc->reg)[rg] % 256));
	}
	(proc->pc) += 3;
}
