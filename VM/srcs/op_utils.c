/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:45:56 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/21 18:07:17 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "process.h"

int			read_mem(t_memory *mem, t_proc *proc, int size)
{
	unsigned char	op;
	int				res;
	int				i;

	op = (mem->memory) + proc->pc;
	(proc->pc) += size;
	res = 0;
	i = -1;
	while (++i < size)
		res = res << 8 + (int)(op[i]);
	return (res);
}
