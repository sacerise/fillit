#include <fillit.h>
#include <stdio.h>

static void		max(size_t *a, const size_t b)
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

static void		make_max_origin(t_info *info)
{
	t_coord	max_coord;

	max_coord = coord_max(info->diezes_pos);
	info->max_origin.x = 3 - max_coord.x;
	(*info).max_origin.y = 3 - max_coord.y;
}

void			make_max_origins(t_info list_tetri[NB_TETRIS])
{
	size_t i;

	i = 0;
	while (i < NB_TETRIS)
	{
		make_max_origin(&list_tetri[i]);
		i++;
	}
}
