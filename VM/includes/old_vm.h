/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_vm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:20:48 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/18 10:39:54 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OLD_VM_H
# define OLD_VM_H
# include "libft_adv.h"
# include "vm.h"
# include "process.h"

typedef struct		s_champ
{
	unsigned int	id;
	char			*name;
	char			*cor_file;
	unsigned int	last_live;
}					t_champ;

typedef		struct	s_vm
{
	unsigned char		memory[MEM_SIZE];
	t_champ				*champs;
	t_proc				*process;
	int					nb_champ;
	unsigned int		cycle;
	unsigned int		next_check;
	unsigned int		to_die;
	unsigned int		failed_check;
}					t_vm;

#endif
