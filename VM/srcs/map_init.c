/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 04:05:03 by allauren          #+#    #+#             */
/*   Updated: 2018/02/27 16:48:46 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
void	ft_sort_champ(t_param *p)
{
	int		i;
	t_chmp	temp;

	i = 0;
	while (i < 3 && p->nchamp[i].fd)
	{
		ft_printf("coucou");
		if (p->nchamp[i].num_player > p->nchamp[i + 1].num_player && p->nchamp[i + 1].fd)
		{
			if (p->nchamp[i].num_player == p->nchamp[i + 1].num_player)
				ft_perror("2 times the same number\n");
			temp = p->nchamp[i + 1];
			p->nchamp[i + 1] = p->nchamp[i];
			p->nchamp[i] = temp;
			i = 0;
		}
		else
			i++;
	}

}
void	ft_set_memory(t_memory *m, t_param *p)
{
	int i;

	i = -1;
	ft_sort_champ(p);
	ft_printf("%d %d %d %d", p->nchamp[0].num_player, p->nchamp[1].num_player, p->nchamp[2].num_player, p->nchamp[3].num_player);
	while (++i < p->nb_champ)
		if(((p->ret = read(p->nchamp[i].fd, p->buf, 200000)) > 0))
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
}
