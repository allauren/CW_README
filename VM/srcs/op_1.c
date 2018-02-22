/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:15:44 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/22 12:13:47 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "op.h"

void	op_live(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	unsigned char	op;
	int				n_player;
	t_chmp			*chmp;

	(void)lst_proc;
	(proc->lives)++;
	(proc->pc)++;
	n_player = read_mem(mem, proc, 4) % mem->nb_champ;
	chmp = (mem->chp)[n_player];
	chmp->last_live = timer->cycle;
	ft_printf("Player %d (%s) is said to be alive\n", n_player, chmp->name);
}

void	op_ld(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}

void	op_st(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}

void	op_add(t_memory *mem, t_proc *proc, t_proc **lst_proc, t_timer *timer)
{
	return ;
}
