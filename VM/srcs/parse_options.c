/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:19:40 by allauren          #+#    #+#             */
/*   Updated: 2018/02/13 16:50:39 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_usage(void)
{
	ft_printf("Usage : ./corewar <champion.cor> <...>\n");
}

int		ft_iscor(char *str)
{
	int len;

	len = ft_strlen(str);
	return (len > 3 ? ft_strequ(".cor", &str[len - 4]) : 0);
}

static int		ft_select_option(char **argv, int argc, t_param *p)
{
	static int	i = 0;
	
	if (argc < 1 && !i)
		ft_perror("no champion\n");
	if (ft_iscor(argv[argc]) && ++i)
		return (p->opt.param == 1 ? 0 : 1);
	if(argv[argc][0] == '-')
		return (3);
	if (p->opt.param)
		return (2);
	if (argc < 1)
		return (4);
	return (0);
}


void		ft_parse_options(int argc,char **argv,t_param *p, t_map *m)
{
	static void (*tab[4])(char*, t_param*, t_options*) = {ft_error, ft_set_fd, ft_set_optionparam, ft_set_option};
	while(argc-- > 1)
	{
		tab[ft_select_option(argv, argc, p)](argv[argc], p, &p->opt);
	}
	ft_set_map(m, p);

}
