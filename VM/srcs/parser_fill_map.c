/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fill_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:20:12 by allauren          #+#    #+#             */
/*   Updated: 2018/02/18 16:18:15 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	ft_fill_memory(unsigned char *memory, unsigned char *buf, int start, int stop)
{
	int		i;
	int		z;

	i = start;
	z = -1;
	while (++z < stop)
		memory[i++] = buf[z];
}
