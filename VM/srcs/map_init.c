/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 04:05:03 by allauren          #+#    #+#             */
/*   Updated: 2018/03/03 08:19:58 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

int		ft_ispresentchamp(t_param *p, int value)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (p->nchamp[i].num_player == value && p->nchamp[i].param)
			return (0);
	}
	return (1);
}

void	ft_set_champ_num(t_param *p)
{
	int		i;
	int		value;

	i = -1;
	value = 0;
	while (++i < 4 && p->nchamp[i].fd)
	{
		if (p->nchamp[i].fd && !p->nchamp[i].param)
		{
			while (!ft_ispresentchamp(p, value))
				value++;
			p->nchamp[i].num_player = value;
			p->nchamp[i].param = 1;
		}
	}
}

void	ft_sort_champ(t_param *p)
{
	int		i;
	t_chmp	temp;

	i = 0;
	while (i < 3 && p->nchamp[i].fd)
	{
		if (p->nchamp[i].num_player >= p->nchamp[i + 1].num_player 
				&& p->nchamp[i + 1].fd)
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

void	ft_isolatebuf(UC *buf, UC *cpy, int start, int end)
{
	int		i;

	i = 0;
	while(start < end)
	{
		cpy[i++] = buf[start];
		start++;
	}
}

void	ft_set_memory(t_memory *m, t_param *p)
{
	int i;

	i = -1;
	ft_set_champ_num(p);
	ft_sort_champ(p);
	while (++i < p->nb_champ)
		if(((p->ret = read(p->nchamp[i].fd, p->buf, SIZE_CHAMP + 1)) > 0))
		{
		//	if (p->ret > SIZE_CHAMP)
		//		ft_perror("too long champ\n");
			ft_check_magic(m, p, i);
			ft_isolatebuf(p->buf, (UC*)p->nchamp[i].head.prog_name, 4, 132);
			ft_check_prog_size(m, p, i);
			ft_printf("%s %d\n", p->nchamp[i].head.prog_name, p->nchamp[i].head.prog_size);
			print_memory(&p->buf[132], 8);
			//ft_check_name(m, p, i);
			ft_fill_memory(m->memory, p->buf + 2192, \
					(MEM_SIZE / p->nb_champ) * i, p->ret - 2192);
			close(p->fd[i]);
		}
		else
			ft_perror("read fail\n");
}
