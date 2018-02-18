/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:20:48 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/16 17:58:46 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft_adv.h"
# include "op.h"
# include "process.h"

typedef struct		s_champ
{
	unsigned int	id;
	char			*name;
	char			*cor_file;
	unsigned int	last_live;
}					t_champ;
/*
void				vm_init(t_vm *vm, int argc, char *argv[]);
t_bool				vm_write_champ(t_vm *vm, t_champ *champ);
void				vm_cycle(t_vm *vm);
void				vm_itsover(t_vm *vm, t_bool error);
*/
#endif
