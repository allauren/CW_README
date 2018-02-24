/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:45:56 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/24 14:24:04 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "vm.h"

int			read_mem(t_memory *mem, int ind, int size)
{
	int				res;

	res = 0;
	while (size > 0)
	{
		res = (res << 8) + (int)((mem->memory)[ind % MEM_SIZE]);
		(ind)++;
		size--;
	}
	return (res);
}

void		write_mem(t_memory *mem, int ind, int val)
{
	int				i;
	unsigned char	b;

	i = -1;
	while (++i < 4)
	{
		b = (unsigned char)((val >> ((3 - i) * 16)) & 0xFF);
		(mem->memory)[(ind + i) % MEM_SIZE] = b;
	}
}
