/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:03:20 by allauren          #+#    #+#             */
/*   Updated: 2018/02/08 18:13:33 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "../includes/op.h"

void    ft_printhex(int n)
{
	int c;

	if (n >= 16)
		ft_printhex(n / 16);
	c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	ft_putchar(c);
}

void    ft_printchars(unsigned char c)
{
	ft_putchar((c > 31 && c < 127) ? c : '.');
}

void    print_memory(const void *addr, size_t size)
{
	unsigned char *t = (unsigned char *)addr;
	size_t        i = 0;
	int            col;

	while (i < size)
	{
		col = -1;
		while (++col < 16)
		{
			if (i < size)
			{
				if (t[i] < 16)
					ft_putchar('0');
				ft_printhex(t[i]);
			}
			else
				ft_putstr(" ");
			ft_putchar(' ');
			i++;
		}
		col = -1;
		ft_printf("je suis la valeur au saut de ligne%d", i);
		ft_putchar('\n');
	}
}
