/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:49:35 by allauren          #+#    #+#             */
/*   Updated: 2018/03/03 09:59:17 by allauren         ###   ########.fr       */
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

typedef struct			s_chmp
{
	int					fd;
	char				*name;
	t_bool				param;
	unsigned int		num_player;
	unsigned int		last_live;
	t_header			head;
}						t_chmp;

typedef struct			s_memory
{
	UC					memory[MEM_SIZE];
	char				memoryp[MEM_SIZE * 4];
	char				magic[9];
	char				size[17];
	t_chmp				chp[4];
	int					nb_champ;
}						t_memory;

typedef struct			s_options
{
	int		visu;
	int		param;
	int		sp;
}						t_options;

typedef struct			s_param
{
	t_chmp			nchamp[4];
	int				fd[4];
	int				ret;
	int				nb_champ;
	UC	buf[SIZE_CHAMP + 1];
	int				test;
	int				param;
	t_options		opt;
}						t_param;
typedef struct		s_atoi
{
	long	i;
	long	jack;
	int	neg;
	int	j;
	int	fin;
}					t_atoi;

/*
 ** Utils to display
 */
void					ft_fill_memory(UC *me,
		UC *b, int strt, int stop);
int						ft_atoi_base(const char *l, int base);
void					print_memory(const void *addr, size_t size);
/*
 ** Parsing functions
 */
void					ft_parse_options(int argc,
		char **argv, t_param *p, t_memory *m);
void					ft_set_fd(char *str, t_param *p, t_options *s);
void					ft_set_option(char *str, t_param *p, t_options *s);
void					ft_set_optionparam(char *str, t_param *p, t_options *s);
void					ft_error(char *str, t_param *p, t_options *s);
void					ft_set_memory(t_memory *m, t_param *p);
void					ft_isactive(int i, int *j, int value);
void					corewar_usage(void);
/*
 ** map init functions
 */
void	ft_isolatebuf(UC *buf, UC *cpy, int start, int end);
void	ft_check_magic(t_memory *m, t_param *p, int i);
void	ft_check_prog_size(t_memory *m, t_param *p, int i);

#endif
