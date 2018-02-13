/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pointer_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:16:51 by allauren          #+#    #+#             */
/*   Updated: 2018/02/13 16:50:21 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_set_fd(char *str, t_param *p, t_options *s)
{

	ft_printf("coucou\n");
	(void)s;
	if (p->nb_champ < 4)
		if((p->fd[p->nb_champ++] = open(str, O_RDONLY)) > 0)
			return ;
	ft_perror("invalid .cor\n");
}

void	ft_set_option(char *str, t_param *p, t_options *s)
{
	(void)str;
	(void)p;
	(void)s;
}

void	ft_set_optionparam(char *str, t_param *p, t_options *s)
{
	(void)str;
	(void)p;
	(void)s;
}

void	ft_error(char *str, t_param *p, t_options *s)
{
	(void)str;
	(void)p;
	(void)s;
	ft_perror("invalid param\n");
}

void	ft_set_map(t_map *m, t_param *p)
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
			ft_fill_map(m->map, p->buf + p->test, (MEM_SIZE / p->nb_champ) * i, p->ret - p->test);
	//		ft_printf("coucou\n\n\n\n\n");
	//		print_memory(p->buf  ,p->ret / 4);
		//	print_memory(p->buf + p->test , (p->ret - p->test * 4));
		//	ft_print_map(p->buf + p->test, mapp, 0, (p->ret - p->test * 4));
		//	ft_printf("\n\n\n\nDebut de la map\n%s\n",mapp);
		}
		else
		{
			ft_printf("%d\n", p->ret);
			ft_perror("read fail\n");
		}
			print_memory(m->map , MEM_SIZE);
}
