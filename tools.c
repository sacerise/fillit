#include "fillit.h"

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

t_coord	add_coord(const t_coord c1, const t_coord c2)
{
	t_coord tmp;

	tmp.x = c1.x + c2.x;
	tmp.y = c1.y + c2.y;
	return (tmp);
}
