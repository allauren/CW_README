/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:04:36 by allauren          #+#    #+#             */
/*   Updated: 2018/02/10 23:58:32 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "op.h"
# include "display.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define BUFF_SIZE 20000

void    print_memory(const void *addr, size_t size);

void	ft_print_map(unsigned char *map, char *mapp, int start, int size)
{
	int i;
	int	j;

	j = 0;
	i = 0 ;
	while(++i < size + 1)
	{
		mapp[start++] = HEX[map[i - 1] / 16];
		mapp[start++] = HEX[map[i - 1] % 16];
		mapp[start++] = ' ';
		if(!(i % 64) && i >= 64)
		mapp[start++] = '\n';
	}
}

int main(int argc, char *argv[])
{
	char *line = NULL;
	int fd = open(argv[1], O_RDONLY);
	int ret;
	int i;
	int buf[BUFF_SIZE];
	int test;
	unsigned char	map[MEM_SIZE];
	char	mapp[MEM_SIZE * 4];

	ft_memset(map, 0, MEM_SIZE);
	ft_bzero(mapp, MEM_SIZE * 4);
	ft_print_map(map, mapp, 0, MEM_SIZE);
	if (argc == 1)
		ft_printf("nique toi les arguments\n");
	if(((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		if (ret > (CHAMP_MAX_SIZE * 4))
			ft_perror("champ too long\n");
		ft_printf("je suis ret #%d#\n", ret);
		test = 548;
	print_memory(buf + test , (ret - test * 4));
	ft_print_map(buf + test, mapp, 0, (ret - test * 4));
	ft_printf("\n\n\n\nDebut de la map\n%s\n",mapp);
	}
	return 0;
}
