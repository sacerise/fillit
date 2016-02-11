#include "fillit.h"

bool	is_empty_tab(t_square const tab)
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

void	copy_sq(t_square dst, t_square const src)
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

t_coord	add_coord(t_coord const c1, t_coord const c2)
{
	t_coord	tmp;

	tmp.x = c1.x + c2.x;
	tmp.y = c1.y + c2.y;
	return (tmp);
}

void	print_tab(size_t s, char tab[s][s])
{
	size_t	i;

	i = 0;
	while (i < s)
	{
		write(1, tab[i], s);
		ft_putendl("");
		i++;
	}
}
