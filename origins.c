/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 13:22:05 by sacerise          #+#    #+#             */
/*   Updated: 2016/02/12 13:22:23 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		max(int *a, const int b)
{
	if (b > *a)
		*a = b;
}

static t_coord	coord_max(t_coord diezes_pos[NB_DIEZE_POS])
{
	t_coord	max_coord;
	size_t	i;

	max_coord = (t_coord){0, 0};
	i = 0;
	while (i < NB_DIEZE_POS)
	{
		max(&max_coord.x, diezes_pos[i].x);
		max(&max_coord.y, diezes_pos[i].y);
		i++;
	}
	return (max_coord);
}

static void		make_size(t_info *info)
{
	t_coord	max_coord;

	max_coord = coord_max(info->diezes_pos);
	info->size.x = max_coord.x + 1;
	(*info).size.y = max_coord.y + 1;
}

void			make_sizes(t_info list_tetri[NB_TETRIS])
{
	size_t i;

	i = 0;
	while (i < NB_TETRIS)
	{
		make_size(&list_tetri[i]);
		i++;
	}
}
