 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri.c                                     :+:      :+:  :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:16:53 by sacerise          #+#    #+#             */
/*   Updated: 2016/01/04 15:15:48 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_parse_sq(const char buf[21], bool tab[4][4])
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

void	copy_tab(t_square dst, const t_square src)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < 4)
	{
		coord.x = 0;
		while (coord.x < 4)
		{
			INDEX(dst, coord) = INDEX(src, coord);
			coord.x++;
		}
		coord.y++;
	}
}

bool	is_empty_tab(const t_square tab)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < 4)
	{
		coord.x = 0;
		while (coord.x < 4)
		{
			if (INDEX(tab, coord) == DIEZE)
				return (false);
			coord.x++;
		}
		coord.y++;
	}
	return (true);
}

const t_coord tetri_19[4] = {{0,0}, {0,1}, {1,1}, {1,2}};

t_coord	add_coord(const t_coord c1, const t_coord c2)
{
	t_coord tmp;

	tmp.x = c1.x + c2.x;
	tmp.y = c1.y + c2.y;
	return (tmp);
}

int		test_tetri(const t_square tab, const t_coord diezes_pos[4], t_coord origin)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		if (INDEX(tab, add_coord(origin, diezes_pos[i])) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int		test_tetri_only(const t_square tab, const t_coord diezes_pos[4], t_coord origin)
{
	t_square	cpy;
	size_t		i;

	if (test_tetri(tab, diezes_pos,origin) == ERROR)
		return (ERROR);
	copy_tab(cpy, tab);
	i = 0;
	while (i < 4)
		INDEX(cpy, add_coord(origin, diezes_pos[i])) = POINT;
	if (is_empty_tab(cpy))
		return (OK);
	else
		return (ERROR);
}