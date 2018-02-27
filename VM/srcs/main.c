/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:04:36 by allauren          #+#    #+#             */
/*   Updated: 2018/02/27 16:49:56 by allauren         ###   ########.fr       */
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
	t_memory	m;

	if (argc == 1)
		corewar_usage();
	ft_bzero(&p, sizeof(t_param));
	ft_bzero(&m, sizeof(t_memory));
	ft_parse_options(argc, argv, &p, &m);
	print_memory(m.memory , MEM_SIZE);
	ft_printf("%d %d %d %d", p.nchamp[0].num_player, p.nchamp[1].num_player, p.nchamp[2].num_player, p.nchamp[3].num_player);

	return 0;
}
