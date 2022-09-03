/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:49:49 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 21:10:55 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_game *game_info)
{
	if (keycode == KEY_ESC)
		exit_game(game_info);
	if (keycode == KEY_W)
		move_cat(game_info, 0, -1);
	if (keycode == KEY_A)
		move_cat(game_info, -1, 0);
	if (keycode == KEY_S)
		move_cat(game_info, 0, 1);
	if (keycode == KEY_D)
		move_cat(game_info, 1, 0);
	map_draw(*game_info);
	draw_cat_normal(*game_info, \
	game_info->char_po.x * 32, game_info->char_po.y * 32);
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mp, game->wp);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_game	game_info;

	game_init(&game_info, argv[1]);
	mlx_hook(game_info.wp, KEY_PRESS, 0, &key_press, &game_info);
	mlx_hook(game_info.wp, GAME_WINDOW_EXIT, 0, &exit_game, &game_info);
	map_draw(game_info);
	mlx_loop_hook(game_info.mp, &draw_cat_sprite, &game_info);
	mlx_loop(game_info.mp);
	return (0);
}
