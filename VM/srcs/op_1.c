/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/22 16:46:06 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"

void	op_live(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned char	op;
	int				n_player;
	t_chmp			*chmp;

	(void)lst_proc;
	(proc->lives)++;
	n_player = read_mem(mem, proc->pc + 5, 4);
	(proc->pc) += 5;
	if (n_player < mem->nb_champ)
	{
		chmp = (mem->chp)[n_player];
		chmp->last_live = timer->cycle;
		ft_printf("Player %d (%s) is said to be alive\n", n_player, chmp->name);
	}
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
			val = read_mem(mem, proc->pc + read_mem(mem, proc-pc + 2, 2) % , 4);
		proc->carry = !(val);
	}
}

void	op_st(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}

void	op_add(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}
