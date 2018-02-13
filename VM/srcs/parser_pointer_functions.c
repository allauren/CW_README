/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pointer_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:16:51 by allauren          #+#    #+#             */
/*   Updated: 2018/02/12 17:03:13 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_set_fd(char *str, t_param *p, t_options *s)
{

	(void)s;
	if (p->nb_champ < 4)
		if((p->fd[nb_champ++] = open(str, O_RDONLY)) > 0)
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

void	ft_set_map(char *str, t_param *p, t_options *s)
{
	int i;

	i = 0;
	while (p->fd[i++])
		if(((p->ret = read(p->fd[i], buf, BUFF_SIZE)) > 0))
	{
		if (p->ret > (CHAMP_MAX_SIZE * 4))
			ft_perror("champ too long\n");
		ft_printf("je suis ret #%d#\n", ret);
		p->test = 548;
	print_memory(buf + test , (ret - test * 4));
	ft_print_map(buf + test, mapp, 0, (ret - test * 4));
	ft_printf("\n\n\n\nDebut de la map\n%s\n",mapp);
	}


	}
}
