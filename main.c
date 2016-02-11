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

int		read_return(int fd)
{
	int ret;
	char c;

	ret = read(fd, &c, 1);
	if (ret != 1)
		return (ret);
	if (c == '\n')
		return (1);
	else
		return (-1);
}

int 	read_tetri(int fd, t_tetri *tetri)
{
	char	buf[BUF_SIZE];

	if (read_fuck(fd, buf, BUF_SIZE) != 1)
		return (-1);
	if (parse(buf, tetri) == ERROR)
		return (-1);
	return (read_return(fd));
}

int		main(int ac, char **av)
{

	int 		fd;
	t_tetri		tetri;
	t_tetri		list[NB_LIST_TETRI_MAX];
	size_t		nb_tetri;
	int			ret;

	fd = 0;
	if (ac != 2)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return(0);
	make_sizes(list_tetri);
	nb_tetri = 0;
	while (nb_tetri < NB_LIST_TETRI_MAX)
	{
		ret = read_tetri(fd, &tetri);
		if (ret == -1)
			break ;
		list[nb_tetri] = tetri;
		nb_tetri++;
		if (ret == 0)
			break ;
	}
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

