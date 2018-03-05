/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 14:34:14 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/01 16:51:24 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H
# include "libft_adv.h"
# include "vm.h"

typedef struct		s_proc
{
	unsigned int		reg[REG_NUMBER];
	unsigned int		pc;
	t_bool				carry;
	unsigned int		sleep;
	unsigned int		lives;
	struct s_proc		*next;
}					t_proc;

t_proc				*proc_new(unsigned int pc);
t_proc				*proc_dup(t_proc *proc, unsigned int pc);
void				proc_add(t_proc **proc, t_proc *new_p);
void				proc_kill(t_proc **proc);
int					proc_alive(t_proc **proc);

#endif
