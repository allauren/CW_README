/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:45:56 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/22 12:05:10 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"

int			read_mem(t_memory *mem, t_proc *proc, int size)
{
	int				res;

	res = 0;
	while (size > 0)
	{
		res = res << 8 + (int)((mem->memory)[proc->pc]);
		(proc->pc)++;
		size--;
	}
	return (res);
}
