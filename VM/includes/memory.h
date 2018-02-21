/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:49:35 by allauren          #+#    #+#             */
/*   Updated: 2018/02/18 17:52:09 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H
# define HEX "0123456789abcdef"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft_adv.h"
# include "vm.h"

typedef struct			s_memory
{	
	unsigned char		memory[MEM_SIZE];
	char				memoryp[MEM_SIZE * 4];
	t_chmp				chp[4];
	int					nb_champ;
}						t_memory;

typedef struct			s_options
{
	int		visu;
	int		param;
	int		sp;
}						t_options;

typedef struct			s_chmp
{
	int					fd;
	char				*name;
	unsigned int		num_player;
	unsigned int		last_live;
}						t_chmp;

typedef struct			s_param
{
	t_memory		mem[4];
	int				fd[4];
	int				ret;
	int				nb_champ;
	unsigned char	buf[20000];
	int				test;
	int				param;
	t_options		opt;
}						t_param;

/*
 * Utils to display
 */
void		ft_fill_memory(unsigned char *me, unsigned char *b, int strt, int stop);
void		print_memory(const void *addr, size_t size);
/*
 * Parsing functions
 */
void		ft_parse_options(int argc, char **argv,t_param *p, t_memory *m);
void		ft_set_fd(char *str, t_param *p, t_options *s);
void		ft_set_option(char *str, t_param *p, t_options *s);
void		ft_set_optionparam(char *str, t_param *p, t_options *s);
void		ft_error(char *str, t_param *p, t_options *s);
void		ft_set_memory(t_memory *m, t_param *p);
void		ft_isactive(int i, int *j, int value);
#endif
