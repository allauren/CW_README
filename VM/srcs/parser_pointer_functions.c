/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pointer_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:16:51 by allauren          #+#    #+#             */
/*   Updated: 2018/02/18 16:21:41 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_set_fd(char *str, t_param *p, t_options *s)
{

	(void)s;
	if (p->nb_champ < 4)
	{
		p->opt.param = 0;
		if((p->nchamp[p->nb_champ++].fd = open(str, O_RDONLY)) > 0)
			return ;
	}
	ft_perror("invalid .cor\n");
}

void	ft_set_option(char *str, t_param *p, t_options *s)
{
	int		param;

	if (ft_strequ("-n", str) && (param = 1))
		ft_isactive(p->opt.sp, &p->opt.sp, 1);
	if (param)
		p->opt.param = 1;
	(void)s;
}

void	ft_set_optionparam(char *str, t_param *p, t_options *s)
{
	char		*tmp;

	if (!p->param && p->opt.sp)
	{
		p->param = 1;
		if ((tmp = ft_trim_int(str)))
			if (ft_atoi(tmp) >= 0)
				p->nchamp[p->nb_champ].num_player = ft_atoi(tmp);
			else
				ft_perror("invalid param\n");
		else
				ft_perror("invalid int\n");
	}
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

