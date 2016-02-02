#include "fillit.h"

void			algo_super(t_tetri list[NB_LIST_TETRI_MAX], size_t nb_tetri)
{
	while (nb_tetri)
	{
		nb_tetri--;
		ft_putnbr(*list);
		ft_putendl("");
		list++;
	}
}