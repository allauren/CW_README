/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:49:35 by allauren          #+#    #+#             */
/*   Updated: 2018/02/13 16:09:06 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
#define HEX "0123456789abcdef"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft_adv.h"
#include "op.h"

typedef struct			s_map
{	
	unsigned char		map[MEM_SIZE];
	char				mapp[MEM_SIZE * 4];
	int					lives_in_period;
	int					last_live_player;
	int					cycle;
	int					cum_cycle;
	int					cycles_to_die;
}						t_map;

typedef struct			s_options
{
	int		visu;
	int		param;
}						t_options;

typedef struct			s_param
{
	int fd[4];
	int ret;
	int nb_champ;
	unsigned char buf[200000];
	int test;
	t_options	opt;
}						t_param;

/*
 * Utils to display
 */
void	ft_fill_map(unsigned char *map, unsigned char *buf, int start, int stop);
void    print_memory(const void *addr, size_t size);
/*
 * Parsing functions
 */
void		ft_parse_options(int argc,char **argv,t_param *p, t_map *m);
void	ft_set_fd(char *str, t_param *p, t_options *s);
void	ft_set_option(char *str, t_param *p, t_options *s);
void	ft_set_optionparam(char *str, t_param *p, t_options *s);
void	ft_error(char *str, t_param *p, t_options *s);
void	ft_set_map(t_map *m, t_param *p);
#endif
