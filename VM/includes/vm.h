/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:20:48 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/12 14:15:16 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft_adv.h"
# include "process.h"

typedef structs_champ
{
	int				id;
	int				mem_orig;
	char			*name;
	char			*cor_file;
	unsigned int	last_live;
}t_champ;

typedef		struct	s_vm
{
	unsigned char		*memory;
	t_champ				*champs;
	t_proc				*process;
	int					nb_champ;
	unsigned int		cycle;
	unsigned int		next_check;
	unsigned int		to_die;
	unsigned int		failed_check;
}					t_vm;

void	vm_init(t_vm *vm, int argc, char *argv[]);
t_bool	vm_write_champ(t_vm *vm, t_champ *champ);
void	vm_cycle(t_vm *vm);
void	vm_itsover(t_vm *vm, t_bool error);

#endif
