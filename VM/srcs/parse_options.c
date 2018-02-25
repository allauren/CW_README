/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:19:40 by allauren          #+#    #+#             */
/*   Updated: 2018/02/25 16:23:49 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include <stdlib.h>

void	corewar_usage(void)
{
	ft_putendl("usage: ./corewar [-dump nbr_cycles] \
			<[-n number] champion.cor> ...");
	exit(1);
}

int		ft_iscor(char *str)
{
	int len;

	len = ft_strlen(str);
	return (len > 3 ? ft_strequ(".cor", &str[len - 4]) : 0);
}

static int		ft_select_option(char **argv, int argc, t_param *p)
{
	if (ft_iscor(argv[argc]) && !(p->param = 0))
		return (p->opt.param == 1 ? 0 : 1);
	if(argv[argc][0] == '-')
		return (3);
	if (p->opt.param)
		return (2);
	if (argc < 1)
		return (4);
	return (0);
}


void		ft_parse_options(int argc,char **argv,t_param *p, t_memory *m)
{
	static void (*tab[4])(char*, t_param*, t_options*) =
	{
		ft_error,
		ft_set_fd,
		ft_set_optionparam,
		ft_set_option
	};
	int i;

	i = 1;
	while(i < argc)
	{
		tab[ft_select_option(argv, i, p)](argv[i], p, &p->opt);
		i++;
	}
	if (argc < 1 && p->nb_champ == 0)
		ft_perror("no champion\n");
	ft_printf("coucou ici");
	ft_set_memory(m, p);
}
