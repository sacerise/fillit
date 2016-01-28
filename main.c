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

#include <fillit.h>
#include <stdio.h>

int		main(int ac, char **av)
{

	int 		fd;
	char 		buf[BUF_SIZE];
	t_tetri		tetri;

	fd = 0;
	if (ac != 2)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return(0);
	make_max_origins(list_tetri);
	while (read_fuck(fd, buf, BUF_SIZE) == 1)
	{
		if (parse(buf, &tetri) == ERROR)
			ft_putendl("ERROR");
		else
			printf("OK: %d\n", tetri);
	}
	close(fd);
	return (0);
}

