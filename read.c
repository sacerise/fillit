/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:45:23 by sacerise          #+#    #+#             */
/*   Updated: 2015/12/28 17:25:04 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		parse_buf_2_sq(const char buf[BUF_SIZE], t_square tab)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	y = 0;

	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if(buf[i] == '#')
				tab[y][x] = DIEZE;
			else if (buf[i] == '.')
				tab[y][x] = POINT;
			else
				return (ERROR);
			x++;
			i++;
		}
		if (buf[i] != '\n')
			return (ERROR);
		y++;
		i++;
	}
	return (OK);
}

int		read_fuck(int fd, char *b, size_t size)
{
	int		ret;
	size_t	count;

	count = 0;
	while (count < size)
	{
		ret = read(fd, &b[count], size - count);
		if (ret == -1)
			return (-1);
		else if (ret == 0)
		{
			if (count != 0)
				return (-1);
			else
				return (0);
		}
		count += ret;
	}
	return(1);
}

