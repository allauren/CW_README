/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 04:05:03 by allauren          #+#    #+#             */
/*   Updated: 2018/02/15 20:16:26 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_set_memory(t_memory *m, t_param *p)
{
	int i;

	i = -1;
	while (++i < p->nb_champ)
		if(((p->ret = read(p->fd[i], p->buf, 200000)) > 0))
		{
	//		if (p->ret > (CHAMP_MAX_SIZE * 4))
	//			ft_perror("champ too long\n");
			ft_printf("je suis ret #%d#\n", p->ret);
			p->test = 548 * 4;
			ft_fill_memory(m->memory, p->buf + p->test, (MEM_SIZE / p->nb_champ) * i, p->ret - p->test);
	//		ft_printf("coucou\n\n\n\n\n");
	//		print_memory(p->buf  ,p->ret / 4);
		//	print_memory(p->buf + p->test , (p->ret - p->test * 4));
		//	ft_print_memory(p->buf + p->test, memoryp, 0, (p->ret - p->test * 4));
		//	ft_printf("\n\n\n\nDebut de la memory\n%s\n",memoryp);
		close(p->fd[i]);
		}
		else
		{
			ft_printf("%d\n", p->ret);
			ft_perror("read fail\n");
		}
			print_memory(m->memory , MEM_SIZE);
}
