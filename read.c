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

int		ft_read_fuck(int fd, char *b, size_t size)
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

	int		main(int ac, char **av)
{

	int 	fd;
	char 	buf[BUF_SIZE];
	bool	tab[4][4];

	fd = 0;
	if (ac != 2)
		return (1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return(0);
	while (ft_read_fuck(fd, buf, BUF_SIZE) == 1)
	{
		if (ft_parse_sq(buf, tab) == ERROR)
			ft_putendl("ERROR");
		else
			write(1, buf, BUF_SIZE);		
	}
	close(fd);
	return (0);
}

