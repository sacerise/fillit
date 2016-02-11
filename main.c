/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 17:12:39 by sacerise          #+#    #+#             */
/*   Updated: 2016/01/26 17:12:44 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static int	read_fuck(int fd, char *b, size_t size)
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
	return (1);
}

static int	read_return(int fd)
{
	int		ret;
	char	c;

	ret = read(fd, &c, 1);
	if (ret != 1)
		return (ret);
	if (c == '\n')
		return (1);
	else
		return (-1);
}

static int	read_tetris(int fd,
						t_tetri list[NB_LIST_TETRI_MAX], size_t *nb_tetri)
{
	int		ret;
	char	buf[BUF_SIZE];
	t_tetri	tetri;

	*nb_tetri = 0;
	while (*nb_tetri < NB_LIST_TETRI_MAX)
	{
		if (read_fuck(fd, buf, BUF_SIZE) != 1)
			return (-1);
		if (parse(buf, &tetri) == ERROR)
			return (-1);
		list[*nb_tetri] = tetri;
		(*nb_tetri)++;
		if ((ret = read_return(fd)) != 1)
			return (ret);
	}
	return (-1);
}

int			main(int ac, char **av)
{
	int			fd;
	t_tetri		list[NB_LIST_TETRI_MAX];
	size_t		nb_tetri;
	int			ret;

	fd = 0;
	if (ac != 2)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	make_sizes(g_list_tetri);
	ret = read_tetris(fd, list, &nb_tetri);
	close(fd);
	if (ret == 0)
	{
		algo_super(list, nb_tetri);
		return (0);
	}
	else
	{
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
}
