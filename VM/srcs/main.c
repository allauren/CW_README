/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:04:36 by allauren          #+#    #+#             */
/*   Updated: 2018/02/15 19:09:07 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "op.h"
# include "memory.h"

void	ft_print_memory(unsigned char *memory, char *memoryp, int start, int size)
{
	int i;
	int	j;

	j = 0;
	i = 0 ;
	while(++i < size + 1)
	{
		memoryp[start++] = HEX[memory[i - 1] / 16];
		memoryp[start++] = HEX[memory[i - 1] % 16];
		memoryp[start++] = ' ';
		if(!(i % 64) && i >= 64)
			memoryp[start++] = '\n';
	}
}

int main(int argc, char *argv[])
{
	t_param		p;
	t_memory		m;

	if (argc == 1)
		ft_printf("nique toi les arguments\n");
	ft_bzero(&p, sizeof(t_param));
	ft_bzero(&m, sizeof(t_memory));
	ft_parse_options(argc, argv, &p, &m);
	return 0;
}
