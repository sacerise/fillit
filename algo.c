#include "fillit.h"

static int	try_again(STAB tab[s][s], t_info *info,
					t_coord *origin, char lettre)
{
	while (origin->y <= s - info->size.y)
	{
		while (origin->x <= s - info->size.x)
		{
			if (INDEX(tab, ADD_COORD(info->diezes_pos[0], *origin)) == '.' &&
				INDEX(tab, ADD_COORD(info->diezes_pos[1], *origin)) == '.' &&
				INDEX(tab, ADD_COORD(info->diezes_pos[2], *origin)) == '.' &&
				INDEX(tab, ADD_COORD(info->diezes_pos[3], *origin)) == '.')
			{
				INDEX(tab, ADD_COORD(info->diezes_pos[0], *origin)) = lettre;
				INDEX(tab, ADD_COORD(info->diezes_pos[1], *origin)) = lettre;
				INDEX(tab, ADD_COORD(info->diezes_pos[2], *origin)) = lettre;
				INDEX(tab, ADD_COORD(info->diezes_pos[3], *origin)) = lettre;
				origin->x++;
				return (OK);
			}
			origin->x++;
		}
		origin->x = 0;
		origin->y++;
	}
	return (ERROR);
}

static int	algo(STAB tab[s][s], size_t nb_tetri, t_tetri *list, char lettre)
{
	t_coord		origin;
	char		cpy[s][s];

	if (nb_tetri == 0)
		return (OK);
	ft_memcpy(cpy, tab, s * s);
	origin.x = 0;
	origin.y = 0;
	while (try_again(s, cpy, &g_list_tetri[*list], &origin, lettre) == OK)
	{
		if (algo(s, cpy, nb_tetri - 1, list + 1, lettre + 1) == OK)
		{
			ft_memcpy(tab, cpy, s * s);
			return (OK);
		}
		else
			ft_memcpy(cpy, tab, s * s);
	}
	return (ERROR);
}

static int	algo_pas_super(t_tetri list[NB_LIST_TETRI_MAX],
						size_t nb_tetri, int s)
{
	char tab[s][s];

	ft_memset(tab, '.', sizeof(tab));
	if (algo(s, tab, nb_tetri, list, 'A') == ERROR)
		return (ERROR);
	print_tab(s, tab);
	return (OK);
}

void		algo_super(t_tetri list[NB_LIST_TETRI_MAX], size_t nb_tetri)
{
	int s;

	s = 2;
	while (algo_pas_super(list, nb_tetri, s) == ERROR)
		s++;
}
