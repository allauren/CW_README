/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pointer_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:16:51 by allauren          #+#    #+#             */
/*   Updated: 2018/03/03 09:49:15 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_set_fd(char *str, t_param *p, t_options *s)
{
	ft_printf("je passe ici et je met le fd\n");
	(void)s;
	if (p->nb_champ < 4)
	{
		p->opt.param = 0;
		if ((p->nchamp[p->nb_champ++].fd = open(str, O_RDONLY)) > 0)
			return ;
	}
	ft_perror("invalid .cor\n");
}

void	ft_set_option(char *str, t_param *p, t_options *s)
{
	static int		param;

	ft_printf("je passe ici et je met option\n");
	if (ft_strequ("-n", str) && (param = 1))
		ft_isactive(p->opt.sp, &p->opt.sp, 1);
	if (param)
		p->opt.param = 1;
	(void)s;
}

void	ft_set_optionparam(char *str, t_param *p, t_options *s)
{
	char		*tmp;

	ft_printf("je passe ici et je met le param\n");
	if (!p->param && p->opt.sp)
	{
		p->param = 1;
		p->opt.param = 0;
		p->opt.sp = 0;
		if ((tmp = ft_trim_int(str)))
		{
			if (((unsigned int)ft_atol(tmp)) <= 4294967295
					&& (p->nchamp[p->nb_champ].param = 1))
				p->nchamp[p->nb_champ].num_player = (unsigned int)ft_atol(tmp);
			else
				ft_perror("invalid param\n");
			ft_strdel(&tmp);
		}
		else
			ft_perror("invalid number\n");
	}
	(void)s;
}

void	ft_error(char *str, t_param *p, t_options *s)
{
	(void)str;
	(void)p;
	(void)s;
	ft_perror("error param\n");
}
