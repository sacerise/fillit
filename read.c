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

int		parse_buf_2_sq(const char buf[21], t_square tab)
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
		if (ret <= 0)
			return (ret);
		count += ret;
	}
	return(1);
}



