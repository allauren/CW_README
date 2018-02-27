/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:14:57 by allauren          #+#    #+#             */
/*   Updated: 2018/02/27 16:06:43 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void		ft_isactive(int i, int *j, int value)
{
	if (i)
		ft_perror("invalid parameter\n");
	else 
		*j = value;
}
