/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 12:02:38 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/22 12:04:31 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_UTILS_H
# define OP_UTILS_H

#include "memory.h"
#include "process.h"

int			read_mem(t_memory *mem, t_proc *proc, int size);

#endif
