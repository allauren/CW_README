/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:20:48 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/09 18:04:31 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft_adv.h"

typedef struct		s_champ
{
	int				id;
	char			*name;
	unsigned int	last_live;
}					t_champ;

typedef struct		s_process
{
	unsigned char	*reg;
	int				pc;
	t_bool			carry;
}					t_process;

typedef struct		s_vm
{
	unsigned char	*memory;
	t_list			*process;
	unsigned int	cycle;
	unsigned int	next_check;
	unsigned int	last_check;
	unsigned int	failed_checkr
}					t_vm;

void				vm_init(t_vm *vm, t_list *champs);
#endif
