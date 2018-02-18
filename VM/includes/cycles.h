/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycles.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmith <gsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:25:53 by gsmith            #+#    #+#             */
/*   Updated: 2018/02/15 15:54:31 by gsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLES_H
# define CYCLES_H
# include "libft_adv.h"

typedef struct		s_timer
{
	unsigned int		cycle;
	unsigned int		next_check;
	unsigned int		to_die;
	unsigned int		fail_check;
}					t_timer;

t_timer				cycle_init(void);
t_bool				cycle_count(t_timer *timer);

#endif