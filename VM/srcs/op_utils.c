/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:45:56 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/28 15:59:08 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"
#include "vm.h"

unsigned int	read_mem(t_memory *mem, int ind, int size)
{
	unsigned int	res;

	res = 0;
	while (size > 0)
	{
		res = (res << 8) + (unsigned int)((mem->memory)[ind % MEM_SIZE]);
		(ind)++;
		size--;
	}
	return (res);
}

void		write_mem(t_memory *mem, unsigned int ind, unsigned int val)
{
	unsigned int	i;
	unsigned char	b;

	i = -1;
	while (++i < 4)
	{
		b = (unsigned char)((val >> ((3 - i) * 16)) & 0xFF);
		(mem->memory)[(ind + i) % MEM_SIZE] = b;
	}
}
