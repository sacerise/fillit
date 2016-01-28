/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tetris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:12:42 by sacerise          #+#    #+#             */
/*   Updated: 2016/01/27 18:12:46 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

t_info	list_tetri[NB_TETRIS] = {
	{
		.id = TETRI_1,
		.diezes_pos = {{0,0}, {1,0}, {2,0}, {3,0}}
	},
	{
		.id = TETRI_2,
		.diezes_pos = {{0,0}, {0,1}, {0,2}, {0,3}}
	},
	{
		.id = TETRI_3,
		.diezes_pos = {{0,0}, {1,0}, {0,1}, {1,1}}
	},
	{
		.id = TETRI_4,
		.diezes_pos = {{0,0}, {1,0}, {0,1}, {0,2}}
	},
	{
		.id = TETRI_5,
		.diezes_pos = {{0,0}, {1,0}, {2,0}, {2,1}}
	},
	{
		.id = TETRI_6,
		.diezes_pos = {{1,0}, {1,1}, {1,2}, {0,2}}
	},
	{
		.id = TETRI_7,
		.diezes_pos = {{0,0}, {0,1}, {1,1}, {1,2}}
	},
	{
		.id = TETRI_8,
		.diezes_pos = {{0,0}, {1,0}, {1,1}, {1,2}}
	},
	{
		.id = TETRI_9,
		.diezes_pos = {{0,1}, {1,1}, {2,1}, {2,0}}
	},
	{
		.id = TETRI_10,
		.diezes_pos = {{0,0}, {0,1}, {0,2}, {1,2}}
	},
	{
		.id = TETRI_11,
		.diezes_pos = {{0,0}, {1,0}, {2,0}, {0,1}}
	},
	{
		.id = TETRI_12,
		.diezes_pos = {{0,0}, {1,0}, {2,0}, {1,1}}
	},
	{
		.id = TETRI_13,
		.diezes_pos = {{0,0}, {0,1}, {0,2}, {1,1}}
	},
	{
		.id = TETRI_14,
		.diezes_pos = {{1,0}, {0,1}, {1,1}, {1,2}}
	},
	{
		.id = TETRI_15,
		.diezes_pos = {{0,1}, {1,0}, {1,1}, {2,1}}
	},
	{
		.id = TETRI_16,
		.diezes_pos = {{0,0}, {1,0}, {1,1}, {2,1}}
	},
	{
		.id = TETRI_17,
		.diezes_pos = {{1,0}, {1,1}, {0,1}, {0,2}}
	},
	{
		.id = TETRI_18,
		.diezes_pos = {{0,1}, {1,1}, {1,0}, {2,0}}
	},
	{
		.id = TETRI_19,
		.diezes_pos = {{0,0}, {0,1}, {1,1}, {1,2}}
	}
};