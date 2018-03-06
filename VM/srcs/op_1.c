/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/06 16:53:40 by gsmith           ###   ########.fr       */
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

	(void)lst_proc;
	(void)timer;
	n_player = read_mem(mem, proc->pc + 1, 4);
	i = 0;
	while (i < mem->nb_champ && n_player != (mem->chp)[i].num_player)
		i++;
	if (i != mem->nb_champ)
	{
		(proc->lives)++;
		chmp = &((mem->chp)[i]);
		mem->last_live = chmp;
		ft_printf("Player %d (%s) is said to be alive\n", n_player,
				(chmp->head).prog_name);
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
	unsigned int		val[3];
	unsigned int		offset;

	(void)lst_proc;
	(void)timer;
	ocp = read_mem(mem, proc->pc + 1, 1);
	offset = 2;
	if (ARG(ocp, 1) == A_REG && ARG(ocp, 2) && ARG(ocp, 3))
	{
		val[0] = read_log_arg(mem, proc, ARG(ocp, 3), &offset);
		val[1] = read_log_arg(mem, proc, ARG(ocp, 2), &offset);
		val[2] = read_mem(mem, proc->pc + offset, 1);
		(proc->reg)[val[2] - 1] = val[0] + val[1];
		(proc->carry) = !((proc->reg)[val[2] - 1]);
	}
	(proc->pc) += offset + 1;
}
