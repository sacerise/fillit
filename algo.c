#include "fillit.h"

int		put_tetri(int s, char tab[s][s], t_coord diezes_pos[NB_DIEZE_POS], t_coord origin, char lettre)
{
	size_t		i;

	i = 0;
	while (i < NB_DIEZE_POS)
	{
		if (INDEX(tab, add_coord(diezes_pos[i], origin)) != '.')
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < NB_DIEZE_POS)
	{
		INDEX(tab, add_coord(diezes_pos[i], origin)) = lettre;
		i++;
	}
	return (OK);
}

int		try_again(int s, char tab[s][s], t_info *info, t_coord *origin, char lettre)
{
	while (origin->y <= s - info->size.y)
	{
		while (origin->x <= s - info->size.x)
		{
			if (put_tetri(s, tab, info->diezes_pos, *origin, lettre) == OK)
			{
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

int		algo(int s, char tab[s][s], size_t nb_tetri, t_tetri *list, char lettre)
{
	t_coord		origin;
	char		cpy[s][s];

	if (nb_tetri == 0)
		return (OK);
	copy_tab(s, cpy, tab);
	origin.x = 0;
	origin.y = 0;
	while (try_again(s, cpy, &g_list_tetri[*list], &origin, lettre) == OK)
	{
		if (algo(s, cpy, nb_tetri - 1, list + 1, lettre + 1) == OK)
		{
			copy_tab(s, tab, cpy);
			return (OK);
		}
		else
			copy_tab(s, cpy, tab);
	}
	return (ERROR);
}

int		algo_pas_super(t_tetri list[NB_LIST_TETRI_MAX], size_t nb_tetri, int s)
{
	char tab[s][s];

	ft_memset(tab, '.', sizeof(tab));
	if (algo(s, tab, nb_tetri, list, 'A') == ERROR)
		return (ERROR);
	print_tab(s, tab);
	return (OK);
}

void	algo_super(t_tetri list[NB_LIST_TETRI_MAX], size_t nb_tetri)
{
	int s;

	s = 2;
	while (algo_pas_super(list, nb_tetri, s) == ERROR)
		s++;
}
