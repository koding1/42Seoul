/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cnt_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:10:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 20:26:04 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_number_image(t_game game, int depth, int move_cnt)
{
	int	x;
	int	y;

	x = (32 * game.map.w) - (depth * 20);
	y = (32 * game.map.h) - (20);
	mlx_put_image_to_window(game.mp, game.wp, \
	game.num[move_cnt % 10].img, x, y);
	if (move_cnt / 10 > 0)
		put_number_image(game, depth + 1, move_cnt / 10);
}

void	move_cnt_draw(t_game game)
{
	put_number_image(game, 1, game.cnts.move_cnt);
}
