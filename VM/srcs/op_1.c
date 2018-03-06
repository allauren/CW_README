/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/06 14:17:48 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "process.h"
#include "op.h"
#include "vm.h"

void	op_live(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int	n_player;
	int				i;
	t_chmp			*chmp;

	ft_putendl("hello there");
	(void)lst_proc;
	n_player = read_mem(mem, proc->pc + 1, 4);
	i = 0;
	while (i < mem->nb_champ && n_player != (mem->chp)[i].num_player)
		i++;
	if (i != mem->nb_champ)
	{
		(proc->lives)++;
		chmp = &((mem->chp)[i]);
		chmp->last_live = timer->cycle;
		ft_printf("Player %d (%s) is said to be alive\n", n_player, chmp->name);
	}
	(proc->pc) += 5;
}

void	op_ld(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		rg;
	unsigned int		val;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (!ARG(ocp, 1) && ARG(ocp, 2) == A_REG
			&& (ARG(ocp, 3) == A_DIR || ARG(ocp, 3) == A_IND))
	{
		if (ARG(ocp, 3) == A_DIR)
			val = read_mem(mem, proc->pc + 2, 4);
		else
			val = read_mem(mem,
					proc->pc + (read_mem(mem, proc->pc + 2, 2) % IDX_MOD), 4);
		rg = read_mem(mem, proc->pc + 2 + (ARG(ocp, 3) == A_DIR ? 4 : 2), 1);
		if (rg <= REG_NUMBER && rg > 0)
		{
			(proc->reg)[rg - 1] = val;
			(proc->carry) = !(val);
		}
	}
	(proc->pc) += 3 + (ARG(ocp, 3) == A_DIR ? 4 : 2);
}

void	op_st(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned int		ocp;
	unsigned int		dest;
	unsigned int		val;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	if (!ARG(ocp, 1) && (ARG(ocp, 2) == A_REG || ARG(ocp, 2) == A_IND)
			&& ARG(ocp, 3) == A_REG)
	{
		val = read_mem(mem, proc->pc + 2, 1);
		val = (val <= REG_NUMBER && val > 0) ? (proc->reg)[val - 1] : 0;
		dest = read_mem(mem, proc->pc + 3, (ARG(ocp, 2) == A_REG ? 1 : 2));
		if (ARG(ocp, 2) == A_REG && dest <= REG_NUMBER && dest > 0)
			(proc->reg)[dest - 1] = val;
		else if (ARG(ocp, 2) == A_IND)
			write_mem(mem, proc->pc + (dest % IDX_MOD), val);
		(proc->carry) = !(val);
	}
	(proc->pc) += 3 + (ARG(ocp, 2) == A_REG ? 1 : 2);
}

void	op_add(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
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
				+ (proc->reg)[rg[1] - 1];
			(proc->carry) = !((proc->reg)[rg[2]]);
		}
	}
	(proc->pc) += 5;
}
