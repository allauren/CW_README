/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:04:36 by allauren          #+#    #+#             */
/*   Updated: 2018/03/04 20:38:05 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "memory.h"

int	main(int argc, char *argv[])
{
	t_param		p;
	t_memory	m;
	t_proc		*pc;

	pc = NULL;
	if (argc == 1)
		corewar_usage();
	ft_bzero(&p, sizeof(t_param));
	ft_bzero(&m, sizeof(t_memory));
	ft_parse_options(argc, argv, &p, &m);
	ft_process(&pc, &m, &p);
	ft_printf("registre 0 %d et PC %u\n %p et next %p", pc->reg[0], pc->pc, pc, pc->next);
	print_memory(m.memory, MEM_SIZE);
	return (0);
}
