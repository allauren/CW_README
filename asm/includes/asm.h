/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 13:32:51 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/08 12:59:49 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <fcntl.h>
# include "libft.h"
# include "op.h"

typedef struct					s_op
{
	char						*name;
	int							nb_params;
	int							param_types[4];
	int							opcode;
	int							nb_cycles;
	char						*description;
	int							has_pcode;
	int							has_idx;
}								t_op;
#endif
