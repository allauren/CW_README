/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:04:36 by allauren          #+#    #+#             */
/*   Updated: 2018/02/10 18:36:25 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../includes/op.h"
# include "../includes/display.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void    print_memory(const void *addr, size_t size);

void	ft_print_map(unsigned char *map)
{
	int i;
	int	line;

	i = -1;
	line = 21;
	while(++i < MEM_SIZE)
	{
		write(1, &(HEX[map[i] / 16]), 1);
		write(1, &(HEX[map[i] % 16]), 1);
		write(1, " ", 1);
		if(i && !(i % 65))
		write(1, "\n", 1);
	}
	ft_printf("\n#%d#\n", i);
}

int main(int argc, char *argv[])
{
	char *line = NULL;
	int fd = open(argv[1], O_RDONLY);
	int ret;
	int i;
	unsigned char buf[BUFF_SIZE + 1];
	int test;
	unsigned char	map[MEM_SIZE];

	ft_memset(map, 0, MEM_SIZE);
	ft_print_map(map);
	if (argc == 1)
		ft_printf("nique toi les arguments\n");
	if((ret = read(fd, buf, (CHAMP_MAX_SIZE * 4) + 1)) > 0)
	{
		if (ret > (CHAMP_MAX_SIZE * 4))
			ft_perror("champ too long\n");
		ft_printf("#%d#\n", ret);
		test = 548;
//		print_memory(buf + test , (ret - (test * 4)));
	}
	return 0;
}
