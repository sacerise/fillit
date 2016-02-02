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

int 	read_tetri(int fd, t_tetri *tetri)
{
	char	buf[BUF_SIZE];
	int		ret;

	ret = read_fuck(fd, buf, BUF_SIZE);
	if (ret != 1)
		return (ret);
	if (parse(buf, tetri) == ERROR)
		return (-1);
	return (OK);
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
	make_max_origins(list_tetri);
	nb_tetri = 0;
	while (nb_tetri < NB_LIST_TETRI_MAX && (ret = read_tetri(fd, &tetri)) == 1)
	{
		list[nb_tetri] = tetri;
		nb_tetri++;
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

