/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/24 16:46:03 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_live(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned char	op;
	int				n_player;
	t_chmp			*chmp;

	(void)lst_proc;
	(proc->lives)++;
	n_player = read_mem(mem, proc->pc + 5, 4);
	if (n_player < mem->nb_champ)
	{
		chmp = (mem->chp)[n_player];
		chmp->last_live = timer->cycle;
		ft_printf("Player %d (%s) is said to be alive\n", n_player, chmp->name);
	}
	(proc->pc) += 5;
}

void	op_ld(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	int		ocp;
	int		rg;
	int		val;

	(void)lst_proc;
	(void)timer;
	opc = read_mem(mem, proc->pc + 1, 1);
	if (!ARG(opc, 1) && ARG(opc, 2) == A_REG
			&& (ARG(opc, 3) == A_DIR || ARG(opc, 3) == A_IND))
	{
		if (ARG(opc, 3) == A_DIR)
			val = read_mem(mem, proc->pc + 2, 4);
		else
			val = read_mem(mem, proc->pc + read_mem(mem, proc->pc + 2, 2), 4);
		rg = read_mem(mem, proc->pc + 2 + (ARG(opc, 3) == A_DIR ? 4 : 2), 1);
		if (rg < REG_NUMBER && rg >= 0)
		{
			(proc->reg)[rg] = val;
			(proc->carry) = !(val);
		}
	}
	(proc->pc) += 3 + (ARG(opc, 3) == A_DIR ? 4 : 2);
}

void	op_st(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	int		ocp;
	int		dest;
	int		val;

	(void)lst_proc;
	(void)timer;
	opc = read_mem(mem, proc->pc + 1, 1);
	if (!ARG(opc, 1) && (ARG(opc, 2) == A_REG || ARG(opc, 2) == A_IND)
			&& ARG(opc, 3) == A_REG)
	{
		val = read_mem(mem, proc->pc + 2, 1);
		val = (val < REG_NUMBER && val >= 0) ? (proc->reg)[val] : 0;
		dest = read_mem(mem, proc->pc + 3, (ARG(opc, 2) == A_REG ? 1 : 2));
		if (ARG(opc, 2) == A_REG && dest < REG_NUMBER && dest >= 0)
			(proc->reg)[dest] = val;
		else if (ARG(opc, 2) == A_IND)
			write_mem(mem, proc->pc + (dest % IDX_MOD), val);
		(proc->carry) = !(val);
	}
	(proc->pc) += 3 + (ARG(opc, 2) == A_REG ? 1 : 2);
}

void	op_add(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}
