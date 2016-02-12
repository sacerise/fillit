/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:28:52 by sacerise          #+#    #+#             */
/*   Updated: 2016/02/12 13:29:03 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	test_tetri(t_square const tab,
						t_coord const diezes_pos[NB_DIEZE_POS], t_coord origin)
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

static int	test_origins(t_square const tab, t_info const *info)
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

static int	parse_sq(t_square const tab, t_tetri *tetri_p)
{
	size_t	i;

	i = 0;
	while (i < NB_TETRIS)
	{
		if (test_origins(tab, &g_list_tetri[i]) == OK)
		{
			*tetri_p = g_list_tetri[i].id;
			return (OK);
		}
		i++;
	}
	return (ERROR);
}

static int	parse_buf_2_sq(char const buf[BUF_SIZE], t_square tab)
{
	size_t	i;
	t_coord	coord;

	i = 0;
	coord.y = 0;
	while (coord.y < 4)
	{
		coord.x = 0;
		while (coord.x < 4)
		{
			if (buf[i] == '#')
				tab[coord.y][coord.x] = DIEZE;
			else if (buf[i] == '.')
				tab[coord.y][coord.x] = POINT;
			else
				return (ERROR);
			coord.x++;
			i++;
		}
		if (buf[i] != '\n')
			return (ERROR);
		coord.y++;
		i++;
	}
	return (OK);
}

int			parse(char const buf[BUF_SIZE], t_tetri *tetri)
{
	t_square	tab;

	if (parse_buf_2_sq(buf, tab) == ERROR)
		return (ERROR);
	return (parse_sq(tab, tetri));
}
