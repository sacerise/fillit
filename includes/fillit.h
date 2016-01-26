/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 13:43:41 by sacerise          #+#    #+#             */
/*   Updated: 2015/12/28 16:13:54 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include "libft.h"

# define BUF_SIZE 21
# define OK 1
# define ERROR 0
# define DIEZE true
# define POINT false

typedef	bool	t_square[4][4];

typedef	struct s_coord
{
	size_t	x;
	size_t	y;
}				t_coord;

# define INDEX(tab, coord) ((tab)[(coord).y][(coord).x])

enum 	e_list
{
	TETRI_1,
	TETRI_2,
	TETRI_3,
	TETRI_4,
	TETRI_5,
	TETRI_6,
	TETRI_7,
	TETRI_8,
	TETRI_9,
	TETRI_10,
	TETRI_11,
	TETRI_12,
	TETRI_13,
	TETRI_14,
	TETRI_15,
	TETRI_16,
	TETRI_17,
	TETRI_18,
	TETRI_19,
};

char	*ft_read(char *file);
int		ft_parse_sq(const char buf[21], bool tab[4][4]);
int		ft_parse_tetri_1(bool tab[4][4]);

#endif