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
# include <libft.h>

# define BUF_SIZE 21
# define OK 1
# define ERROR 0
# define DIEZE true
# define POINT false
# define NB_LIST_TETRI_MAX 26

typedef	bool	t_square[4][4];

typedef	struct s_coord
{
	size_t	x;
	size_t	y;
}				t_coord;



# define INDEX(tab, coord) ((tab)[(coord).y][(coord).x])
# define NB_DIEZE_POS 4
# define NB_TETRIS 19

typedef enum 	e_tetri
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
}				t_tetri;

typedef struct 	s_info
{
	t_tetri id;
	t_coord diezes_pos[NB_DIEZE_POS];
	t_coord	size;
}				t_info;

extern t_info	list_tetri[NB_TETRIS];
int				read_fuck(int fd, char *b, size_t size);
void			make_sizes(t_info list_tetri[NB_TETRIS]);
int				parse_buf_2_sq(const char buf[BUF_SIZE], t_square tab);
int				parse(const char buf[BUF_SIZE], t_tetri *tetri);
void			algo_super(t_tetri list[NB_LIST_TETRI_MAX], size_t nb_tetri);
t_coord			add_coord(const t_coord c1, const t_coord c2);
void			copy_tab(size_t s, char dst[s][s], const char src[s][s]);
void			copy_sq(t_square dst, const t_square src);

#endif