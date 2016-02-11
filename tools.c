#include "fillit.h"

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

void	copy_sq(t_square dst, const t_square src)
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

void	copy_tab(size_t s, char dst[s][s], const char src[s][s])
{
	ft_memcpy(dst, src, s * s);
}

t_coord	add_coord(const t_coord c1, const t_coord c2)
{
	t_coord tmp;

	tmp.x = c1.x + c2.x;
	tmp.y = c1.y + c2.y;
	return (tmp);
}

void	print_tab(size_t s, char tab[s][s])
{
	size_t i;

	i = 0;
	while (i < s)
	{
		write(1, tab[i], s);
		ft_putendl("");
		i++;
	}
}
