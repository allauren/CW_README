/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:04:36 by allauren          #+#    #+#             */
/*   Updated: 2018/02/08 18:57:15 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../includes/op.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#define BUFF_SIZE 100000
void    print_memory(const void *addr, size_t size);

int main(int argc, char *argv[])
{
	char *line = NULL;
	if (argc == 1)
		ft_printf("nique");
	int fd = open(argv[1], O_RDONLY);
	int ret;
	int i;
	int buf[BUFF_SIZE + 1];
	if((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_printf("#%d#\n", ret);
		int test;
		test = 548;
		print_memory(buf + test , (ret - (test * 4)));
	}
	return 0;
}
