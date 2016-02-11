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

int		test_tetri(const t_square tab, const t_coord diezes_pos[NB_DIEZE_POS], t_coord origin)
{
	size_t		i;
	t_square	cpy;

	copy_sq(cpy, tab);
	i = 0;
	while (i < NB_DIEZE_POS)
	{
		if (INDEX(cpy, add_coord(origin, diezes_pos[i])) == DIEZE)
		{
			INDEX(cpy, add_coord(origin, diezes_pos[i])) = POINT;
		}
		else
			return (ERROR);
		i++;
	}
	if (is_empty_tab(cpy))
		return (OK);
	else
		return (ERROR);
}

int		test_origins(const t_square tab, const t_info *info)
{
		t_coord	origin;

		origin.y = 0;
		while (origin.y <= 4 - info->size.y)
		{
			origin.x = 0;
			while (origin.x <= 4 - info->size.x)
			{
				if (test_tetri(tab, info->diezes_pos, origin) == OK)
					return (OK);
				origin.x++;
			}
			origin.y++;
		}
		return (ERROR);
}

int		parse_sq(const t_square tab, t_tetri *tetri_p)
{
	size_t	i;

	i = 0;
	while (i < NB_TETRIS)
	{
		if (test_origins(tab, &list_tetri[i]) == OK)
		{
			*tetri_p = list_tetri[i].id;
			return (OK);
		}
		i++;
	}

	return (ERROR);
}	

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

int		parse(const char buf[BUF_SIZE], t_tetri *tetri)
{
	t_square	tab;

	if (parse_buf_2_sq(buf, tab) == ERROR)
		return (ERROR);
	return (parse_sq(tab, tetri));
}
