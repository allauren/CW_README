/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:20:12 by allauren          #+#    #+#             */
/*   Updated: 2018/02/13 15:54:16 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_fill_map(unsigned char *map, unsigned char *buf, int start, int stop)
{
	int		i;
	int		z;

	i = start;
	z = -1;
	while (++z < stop)
		map[i++] = buf[z];
}
