/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 10:37:56 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/24 17:58:01 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
# include "old_vm.h"

typedef struct			s_op
{
	char				*name;
	int					nb_arg;
	int					*args;
	unsigned char		op_code;
	int					sleep;
	char				*desc;
	t_bool				carry;
	t_bool				size_dir;
	void				(*fun)(t_vm *, t_proc *)
}						t_op;

extern t_op			g_op_tab[17];

void					op_live(t_vm *vm, t_proc *proc);
void					op_ld(t_vm *vm, t_proc *proc);
void					op_st(t_vm *vm, t_proc *proc);
void					op_add(t_vm *vm, t_proc *proc);
void					op_sub(t_vm *vm, t_proc *proc);
void					op_and(t_vm *vm, t_proc *proc);
void					op_or(t_vm *vm, t_proc *proc);
void					op_xor(t_vm *vm, t_proc *proc);
void					op_zjmp(t_vm *vm, t_proc *proc);
void					op_ldi(t_vm *vm, t_proc *proc);
void					op_sti(t_vm *vm, t_proc *proc);
void					op_fork(t_vm *vm, t_proc *proc);
void					op_lld(t_vm *vm, t_proc *proc);
void					op_lldi(t_vm *vm, t_proc *proc);
void					op_lfork(t_vm *vm, t_proc *proc);
void					op_aff(t_vm *vm, t_proc *proc);

#endif
