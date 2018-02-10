/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:03:20 by allauren          #+#    #+#             */
/*   Updated: 2018/02/10 17:35:19 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include "../includes/op.h"

void    ft_printhex(int n, unsigned char **ptr, int *i)
{
	int c;

	if (n >= 16)
		ft_printhex(n / 16, *(ptr[i + 1]), i + 1);
	c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
	ft_putchar(c);
	*ptr[i] = c;
	*i++;
}

void    print_memory(const void *addr, size_t size, unsigned char *ptr)
{
	unsigned char *t = (unsigned char *)addr;
	size_t        i = 0;
	int            col;

	if (!(ptr = ft_memmalloc(sizeof(unsigned char) * size * 16)))
	while (i < size)
	{
		col = -1;
		while (++col < 16)
		{
			if (i < size)
			{
				if (t[i] < 16)
					ft_putchar('0');
				ft_printhex(t[i], &ptr);
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
