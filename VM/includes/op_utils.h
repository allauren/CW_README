/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:02:38 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/06 11:29:30 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_UTILS_H
# define OP_UTILS_H

# include "memory.h"
# include "process.h"

# define ARG(opc, pos) ((opc & (3 << (pos * 2))) >> (pos * 2))
# define A_REG 1
# define A_DIR 2
# define A_IND 3

unsigned int	read_mem(t_memory *mem, int ind, int size);
void			write_mem(t_memory *mem, unsigned int ind, unsigned int val);
unsigned int	ind_sum_ldi(unsigned int ocp, t_memory *mem, t_proc *proc);
unsigned int	ind_sum_sti(unsigned int ocp, t_memory *mem, t_proc *proc);

#endif
