/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:20:48 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/10 13:23:03 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft_adv.h"

typedef struct		s_champ
{
	int				id;
	char			*name;
	char			*cor_file;
	unsigned int	last_live;
}					t_champ;

typedef struct		s_process
{
	unsigned char	*reg;
	int				pc;
	t_bool			carry;
	int				lives_cycle;
}					t_process;

typedef struct		s_vm
{
	unsigned char	*memory;
	t_champ			*champs;
	t_list			*process;
	int				nb_champ;
	unsigned int	cycle;
	unsigned int	next_check;
	unsigned int	to_die;
	unsigned int	failed_check;
}					t_vm;

void				vm_init(t_vm *vm, int argc, char *argv[]);
t_bool				vm_write_champ(t_vm *vm, t_champ *champ);
void				vm_cycle(t_vm *vm);

#endif
