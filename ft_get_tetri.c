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


t_coord	add_coord(const t_coord c1, const t_coord c2)
{
	t_coord tmp;

	tmp.x = c1.x + c2.x;
	tmp.y = c1.y + c2.y;
	return (tmp);
}

int		test_tetri(const t_square tab, const t_coord diezes_pos[NB_DIEZE_POS], t_coord origin)
{
	size_t		i;
	t_square	cpy;

	copy_tab(cpy, tab);
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
		while (origin.y <= info->max_origin.y)
		{
			origin.x = 0;
			while (origin.x <= info->max_origin.x)
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

int		parse(const char buf[21], t_tetri *tetri)
{
	t_square	tab;

	if (parse_buf_2_sq(buf, tab) == ERROR)
		return (ERROR);
	return (parse_sq(tab, tetri));
}
