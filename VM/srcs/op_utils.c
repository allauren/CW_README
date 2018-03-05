/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:45:56 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/05 16:23:44 by gsmith           ###   ########.fr       */
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

void			write_mem(t_memory *mem, unsigned int ind, unsigned int val)
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

unsigned int	ind_sum(unsigned int ocp, t_memory *mem, t_proc *proc)
{
	unsigned int		rg;
	unsigned int		ind;

	if (ARG(ocp, 3) == A_REG)
	{
		rg = read_mem(mem, (proc->pc) + 2, 1);
		ind = (rg > 0 && rg <= REG_NUMBER) ? (proc->reg)[rg - 1] : 0;
	}
	else
		ind = read_mem(mem, (proc->pc) + 2, 2);
	if (ARG(ocp, 3) == A_IND)
		ind = read_mem(mem, ind, 4);
	if (ARG(ocp, 2) == A_REG)
	{
		rg = read_mem(mem, proc->pc + 2
				+ (ARG(ocp, 3) == A_REG ? 1 : 2), 1);
		ind += (rg > 0 && rg <= REG_NUMBER) ? (proc->reg)[rg - 1] : 0;
	}
	else
		ind += read_mem(mem, proc->pc + 2
				+ (ARG(ocp, 3) == A_REG ? 1 : 2), 2);
	return (ind);
}
