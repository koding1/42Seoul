/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:46:28 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 20:28:46 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sprite_imgs_choice(t_game *game, int counter)
{
	draw_grass(*game, game->char_po.y, game->char_po.x);
	if (counter % 4 == 0)
		mlx_put_image_to_window(game->mp, game->wp, game->cats[0].img, \
		game->char_po.x * 32, game->char_po.y * 32);
	else if (counter % 4 == 1)
		mlx_put_image_to_window(game->mp, game->wp, game->cats[1].img, \
		game->char_po.x * 32, game->char_po.y * 32);
	else if (counter % 4 == 2)
		mlx_put_image_to_window(game->mp, game->wp, game->cats[2].img, \
		game->char_po.x * 32, game->char_po.y * 32);
	else
		mlx_put_image_to_window(game->mp, game->wp, game->cats[3].img, \
		game->char_po.x * 32, game->char_po.y * 32);
}

int	draw_cat_sprite(t_game *game)
{
	if (game->cnts.sprite_cnt % 2000 == 0)
		sprite_imgs_choice(game, game->cnts.sprite_cnt / 2000);
	game->cnts.sprite_cnt++;
	return (0);
}

void	draw_cat_normal(t_game g, int i, int j)
{
	mlx_put_image_to_window(g.mp, g.wp, g.cats[0].img, i, j);
	mlx_do_sync(g.mp);
}

void	move_cat_draw(t_game *game, int dx, int dy)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		map_draw(*game);
		draw_cat_normal(*game, \
		(game->char_po.x * 32) + ((dx ^ 0) * (i / 1)), \
		(game->char_po.y * 32) + ((dy ^ 0) * (i / 1)));
		i += 5;
	}
	game->cnts.move_cnt++;
	printf("Move Count : %d\n", game->cnts.move_cnt);
}
