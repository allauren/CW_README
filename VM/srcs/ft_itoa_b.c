/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:54:27 by gsmith            #+#    #+#             */
/*   Updated: 2018/03/03 08:26:10 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_isolatebufc(UC *buf, char *cpy, int start, int end)
{
	int		i;

	i = 0;
	while(start < end)
	{
		//cpy[i++] = HEX[buf[start] / 16];
		//cpy[i++] = HEX[buf[start] % 16];
		cpy[i++] = buf[start];
		start++;
	}
}

void	ft_check_magic(t_memory *m, t_param *p,int i)
{
	char	*ret;
	int		len2;

	ft_isolatebuf(p->buf, m->magic, 0, 4);
	ret = ft_itoa_b(m->magic, B16);
	ft_printf("%d \n", ft_atoi_base(m->magic, 16));
	//if (COREWAR_MAGIC != (p->nchamp[i].head.magic = ft_atoi_base(ret, 16)))
	//		ft_perror("invalid magic\n");
	ft_strdel(&ret);
}

void	ft_check_prog_size(t_memory *m, t_param *p, int i)
{
	char	*ret;
	int		len2;

	ft_isolatebuf(p->buf, m->size, 132, 140);
	ft_printf("la%sla\n\n", m->size);
	p->nchamp[i].head.prog_size = (unsigned int)ft_atoi_base(ret, 16);
	ft_strdel(&ret);
}
