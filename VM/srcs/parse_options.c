/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:19:40 by allauren          #+#    #+#             */
/*   Updated: 2018/02/12 16:37:01 by allauren         ###   ########.fr       */
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
	if (ft_iscor(argv[argc]) && i++)
		return (p->opt->param == 1 ? 1 : 0);
	if(argv[argc][0] == '-')
		return (3);
	if (p->opt->param)
		return (2);
	if (argc < 1)
		return (4)
	return (0);
}


void		ft_parse_options(int argc,char **argv,t_param *p, t_map *m)
{
	static void (*tab[4])(char*, t_parse*, t_options*) = {ft_error, ft_comment, ft_room, ft_link};
	while(argc > 1)
	{
		tab[ft_select_option(argv, argc)](argv[argc], p, t_map *m)
	}
	ft_set_map(map, p);

}
