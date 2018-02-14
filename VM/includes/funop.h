/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funop.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:43:49 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/14 13:16:43 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNOP_H
# define FUNOP_H
# include "vm.h"

typedef struct			s_funop
{
	unsigned char		op_code;
	void				(*fun)(t_vm *, t_proc *)
}						t_funop;

extern t_funop			g_funop[16];

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
