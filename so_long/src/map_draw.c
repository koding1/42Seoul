/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:10:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 20:25:46 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_grass(t_game g, int i, int j)
{
	mlx_put_image_to_window(g.mp, g.wp, g.grass.img, j * 32, i * 32);
}

static void	draw_wall(t_game g, int i, int j)
{
	mlx_put_image_to_window(g.mp, g.wp, g.wall.img, j * 32, i * 32);
}

static void	draw_fish(t_game g, int i, int j)
{
	if (g.fish.visibility == 1)
		mlx_put_image_to_window(g.mp, g.wp, g.fish.img, j * 32, i * 32);
}

static void	draw_exit(t_game g, int i, int j)
{
	if (g.exit_x.visibility == 1)
		mlx_put_image_to_window(g.mp, g.wp, g.exit_x.img, j * 32, i * 32);
	else
		mlx_put_image_to_window(g.mp, g.wp, g.exit_o.img, j * 32, i * 32);
}

int	map_draw(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game.map.h)
	{
		j = 0;
		while (j < game.map.w)
		{
			draw_grass(game, i, j);
			if (game.map.data[i][j] == 1)
				draw_wall(game, i, j);
			else if (game.map.data[i][j] == C_CODE)
				draw_fish(game, i, j);
			else if (game.map.data[i][j] == E_CODE)
				draw_exit(game, i, j);
			++j;
		}
		++i;
	}
	move_cnt_draw(game);
	return (0);
}
