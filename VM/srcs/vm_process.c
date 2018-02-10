/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:56:59 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/10 18:54:43 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "op.h"

t_proc				*proc_new(int mem_orig, int pc)
{
	t_proc	*new;

	if (!(new = (t_proc *)malloc(sizeof(t_proc))))
		return (NULL);
	ft_bzero((void *)new, sizeof(t_proc));
	if (!(new->reg = (unsigned char *)malloc(REG_SIZE * REG_NUMBER)))
	{
		free(new);
		return (NULL);
	}
	ft_bzero((void *)(new->reg), REG_SIZE * REG_NUMBER);
	new->mem_orig = mem_orig;
	new->pc = pc;
	return (new);
}

t_proc				*proc_dup(t_proc *proc, int mem_orig, int pc)
{
	t_proc		*new;

	if (!(new = proc_new(mem_orig, pc)))
		return (NULL);
	if (proc)
	{
		new->carry = proc->carry;
		ft_memcpy((void *)(new->reg), (void *)(proc->reg),
				REG_SIZE * REG_NUMBER);
	}
	return (new);
}

void				proc_add(t_proc **proc, t_proc *new_p)
{
	if (new_p && proc)
	{
		new_p->next = *proc;
		*proc = new_p;
	}
}

void				proc_kill(t_proc **proc)
{
	t_proc		*tmp;

	if (proc && *proc)
	{
		free((*proc)->reg);
		tmp = (*proc)->next;
		free(*proc);
		*proc = tmp;
	}
}
