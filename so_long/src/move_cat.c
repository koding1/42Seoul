/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:10:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 20:26:00 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_to_item(t_game *game, int mx, int my)
{
	game->map.data[my][mx] = 0;
	game->cnts.item_cnt--;
	if (game->cnts.item_cnt == 0)
	{
		game->exit_o.visibility = 1;
		game->exit_x.visibility = 0;
	}
	game->char_po.x = mx;
	game->char_po.y = my;
}

static void	move_to_end_point(t_game *game)
{
	exit_game(game);
}

static void	move_to_zero(t_game *game, int mx, int my)
{
	game->char_po.x = mx;
	game->char_po.y = my;
}

void	move_cat(t_game *game, int dx, int dy)
{
	int	mx;
	int	my;

	mx = game->char_po.x + dx;
	my = game->char_po.y + dy;
	if (game->map.data[my][mx] != 1 &&
		!(game->map.data[my][mx] == E_CODE && game->cnts.item_cnt != 0))
		move_cat_draw(game, dx, dy);
	if (game->map.data[my][mx] == C_CODE)
		move_to_item(game, mx, my);
	else if (game->map.data[my][mx] == E_CODE && game->cnts.item_cnt == 0)
		move_to_end_point(game);
	else if (game->map.data[my][mx] == 0 || game->map.data[my][mx] == P_CODE)
		move_to_zero(game, mx, my);
}
