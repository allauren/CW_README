/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 17:49:35 by allauren          #+#    #+#             */
/*   Updated: 2018/02/12 17:08:07 by allauren         ###   ########.fr       */
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

typedef struct			s_option
{
	int		visu;
	int		param;
}						t_option;

typedef struct			s_param
{
	int fd[4];
	int ret;
	int nb_champ;
	int buf[BUFF_SIZE];
	int test;
	t_option	opt;
}						t_param;

#endif
