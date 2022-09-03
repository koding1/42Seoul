/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujang <hyujang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:10:30 by hyujang           #+#    #+#             */
/*   Updated: 2022/06/26 20:25:05 by hyujang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	game_init(t_game *g, char *map_name)
{
	g->cnts.char_cnt = 0;
	g->cnts.item_cnt = 0;
	g->cnts.exit_cnt = 0;
	g->cnts.move_cnt = 0;
	g->cnts.sprite_cnt = 0;
	read_map_file(g, map_name);
	g->mp = mlx_init();
	g->wp = mlx_new_window(g->mp, 32 * g->map.w, 32 * g->map.h, "so_long");
	image_set(g);
	return (1);
}
